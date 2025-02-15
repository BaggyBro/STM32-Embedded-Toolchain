
ENTRY(Reset_Handler)

MEMORY {
  flash(rx) : org = 0x0800000, len = 512k
  ram0 (wx) : org = 0x2000000, len = 112k
}
_estack = ORIGIN(ram0) + LENGTH(ram0);
