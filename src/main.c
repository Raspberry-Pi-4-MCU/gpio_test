#include "gpio.h"
#include <unistd.h>

int main()
{
    initial();
    gpio_structure* gpio26 = new_gpio(26, OUTPUT);
    while(1)
    {
        write_gpio(gpio26,HIGH);
        sleep(1);
        write_gpio(gpio26,LOW);
        sleep(1);
    }

    return 0;
}