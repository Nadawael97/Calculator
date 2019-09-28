#include "C:/Keil/labware/inc/tm4c123gh6pm.h"
#include "stdint.h"
#include "Functions.h"

#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
#define PF0       (*((volatile uint32_t *)0x40025004))
#define RED       0x02
#define GREEN     0x08

void SystemInit(){};	

int main (){
	
	volatile unsigned char op;
	char operands1[3];
	char operands2[3];
	volatile char sign;
int operand_1[3];
	int operand_2[3];
	int operand1;
	int operand2;
	int result = 0;
	char result_char[3];
	volatile int i;
	int temp;
	
	//initializations
	LCD_init();
  Keypad_init();
	LED_init();
	
		LCD_command(1);       /* clear display */
    LCD_command(0x80);    /* lcd cursor location */
		Delay_ms(200000);
	
	while(1){
		while (get_char() == 0){}
		op=get_char();
			Delay_ms(200000);
		while(op!='+' &&op!='-'  &&op!='*'  &&op!='/'){
			static int i = 0;
			operands1[i]=op;
			operand_1[i] = (op-'0');
			i++;
			}
			string_display(operands1);
			operand1 = number_conversion (operand_1);
			//LCD_data(op);
		Delay_ms(200000);
		}
			
			
		if (op=='+' ||op=='-'  ||op=='*'  ||op=='/' ){
			sign=op;
			
			while(1){
				while (get_char() == 0){}
				op=get_char();
				LCD_data(op);
					
					while (op!='='){
						static int i = 0;
			operands2[i]=op;
			operand_2[i] = op-'0';
			i++;
			continue;
					}
			string_display(operands2);
			operand2 = number_conversion (operand_2);
					
				Delay_ms(2000000);
					}
				if(op=='='){
				
					//operand_2 = (operands1-'0');
					//operand_2 = (operands2-'0' );
					
					if (sign == '+')
					result = operand1+ operand2;
				
		else if (sign == '-')
			result = operand1- operand2;
		else if (sign == '*')
			result = operand1*operand2;
		else if (sign == '/'){
		  if (operand_2 == 0) {
					LCD_command(0xC0);
				Delay_ms(80);
						string_display("math error");
			
				LED_indicators(0x02);
					}
			 else 
						result = operand1 / operand2;
			 
				
		 }
		
		 for(i=0; i<3;i++){
	
		 result_char[i] = integar_convert(result);
		 }
		 
		 LED_indicators(0x08);
		 string_display(result_char);
		 Delay_ms(2000000);
			
				}	
				
				}
				
			}
	
		

