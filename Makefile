
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
GDB = arm-none-eabi-gdb
SIZE = arm-none-eabi-size
PROGRAM=firmware.bin

CFLAGS = -mcpu=cortex-m4 -mthumb -Wall -O2 -ffreestanding -nostdlib
LDSCRIPT = linker.ld

SRCS_C = src/main.c src/uart.c src/rtos.c src/startup.c  
OBJS = $(SRCS_C:.c=.o)  
TARGET = firmware.elf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -g -O0 -T $(LDSCRIPT) -o $(TARGET) $(OBJS)
	$(OBJCOPY) -O binary $(TARGET) firmware.bin
	$(SIZE) $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

flash: 
	openocd -f openocd.cfg -c "program $(PROGRAM) verify reset exit"

stflash:
	st-flash --format binary write $(PROGRAM) 0x08000000  

debug:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg

clean:
	rm -f $(OBJS) $(TARGET) firmware.bin

