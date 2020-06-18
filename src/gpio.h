#ifndef __goio__h__
#define __goio__h__
#include <stdint.h>

// pi2,pi3
#ifdef BCM2708
    #define PERI_BASE 0x3F000000
// pi4
#else
    #define PERI_BASE 0xFE000000
#endif
// GPIO base address
#define GPIO_BASE (PERI_BASE + 0x200000)

typedef struct gpio gpio;
typedef enum
{
    out = 0,
    in = 1
}gpio_func;

typedef struct gpio 
{
    uint8_t gpio_pin; // pin name
    uint8_t gpio_func; // out or in
}gpio;


#endif