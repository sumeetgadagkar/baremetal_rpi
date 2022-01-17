SECTIONS
{
    /* start of kernel address */
    . = 0x80000;
    /* text section contains section text.boot */
    .text : { *(.text.boot) }

   /DISCARD/ : { *(.comment) *(.gnu*) *(.note*) *(.eh_frame*) }
}