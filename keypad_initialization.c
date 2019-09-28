#include "C:/Keil/labware/inc/tm4c123gh6pm.h"
#include "tm4c123gh6pm.h"
#include "stdint.h"

void Keypad_init(void){
    SYSCTL_RCGCGPIO_R |= 0x04;
    SYSCTL_RCGCGPIO_R |= 0x10;

    GPIO_PORTE_DIR_R |= 0x0F;
    GPIO_PORTE_DEN_R |= 0x0F;          // 7) enable digital I/O on PE0-3
    GPIO_PORTE_ODR_R |= 0x0F;

    GPIO_PORTC_DIR_R &= ~0xF0;
    GPIO_PORTC_DEN_R |= 0xF0;
    GPIO_PORTC_PUR_R |= 0xF0;          // enable pull-up on PC4-7
}

