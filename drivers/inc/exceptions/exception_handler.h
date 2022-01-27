#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

// function to initialize the exception vector table
void init_vector_table(void);

// function to enable interrupts
void enable_interrupts(void);

// function to disable interrupts
void disable_interrupts(void);

// exception handler for IRQs
void irq_handler(void);

// exception handler for FIQs
void fiq_handler(void);

#endif