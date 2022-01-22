.section ".text.boot"

.global _start

_start:
    //stop all cores except core 0

    // read the first 8 bits of 'mpidr_el1' register
    // the Cortex - A 53 has 4 cores, hence the possible 
    // values of the last 8 bits of the 'mpidr_el1'
    // register  are: 0x0, 0x1, 0x2 and 0x3
    mrs x1, mpidr_el1
    and x1, x1, #0xFF

    // if cpu id is 0 jump to label 'master'
    cbz x1, master

proc_hang:  wfe
    // infinite loop
    b proc_hang

master:
    // read the current exception level
    mrs x0, CurrentEL

    /*
    thinngs to do here :
    1. route all AArch64 exceptions to EL1
    2. set the AArch64 exception vectors for EL1
    3. set the EL to EL1
    */

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
    b proc_hang