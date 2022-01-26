#include "common.h"
#include "exception_handler.h"
#include <stddef.h>

#define PIN0 0  //Using pin0 to test out basic GPIO functions

int main()
{
    init_vector_table();
    enable_interrupts();

    volatile unsigned int * result = NULL;

    // set GPIO0 as output
    gpio_set_fcn(PIN0, GPIO_OUT);

    // set GPIO0
    gpio_set_pin(PIN0);

    // get state of GPIO0
    gpio_get_pin_state(PIN0, result);

    // clear GPIO0
    gpio_clear_pin(PIN0);

    // get state of GPIO0
    gpio_get_pin_state(PIN0, result);
    
    while(1)
    {
        // infinite loop
    }

    return 0;
}