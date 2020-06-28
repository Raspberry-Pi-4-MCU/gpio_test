#define BCM2711
#include "gpio.h"
//
int mem_fd;
unsigned *gpio_map;
// I/O access
volatile unsigned *gpio;
//
void gpio_setup()
{
    // open memory
    if( (mem_fd = open("/dev/mem", O_RDWR|O_SYNC)) < 0)
    {
        printf("can't not open /dev/mem");
        exit(-1);
    }
    // mmap
    gpio_map = mmap(
        NULL,
        BLOCK_SIZE,
        PROT_READ|PROT_WRITE,
        MAP_SHARED,
        mem_fd,
        PERI_BASE
    );
    // close 
    close(mem_fd);
    //
    if (gpio_map == MAP_FAILED)
    {
        printf("mmap error");
        exit(-2);
    }
    gpio = (volatile unsigned *)gpio_map;
}

int main()
{
    gpio_setup();
    return 0;
}