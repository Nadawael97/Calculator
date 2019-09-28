#include "C:/Keil/labware/inc/tm4c123gh6pm.h"
#include "stdint.h"
#include "math.h"
#include "Functions.h"

void string_display(char *p)
{
	while(*p)
	{
    LCD_data(*p);  
			Delay_ms(1);
    p++;		
	 }
	Delay_ms(1);
  LCD_data(' ');
	Delay_ms(1);
	LCD_command(0x10);
}
