#include "common.h"
#include <stddef.h>



int main()
{

    volatile unsigned int * result = NULL;

    // set GPIO0 as output
    gpio_set_fcn(0, 1);

    // set GPIO0
    gpio_set_pin(0);

    // get state of GPIO0
    gpio_get_pin_state(0, result);

    // clear GPIO0
    gpio_clear_pin(0);

    // get state of GPIO0
    gpio_get_pin_state(0, result);
    
    while(1)
    {
        // infinite loop
    }

    return 0;
}