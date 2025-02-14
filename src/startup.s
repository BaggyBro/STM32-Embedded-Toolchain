.syntax unified
.cpu cortex-m4
.thumb

.global Reset_Handler
.global _estack

.section .text
Reset_Handler:
    ldr sp, =_estack 
    bl main           
    b .            

.section .bss

