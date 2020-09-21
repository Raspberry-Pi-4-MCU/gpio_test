#ifndef __raspi4__h__
#define __raspi4__h__

#define PERI_BASE 0x7E000000
#define GPIO_BASE (PERI_BASE + 0x200000)

// offset
#define GPFSEL(x) (0x00 + (1 << ((x) << 1)) )
#define GPSET(x) (0x1C + (1 << ((x) << 1)) )
#define GPCLR(x) (0x28 + (1 << ((x) << 1)) )
#define GPLEV(x) (0x34 + (1 << ((x) << 1)) )
#define GPEDS(x) (0x40 + (1 << ((x) << 1)) )
#define GPREN(x) (0x4C + (1 << ((x) << 1)) )
#define GPREN(x) (0x4C + (1 << ((x) << 1)) )
#define GPFEN(x) (0x58 + (1 << ((x) << 1)) )
#define GPHEN(x) (0x64 + (1 << ((x) << 1)) )
#define GPLEN(x) (0x70 + (1 << ((x) << 1)) )
#define GPAREN(x) (0x7C + (1 << ((x) << 1)) )
#define GPAFEN(x) (0x88 + (1 << ((x) << 1)) )
#define GPIO_PUP_PDN_CNTRL_REG(x) (0xE4 + (1 << ((x) << 1)) )

#endif