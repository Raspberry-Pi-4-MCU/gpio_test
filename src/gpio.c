#include "gpio.h"

void initial()
{
    // mmap
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    mmio_gpio = (uint32_t*)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO_BASE);
    close(fd);
}

gpio_structure* new_gpio(uint8_t gpio_num, uint8_t func)
{
    gpio_structure* new_gpio_device = (gpio_structure*)calloc(sizeof(gpio_structure),1);
    new_gpio_device->gpio_num = gpio_num;
    new_gpio_device->gpio_func = func;
    // set gpio func
    switch (func)
    {
        case OUTPUT:
            *(mmio_gpio + GPFSEL( (gpio_num / 9) )) |= (1 << (gpio_num % 9 * 3));
            break;
        case INPUT:
            *(mmio_gpio + GPFSEL( (gpio_num / 9) )) &= ~(1 << (gpio_num % 9 * 3));
            break;
        default:
            break;
    };
    return new_gpio_device;
}

void write_gpio(gpio_structure* gpio_device, uint8_t io_level)
{
    switch (io_level)
    {
        case HIGH:
            *(mmio_gpio + GPSET( ((gpio_device->gpio_num) / 32) )) |= (uint32_t)(1 << ((gpio_device->gpio_num) % 32) );
            break;
        case LOW:
            *(mmio_gpio + GPCLR( ((gpio_device->gpio_num) / 32) )) |= (uint32_t)(1 << ((gpio_device->gpio_num) % 32) );
            break;
        default:
            break;
    };

}

uint8_t read_gpio(gpio_structure* gpio_device)
{
    // return *(mmio_gpio + GPLEV( ((gpio_device->gpio_num) / 32) ) & (uint32_t)(1 << (gpio_device->gpio_num % 32));
    return 0;
}
/*
int main()
{
    gpio_setup();
    return 0;
}
*/