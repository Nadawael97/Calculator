#include "C:/Keil/labware/inc/tm4c123gh6pm.h"
#include "stdint.h"
#include "Functions.h"

unsigned char get_char(void){
	const unsigned char keymap [4][4]={
		{'+','3','2','1'},
		{'-','6','5','4'},
		{'*','9','8','7'},
		{'/','=','0','.'},
	};
	
	int row, col;
	GPIO_PORTE_DATA_R = 0x00000000;
	col = GPIO_PORTC_DATA_R & 0xF0;
	if (col == 0xF0)
	    return 0;
	
	while (1){
		row = 0;
		GPIO_PORTE_DATA_R = 0x0E; //enable row 0
		Delay_Us(10); //wait for signal to settle
		col = GPIO_PORTC_DATA_R & 0xF0;
		if (col != 0xF0)
			break;
		
		row = 1;
		GPIO_PORTE_DATA_R = 0x0D; //enable row 1
		Delay_Us(10); //wait for signal to settle
		col = GPIO_PORTC_DATA_R & 0xF0;
		if (col != 0xF0)
			break;
		
		row = 2;
		GPIO_PORTE_DATA_R = 0x0B; //enable row 2
		Delay_Us(10); //wait for signal to settle
		col = GPIO_PORTC_DATA_R & 0xF0;
		if (col != 0xF0)
			break;
		
		row = 3;
		GPIO_PORTE_DATA_R = 0x07; //enable row 3
		Delay_Us(10); //wait for signal to settle
		col = GPIO_PORTC_DATA_R & 0xF0;
		if (col != 0xF0)
			break;

		return 0;
	}
	if (col == 0xE0) return keymap[row][0]; //key in column 0
	if (col == 0xD0) return keymap[row][1]; //key in column 1
	if (col == 0xB0) return keymap[row][2]; //key in column 2
	if (col == 0x70) return keymap[row][3]; //key in column 3
	return 0;
}
