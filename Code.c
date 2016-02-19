#include<avr/io.h>
#include<util/delay.h>
#include "lcd_lib.c"
#include<stdint.h>
#include<stdio.h>

//unsigned char i,X;

static int LCDsendstream(char c , FILE *stream);

//----set output stream to LCD-------
static FILE lcd_str = FDEV_SETUP_STREAM(LCDsendstream, NULL, _FDEV_SETUP_WRITE);

static int LCDsendstream(char c , FILE *stream)
{
LCDsendChar(c);
return 0;
}

void delay_ms(int q)
{
	_delay_ms(q);
}
	
void init()
{	
	stdout = &lcd_str;	
	LCDinit();
	LCDclr();
	LCDcursorOFF();
	LCDclr();	
	DDRA=0x00;
	DDRB=0x00;
	DDRC=0xFF;
	DDRD=0xFF;
	PORTA=0x00;
	PORTB=0x00;
	PORTD=0x00;	
}

void forward()
{
	PORTD=(1<<PD4)|(0<<PD5)|(1<<PD6)|(0<<PD7);
   // _delay_ms(1000);
	LCDGotoXY(0,0);
	printf("forward");
}


void right()
{
	PORTD=(1<<PD4)|(0<<PD5)|(0<<PD6)|(0<<PD7);
  //  _delay_ms(500);
	LCDGotoXY(0,0);
	printf("right          ");
}

void left()
{
	PORTD=(0<<PD4)|(0<<PD5)|(1<<PD6)|(0<<PD7);
  //  _delay_ms(500);
	LCDGotoXY(0,0);
	printf("left           ");
}

void stop()
{
	PORTD=(0<<PD4)|(0<<PD5)|(0<<PD6)|(0<<PD7);
 //	_delay_ms(500);
	LCDGotoXY(0,0);
	printf("stop           ");
}    

void reverse()
{
	PORTD=(0<<PD4)|(1<<PD5)|(0<<PD6)|(1<<PD7);
 //	_delay_ms(500);
	LCDGotoXY(0,0);
	printf("reverse         ");
}    

void long()
{
	PORTD=(0<<PD4)|(0<<PD5)|(0<<PD6)|(0<<PD7);
//	_delay_ms(500);
	LCDGotoXY(0,0);
	printf("Voice too long   ");
}    

void short()
{
	PORTD=(0<<PD4)|(0<<PD5)|(0<<PD6)|(0<<PD7);
//	_delay_ms(500);
	LCDGotoXY(0,0);
	printf("Voice too short     ");
}    

void unmatch()
{
	PORTD=(0<<PD4)|(0<<PD5)|(0<<PD6)|(0<<PD7);
//	_delay_ms(500);
	LCDGotoXY(0,0);
	printf("Voice not matched  ");
}    

void obstacle()
{
	PORTD=(0<<PD4)|(0<<PD5)|(0<<PD6)|(0<<PD7);
//	_delay_ms(500);
	LCDGotoXY(0,0);
	printf("Object ");
}   

int main()
{
  init();
  while(1)
	{	
	/*	forward();
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);		
		right();
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		_delay_ms(500);
		}*/
		
		if(bit_is_clear(PINA,2))
				{
					obstacle();
					PORTD=0x01;
					_delay_ms(2000);
					PORTD=0x00;
				}
		 }			

				i=PINB&0b11111111;
				switch(i)
					{
						case 0b000000001:forward();
							 break;
			 	
						case 0b00000011:right();
						     	 break;
			 	
						case 0b000000101:left();
							 break;
			 	
						case 0b000000111:stop();
							 break;
						
						case 0b000001001:reverse();
							 break;
						
						case 0b001010101:long();
							 break;
						
						case 0b001100110:short();
							 break;

						case 0b001110111:unmatch();
							 break;
					}
	}	
return 0;
}	
