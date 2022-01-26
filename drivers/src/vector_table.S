#include "vector_table.h"

// macro for adding an entry to the exveption vector table
.macro ventry label
    // 0x80 space required between entries
    .align 7
    b \label
.endm

// macro for storing x[0-30] on exception
.macro exception_entry
    // we need to store 31 8 byte registers on the stack
    // 31 * 8 = 248 bytes
    // but in AArch64 the sp needs to be 16 aligned
    // 248 is not 16 aligned
    // hence we decrease the sp by the next 16 aligned number i.e 256
    sub sp, sp, #256
    stp x0, x1, [sp, #16 * 0]
    stp x2, x3, [sp, #16 * 1]
    stp x4, x5, [sp, #16 * 2]
    stp x6, x7, [sp, #16 * 3]
    stp x8, x9, [sp, #16 * 4]
    stp x10, x11, [sp, #16 * 5]
    stp x12, x13, [sp, #16 * 6]
    stp x14, x15, [sp, #16 * 7]
    stp x16, x17, [sp, #16 * 8]
    stp x18, x19, [sp, #16 * 9]
    stp x20, x21, [sp, #16 * 10]
    stp x22, x23, [sp, #16 * 11]
    stp x24, x25, [sp, #16 * 12]
    stp x26, x27, [sp, #16 * 13]
    stp x28, x29, [sp, #16 * 14]
    str x30, [sp, #16 * 15]
.endm

// macro for reverting x[0-30] stored on the stack
// before returning from the stack
.macro exception exception_exit
    ldp x0, x1, [sp, #16 * 0]
    ldp x2, x3, [sp, #16 * 1]
    ldp x4, x5, [sp, #16 * 2]
    ldp x6, x7, [sp, #16 * 3]
    ldp x8, x9, [sp, #16 * 4]
    ldp x10, x11, [sp, #16 * 5]
    ldp x12, x13, [sp, #16 * 6]
    ldp x14, x15, [sp, #16 * 7]
    ldp x16, x17, [sp, #16 * 8]
    ldp x18, x19, [sp, #16 * 9]
    ldp x20, x21, [sp, #16 * 10]
    ldp x22, x23, [sp, #16 * 11]
    ldp x24, x25, [sp, #16 * 12]
    ldp x26, x27, [sp, #16 * 13]
    ldp x28, x29, [sp, #16 * 14]
    ldr x30, [sp, #16 * 15]
    add sp, sp, #256
    eret
.endm

// macro to handle invalid exceptions
.macro handle_invalid_entry type
    kernel_entry
    mov x0, #\type
    mrs x1, esr_el1
    mrs x2, elr_el1
    bl show_invalid_entry_message
    b err_hang
.endm

// exception vectors require 2048 alignment
.align 11
.global vectors
vectors:
    // current EL with SP0
    // these should not occur as we do not use SP0
    // and hence are invalid
    ventry sync_invalid_el1t
    ventry irq_invalid_el1t
    ventry fiq_invalid_el1t
    ventry serror_invalid_el1t

    // current EL with SPx
    // these are valid
    // we are interested in the IRQ and the FIQ exceptions
    ventry sync_invalid_el1h
    ventry irq_el1h
    ventry fiq_el1h
    ventry serror_invalid_el1h

    // lower EL using AArch64
    // since we always operate in EL1 there are invalid
    ventry sync_invalid_el0_64
    ventry irq_invalid_el0_64
    ventry fiq_invalid_el0_64
    ventry error_invalid_el0_64

    // lower EL using AArch32
    // since we always operate in EL1 there are invalid
    ventry sync_invalid_el0_32
    ventry irq_invalid_el0_32
    ventry fiq_invalid_el0_32
    ventry error_invalid_el0_32

sync_invalid_el1t:
