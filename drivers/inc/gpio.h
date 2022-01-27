// GPIO peripheral driver

#ifndef GPIO_H
#define GPIO_H

#include "raspi3.h"

// GPIO registers for BCM2837. All registers below are R/W 32 bit registers unless otherwise stated
#define GPFSEL0                 ((volatile unsigned int *)(MMIO_BASE + 0x00200000))
#define GPFSEL1                 ((volatile unsigned int *)(MMIO_BASE + 0x00200004))
#define GPFSEL2                 ((volatile unsigned int *)(MMIO_BASE + 0x00200008))
#define GPFSEL3                 ((volatile unsigned int *)(MMIO_BASE + 0x0020000C))
#define GPFSEL4                 ((volatile unsigned int *)(MMIO_BASE + 0x00200010))
#define GPFSEL5                 ((volatile unsigned int *)(MMIO_BASE + 0x00200014))
#define GPSET0                  ((volatile unsigned int *)(MMIO_BASE + 0x0020001C)) // write-only
#define GPSET1                  ((volatile unsigned int *)(MMIO_BASE + 0x00200020)) // write-only
#define GPCLR0                  ((volatile unsigned int *)(MMIO_BASE + 0x00200028)) // write-only
#define GPCLR1                  ((volatile unsigned int *)(MMIO_BASE + 0x0020002C)) // write-only
#define GPLEV0                  ((volatile unsigned int *)(MMIO_BASE + 0x00200034)) // read-only
#define GPLEV1                  ((volatile unsigned int *)(MMIO_BASE + 0x00200038)) // read-only
#define GPEDS0                  ((volatile unsigned int *)(MMIO_BASE + 0x00200040))
#define GPEDS1                  ((volatile unsigned int *)(MMIO_BASE + 0x00200044))
#define GPREN0                  ((volatile unsigned int *)(MMIO_BASE + 0x0020004C))
#define GPREN1                  ((volatile unsigned int *)(MMIO_BASE + 0x00200050))
#define GPFEN0                  ((volatile unsigned int *)(MMIO_BASE + 0x00200058))
#define GPFEN1                  ((volatile unsigned int *)(MMIO_BASE + 0x0020005C))
#define GPHEN0                  ((volatile unsigned int *)(MMIO_BASE + 0x00200064))
#define GPHEN1                  ((volatile unsigned int *)(MMIO_BASE + 0x00200068))
#define GPLEN0                  ((volatile unsigned int *)(MMIO_BASE + 0x00200070))
#define GPLEN1                  ((volatile unsigned int *)(MMIO_BASE + 0x00200074))
#define GPAREN0                 ((volatile unsigned int *)(MMIO_BASE + 0x0020007C))
#define GPAREN1                 ((volatile unsigned int *)(MMIO_BASE + 0x00200080))
#define GPAFEN0                 ((volatile unsigned int *)(MMIO_BASE + 0x00200088))
#define GPAFEN1                 ((volatile unsigned int *)(MMIO_BASE + 0x0020008C))
#define GPPUD                   ((volatile unsigned int *)(MMIO_BASE + 0x00200094))
#define GPPUDCLK0               ((volatile unsigned int *)(MMIO_BASE + 0x00200098))
#define GPPUDCLK1               ((volatile unsigned int *)(MMIO_BASE + 0x0020009C))


typedef enum
{
    GPIO_OK = 0,                // no errors
    GPIO_INVALID_PIN,           // value of pin was outside [0-53]
    GPIO_INVALID_ALT,           // value of requested alt function was beyond [0-7]
    GPIO_INPUT,
    GPIO_OUTPUT,
    GPIO_ALT_0,
    GPIO_ALT_1,
    GPIO_ALT_2,
    GPIO_ALT_3,
    GPIO_ALT_4,
    GPIO_ALT_5
} GPIOStatusTypeDef;

/* function : gpio_set_fcn
*    intput args : unsigned int pin > GPIO pin number [0-53]
*                  unsiged int fcn  > function [0-5]
*    output args : GPIOStatusTypeDef
*
* NOTE : Care should be taken not to assign invalid alternate functions
*        for GPIO pins. Not all GPIO pins have alternate functions
*/
GPIOStatusTypeDef gpio_set_fcn(unsigned int pin, unsigned int fcn);


/* function : gpio_get_fcn
*    intput args : unsigned int pin > GPIO pin number [0-53]
*    output args : GPIOStatusTypeDef
*/
GPIOStatusTypeDef gpio_get_fcn(unsigned int pin);


/* function : gpio_set_pin
*    intput args : unsigned int pin > GPIO pin number [0-53]
*    output args : GPIOStatusTypeDef
*/
GPIOStatusTypeDef gpio_set_pin(unsigned int pin);


/* function : gpio_clear_pin
*    intput args : unsigned int pin > GPIO pin number [0-53]
*    output args : GPIOStatusTypeDef
*/
GPIOStatusTypeDef gpio_clear_pin(unsigned int pin);


/* function : gpio_get_pin_state
*    intput args : unsigned int pin > GPIO pin number [0-53]
*                  unsigned int * result > state of <pin> will be written to
*                                          address pointed by this pointer
*    output args : GPIOStatusTypeDef
*/
GPIOStatusTypeDef gpio_get_pin_state(unsigned int pin, volatile unsigned int * result);


#endif // GPIO_H

