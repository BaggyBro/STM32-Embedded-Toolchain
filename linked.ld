
/* Linker Script Example (linked.ld) */
ENTRY(Reset_Handler)

MEMORY {
    RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 64K
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);  /* Set stack top to the end of RAM */
