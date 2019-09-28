#include"stdint.h"

//LCD Functions
void Delay_Us(long);
void Delay_ms(long);
void LCD_init(void);
void LCD_command (unsigned char);
void LCD_data(unsigned char);

//Calculator Basic Operations
signed long Add ( signed long , signed long);
signed long Subtract ( signed long ,signed long);
signed long Multiply (signed long ,signed long);
signed long Divide ( signed long ,signed long);

//Keypad Functions
void Keypad_init(void);
unsigned char get_char(void);

//LCD_Keypad_interface
void display_key(char);
void string_display(char *);


//Calculator Additional Operations
void LED_init();
void LED_indicators(uint32_t);
int number_conversion (int*);
char integar_convert(int);