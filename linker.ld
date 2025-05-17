/* Linker script for STM32F031K6T6 (32KB Flash, 4KB SRAM) */

ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 32K
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 4K
}

SECTIONS
{
  /* Vector table and startup code */
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } > FLASH

  /* Program code and read-only data */
  .text :
  {
    *(.text)           /* .text sections (code) */
    *(.text*)          
    *(.rodata)         /* .rodata sections (constants) */
    *(.rodata*)
    KEEP(*(.init))
    KEEP(*(.fini))
  } > FLASH

  /* Data segment */
  .data : 
  {
    _sdata = .;
    *(.data)
    *(.data*)
    _edata = .;
  } > RAM AT > FLASH

  /* BSS segment */
  .bss (NOLOAD) :
  {
    _sbss = .;
    *(.bss)
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  /* Symbols for system initialization */
  _etext = LOADADDR(.data);
  _estack = ORIGIN(RAM) + LENGTH(RAM);
}
