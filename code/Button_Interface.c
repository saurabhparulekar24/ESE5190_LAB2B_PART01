#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"
#include "pixel.h"
#include "pushbutton.h"
#include "sio_registers.h"
/*
// Register    : SIO_GPIO_IN
// Description : Input value for GPIO pins
//               Input value for GPIO0...29
#define SIO_GPIO_IN_OFFSET _u(0x00000004)
#define SIO_GPIO_IN_BITS   _u(0x3fffffff)
#define SIO_GPIO_IN_RESET  _u(0x00000000)
#define SIO_GPIO_IN_MSB    _u(29)
#define SIO_GPIO_IN_LSB    _u(0)
#define SIO_GPIO_IN_ACCESS "RO"

#define SIO_BASE _u(0xd0000000)

WE can see that the SIO base is 0xd0000000, and the input register offset is 0x00000004, therefore we can read
the status of all the GPIO pins by reading the register
*/

int main(){
    pixel_init();
    stdio_init_all();
    VALUE a;
    while(true){
        a = register_read((ADDRESS)0xd0000004);
        if(!(1<<21 & a)){
            printf("%d",(1<<21 & a));
            pixel_set(0x00ff0000);
            printf("Hello\n");
            sleep_ms(10);
        }
        else{
        pixel_set(0x0000ff00);
        printf("Hello\n");
        sleep_ms(10);

        pixel_set(0x000000ff);
        printf("Hello\n");
        sleep_ms(10);
        }
    }
    return 0;
}