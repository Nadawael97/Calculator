#include "stdint.h"
#include "C:/Keil/labware/inc/tm4c123gh6pm.h"

void Delay_Us(long t){
	  long i , j;
	   i = 0;
	   j = 0;
	  while(i<t){
       while(j<80){
				 j++;
			 //Do Nothing
			 }
			 i++;
	  }
}
//Function to delay t milliseconds
void Delay_ms(long t){
	  long i , j;
	   i = 0;
	   j = 0;
	  while(i<t){
       while(j<80000){
				 j++;
			 //Do Nothing
			 }
			 i++;
	  }
}
