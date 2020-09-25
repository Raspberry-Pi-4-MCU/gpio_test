#include "gpio.h"
#include <unistd.h>

int main()
{
    initial();
    pinMode(26,OUTPUT);
    for(int idx = 0; idx < 3; idx++)
    {
        digitalWrite(26,HIGH);
        sleep(1);
        digitalWrite(26,LOW);
        sleep(1);
    }
    gpio_structure* gpio26 = new_gpio(26, OUTPUT);
    // blink
    for(int idx = 0; idx < 3; idx++)
    {
        write_gpio(gpio26,HIGH);
        sleep(1);
        write_gpio(gpio26,LOW);
        sleep(1);
    }
    return 0;
}