
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
GDB = arm-none-eabi-gdb
SIZE = arm-none-eabi-size

# Compiler flags
CFLAGS = -mcpu=cortex-m4 -mthumb -Wall -O2 -ffreestanding -nostdlib

# Linker script
LDSCRIPT = linked.ld

# Source files
SRCS_C = src/main.c src/uart.c src/rtos.c
SRCS_S = src/startup.s

# Object files
OBJS = $(SRCS_C:.c=.o) $(SRCS_S:.s=.o)

# Output
TARGET = firmware.elf

# Build the target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -T $(LDSCRIPT) -o $(TARGET) $(OBJS)
	$(OBJCOPY) -O binary $(TARGET) firmware.bin
	$(SIZE) $(TARGET)

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile Assembly files
%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

# Flash the firmware to STM32
flash: $(TARGET)
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program firmware.bin verify reset exit"

# Clean up
clean:
	rm -f $(OBJS) $(TARGET) firmware.bin

