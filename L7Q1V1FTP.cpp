/*
    Currently this program writes STOP on the 4 digit display then
    scrolls Covid . Add to the message so that it scrolls Covid19
    instead of just   Covid. Then also adjust the range of the inner 
    for loop    to adjust for the extra 2 characters you have put in your
    character array.            
*/

// Include Section
#include "mbed.h"                   
#include "DigitDisplay.h"          

// Hardware definitions
DigitDisplay segment(D2,D3);        

// Global variables
unsigned char mess[]= {0x00,0x00,0x00,0x00,          
                       0x39,0x5c,0x1c,0x04,0x5e,
                       0x00,0x00,0x00,0x00};          
unsigned short i;

int main(void)
{
    segment.clear();                
    segment.setColon(0);            
    segment.setBrightness(4);       
 
    for(;;)                         
    {                                   
        segment.writeRaw(0,0x6d);   
        segment.writeRaw(1,0x78);
        segment.writeRaw(2,0x3f);
        segment.writeRaw(3,0x73);  
        wait_ms(500);
      for(i=0;i<=9;++i)             
      {
         segment.writeRaw(&mess[i]); 
         wait_ms(250);
      }
      wait_ms(1000);                
    }
                          
}