
MEMORY
{
  ram    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 128K
  flash    (rx)    : ORIGIN =0x08000000,   LENGTH = 512K
}

_eram = ORIGIN(ram) + LENGTH(ram);
_stack = _eram;
/*stack starts at the end of ram and grows downwards*/

SECTIONS
{
  .text :
  {
    . = ALIGN(4);
    KEEP(*(.ivt))
    *(.text)
    . = ALIGN(4);
    _extext = .;
  } > flash
}
