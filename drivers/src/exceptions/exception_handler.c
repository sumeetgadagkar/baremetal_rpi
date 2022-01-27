#include "exceptions/exception_handler.h"

// exception handler for IRQs
void irq_handler(void)
{
    // read pending IRQ bits and perform IRQ specific tasks and then clear the interrupt flag
}

void fiq_handler(void)
{
    // perform FIQ specific tast and clear the interrupt flag
}

void show_invalid_entry_message(int type, unsigned long esr, unsigned long address)
{
    // output the type, esr and the address
}
