#include "Functions.h"

int number_conversion (int array[10]){
	int i;
	int temp = 0;
	for (i =0; i>10; i++){
		temp = temp*10 + array[i];
	}
	return temp;
}

char integar_convert(int result1)
{ 
	char temp[3];
	int i;
	
	if(result1 <= 9)
	{
  temp[0] = (result1 +'0');
	//return *temp;
	}
	else if((result1 >= 10)&&((result1 <= 99))) 
 { 
	 
   temp[0]=((result1/10)+'0');
   temp[1]=((result1%10)+'0');
	// return *temp;
	 
 }
  else if((result1 >= 100)&&((result1 <= 999))) 
 {
  temp[0] = ((result1/100)+'0');
 temp[1]=(((result1%100)/10)+'0');
  temp[2] = (((result1%100)%10)+'0');
	
 }
 /*else if((result1 >= 1000)&&((result1 <= 9999))) 
 {
   LCD_data((result1/1000)+'0');
   LCD_data(((result1%1000)/100)+'0');
   LCD_data((((result1%1000)%100)/10)+'0');
   LCD_data((((result1%1000)%100)%10)+'0');
 }*/
  return *temp;
}
