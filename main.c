#include <msp430.h> 
#include <lcd.h>
char x,y,z;
int c,t;

	void primera_conf()
	{
	    P3DIR=0x0f;
	    P3REN=0Xf0;
	    P3OUT=0xf0;
	}
	
	void segunda_conf()
	{
	    P3DIR=0Xf0;
	    P3REN=0X0f;
	    P3OUT=0X0f;
	}

	unsigned char lcd(unsigned char c)
	{
	      switch(c){
	                                case 0x77: t=49;  x++; break;
	                                case 0x7B: t=50;  x++; break;
	                                case 0x7D: t=51;  x++; break;
	                                case 0x7E: t=65;  x++; break;
	                                case 0xB7: t=52;  x++; break;
	                                case 0xBB: t=53;  x++; break;
	                                case 0xBD: t=54;  x++; break;
	                                case 0xBE: t=66;  x++; break;
	                                case 0xD7: t=55;  x++; break;
	                                case 0xDB: t=56;  x++; break;
	                                case 0xDD: t=57;  x++; break;
	                                case 0xDE: t=67;  x++; break;
	                                case 0xE7: t=42;  x++; break;
	                                case 0xEB: t=48;  x++; break;
	                                case 0xED: t=35;  x++; break;
	                                case 0xEE: t=68;  x++; break;
	                                default: t=0;
	                  }
	      return t;

	}

unsigned char teclado()
	{
	    primera_conf();
	    while(1)
	    {
	        if((P3IN&0xf0)!=0xf0)
	        {
            __delay_cycles(10);
                if((P3IN&0xf0)!=0xf0)
                {
                  x=(P3IN&0xf0);
                  segunda_conf();
                  __delay_cycles(500);
                  x=x | (P3IN&0x0f);
                  x=lcd(x);
                  while((P3IN&0x0f)!=0x0f);
                  primera_conf();
                  __delay_cycles(500);
                  return x;
	            }
	        }

	    }

    }

int main(void)
      {
    WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    LCDinit();

    while(1){
    x=teclado();

    LCDputChar(x);
    }
   }
