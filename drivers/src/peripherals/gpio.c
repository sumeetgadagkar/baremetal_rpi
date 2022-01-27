// GPIO peripheral driver

#include "peripherals/gpio.h"

GPIOStatusTypeDef gpio_set_fcn(unsigned int pin, unsigned int fcn)
{

    // check if requested pin is valid
    if (pin > 53)
    {
        // invalid pin requested
        return GPIO_INVALID_PIN;
    }

    // check if requested function is valid
    if (fcn > 7)
    {
        // invalid function requested
        return GPIO_INVALID_ALT;
    }

    unsigned int GPIOSELReg;

    if (pin <= 9)
    {
        // GPFSEL0 register
        GPIOSELReg = *GPFSEL0;
        // clear bit of GPFSEL0 associated with <pin>
        GPIOSELReg &= ~(7 << pin * 3);
        // set requested function
        GPIOSELReg |=  (fcn << pin * 3);
        *GPFSEL0 = GPIOSELReg;
    }
    else if (pin <= 19)
    {
        // GPFSEL1 register
        GPIOSELReg = *GPFSEL1;
        // clear bit of GPFSEL1 associated with <pin>
        GPIOSELReg &= ~(7 << (pin - 10) * 3);
        // set requested function
        GPIOSELReg |=  (fcn << (pin - 10) * 3);
        *GPFSEL1 = GPIOSELReg;
    }
    else if (pin <= 29)
    {
        // GPFSEL2 register
        GPIOSELReg = *GPFSEL2;
        // clear bit of GPFSEL2 associated with <pin>
        GPIOSELReg &= ~(7 << (pin - 20) * 3);
        // set requested function
        GPIOSELReg |=  (fcn << (pin - 20) * 3);
        *GPFSEL2 = GPIOSELReg;
    }
    else if (pin <= 39)
    {
        // GPFSEL3 register
        GPIOSELReg = *GPFSEL3;
        // clear bit of GPFSEL3 associated with <pin>
        GPIOSELReg &= ~(7 << (pin - 30) * 3);
        // set requested function
        GPIOSELReg |=  (fcn << (pin - 30) * 3);
        *GPFSEL3 = GPIOSELReg;
    }
    else if (pin <= 49)
    {
        // GPFSEL4 register
        GPIOSELReg = *GPFSEL4;
        // clear bit of GPFSEL4 associated with <pin>
        GPIOSELReg &= ~(7 << (pin - 40) * 3);
        // set requested function
        GPIOSELReg |=  (fcn << (pin - 40) * 3);
        *GPFSEL4 = GPIOSELReg;
    }
    else
    {
        // GPFSEL5 register
        GPIOSELReg = *GPFSEL5;
        // clear bit of GPFSEL5 associated with <pin>
        GPIOSELReg &= ~(7 << (pin - 50) * 3);
        // set requested function
        GPIOSELReg |=  (fcn << (pin - 50) * 3);
        *GPFSEL5 = GPIOSELReg;
    }

    return GPIO_OK;
}

GPIOStatusTypeDef gpio_get_fcn(unsigned int pin)
{
    // check if requested pin is valid
    if (pin > 53)
    {
        // invalid pin requested
        return GPIO_INVALID_PIN;
    }

    unsigned int GPIOSELReg;
    unsigned int GPIOFcn;

    if (pin <= 9)
    {
        // GPFSEL0 register
        GPIOSELReg = *GPFSEL0;
        // get the function setiing for the <pin>
        GPIOFcn = GPIOSELReg & (7 << pin * 3);
        GPIOFcn = (GPIOFcn >> pin * 3);
    }
    else if (pin <= 19)
    {
        // GPFSEL1 register
        GPIOSELReg = *GPFSEL1;
        // get the function setiing for the <pin>
        GPIOFcn = GPIOSELReg & (7 << (pin - 10) * 3);
        GPIOFcn = (GPIOFcn >> (pin - 10) * 3);
    }
    else if (pin <= 29)
    {
        // GPFSEL2 register
        GPIOSELReg = *GPFSEL2;
        // get the function setiing for the <pin>
        GPIOFcn = GPIOSELReg & (7 << (pin - 20) * 3);
        GPIOFcn = (GPIOFcn >> (pin - 20) * 3);
    }
    else if (pin <= 39)
    {
        // GPFSEL3 register
        GPIOSELReg = *GPFSEL3;
        // get the function setiing for the <pin>
        GPIOFcn = GPIOSELReg & (7 << (pin - 30) * 3);
        GPIOFcn = (GPIOFcn >> (pin - 30) * 3);
    }
    else if (pin <= 49)
    {
        // GPFSEL4 register
        GPIOSELReg = *GPFSEL4;
        // get the function setiing for the <pin>
        GPIOFcn = GPIOSELReg & (7 << (pin - 40) * 3);
        GPIOFcn = (GPIOFcn >> (pin - 40) * 3);
    }
    else
    {
        // GPFSEL5 register
        GPIOSELReg = *GPFSEL5;
        // get the function setiing for the <pin>
        GPIOFcn = GPIOSELReg & (7 << (pin - 50) * 3);
        GPIOFcn = (GPIOFcn >> (pin - 50) * 3);
    }

    // return the corresponding GPIO function
    switch (GPIOFcn)
    {
        case 0:
            return GPIO_INPUT;
        case 1:
            return GPIO_OUTPUT;
        case 2:
            return GPIO_ALT_5;
        case 3:
            return GPIO_ALT_4;
        case 4:
            return GPIO_ALT_0;
        case 5:
            return GPIO_ALT_1;
        case 6:
            return GPIO_ALT_2;
        case 7:
            return GPIO_ALT_3;
        default:
            return GPIO_INVALID_ALT;
    }
}

GPIOStatusTypeDef gpio_set_pin(unsigned int pin)
{
    // check if requested pin is valid
    if (pin > 53)
    {
        // invalid pin requested
        return GPIO_INVALID_PIN;
    }

    unsigned int GPIOSetReg;

    if (pin <= 31)
    {
        // GPSET0 register
        GPIOSetReg = *GPSET0;
        GPIOSetReg |= (1 << pin);
        *GPSET0 = GPIOSetReg;
    }
    else
    {
        // GPSET1 register
        GPIOSetReg = *GPSET1;
        GPIOSetReg |= (1 << (pin - 32));
        *GPSET0 = GPIOSetReg;
    }

    return GPIO_OK;
}

GPIOStatusTypeDef gpio_clear_pin(unsigned int pin)
{
    // check if requested pin is valid
    if (pin > 53)
    {
        // invalid pin requested
        return GPIO_INVALID_PIN;
    }

    unsigned int GPIOClrReg;

    if (pin <= 31)
    {
        // GPCLR0 register
        GPIOClrReg = *GPCLR0;
        GPIOClrReg |= (1 << pin);
        *GPCLR0 = GPIOClrReg;
    }
    else
    {
        // GPCLR1 register
        GPIOClrReg = *GPCLR1;
        GPIOClrReg |= (1 << (pin - 32));
        *GPCLR1 = GPIOClrReg;
    }

    return GPIO_OK;
}

GPIOStatusTypeDef gpio_get_pin_state(unsigned int pin,volatile unsigned int * result)
{
    // check if requested pin is valid
    if (pin > 53)
    {
        // invalid pin requested
        return GPIO_INVALID_PIN;
    }

    unsigned int GPIOLevReg;

    if (pin <= 32)
    {
        // GPLEV0 register
        GPIOLevReg = *GPLEV0;
        GPIOLevReg &= (1 << pin);
        *result = (GPIOLevReg >> pin);
    }
    else
    {
        // GPLEV1 register
        GPIOLevReg = *GPLEV1;
        GPIOLevReg &= (1 << (pin - 32));
        *result = (GPIOLevReg >> (pin - 32));
    }

    return GPIO_OK;
}
