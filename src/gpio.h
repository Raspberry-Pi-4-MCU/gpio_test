#ifndef __gpio__h__
#define __gpio__h__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>
#define raspi4
#ifdef raspi4
    #include "raspi4.h"
#endif
// GPIO Level
#define HIGH 1
#define LOW 0
// GPIO func
#define OUTPUT 0
#define INPUT 1
volatile uint32_t* mmio_gpio;
// common
void initial();
// OOP
typedef struct gpio_structure gpio_structure;
typedef struct gpio_structure
{
    uint8_t gpio_num;
    uint8_t gpio_func;
}gpio_structure;

gpio_structure* new_gpio(uint8_t, uint8_t);
void write_gpio(gpio_structure*,uint8_t);
uint8_t read_gpio(gpio_structure*);
// arduino method
void pinMode(int,int);
void digitalWrite(int,int);
void digitalRead(int,int);

#endif