#include "Functions.h"
#include "C:/Keil/labware/inc/tm4c123gh6pm.h"
#include "stdint.h"


void LED_init(void){
	volatile uint32_t delay;
SYSCTL_RCGCGPIO_R |= 0x00000020;  
  delay = SYSCTL_RCGCGPIO_R;        
  GPIO_PORTF_CR_R = 0x1F; 	
  GPIO_PORTF_DIR_R = 0x0E;          
  GPIO_PORTF_DEN_R = 0x0E;          
}

void LED_indicators(uint32_t data){ // write PF3-PF1 outputs
  GPIO_PORTF_DATA_R |= data;      
}