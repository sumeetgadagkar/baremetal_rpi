.section ".text.boot"

.global _start

_start:
    //stop all cores except core 0

    // read the first three bits of mpidr_el1 register
    mrs x1, mpidr_el1
    and x1, x1, #3

    // if cpu id is 0 jump to label '2'
    cbz x1, 2f

1:  wfe
    // infinite loop
    b 1b

2:
    // cpu id == 0

    // get the value of _start
    ldr x1, =_start
    // move stack pointer to _start
    mov sp, x1

    // get the value of __bss_start
    ldr x1, =__bss_start

    // get the value of __bss_size
    ldr w2, =__bss_size

    // if __bss_size is 0 branch to label '4' looking forward
3:  cbz w2, 4f

    //  store x1 + 8 into xzr
    str xzr, [x1], #8

    // decrement w2 (__bss_size) by 1
    sub w2, w2, #1

    // repeate '3' until w2 is 0
    cbnz w2, 3b

    // branch with link to 'main'
4:  bl main
    // for safety if main returns
    b 1b