#ifndef __raspi4__h__
#define __raspi4__h__
#include <assert.h>

#define PERI_BASE 0xFE000000
#define GPIO_BASE (PERI_BASE + 0x200000)

// offset (32 bits)
#define GPFSEL(x) (0x00 + (x) / 10)
#define GPSET(x) (0x07 + ((x) << 1))
#define GPCLR(x) (0x0A + ((x) << 1))
#define GPLEV(x) (0x0D + ((x) / 32))

#define IS_PIN(x) ((x)>=0 && (x)<=57)
#endif