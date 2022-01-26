// function to initialize EL1 vector table
.global init_vector_table
init_vector_table:
    adr x0, vectors
    msr vbar_el1, x0
    ret

// function to enable interrupts (IRQ, FIQ and SError)
.global enable_interrupts
enable_interrupts:
    msr    daifclr, #7
    ret

// function to disable interrupts (IRQ, FIQ and SError)
.global disable_interrupts
disable_interrupts:
    msr    daifset, #7
    ret