#include<avr/io.h>
#include<util/delay.h>
void cmd(unsigned char ch1)
  {
          unsigned char ch2;
	  ch2 = (ch1 & 0xf0) >> 4;
	  PORTC = ch2;
          PORTD &= ~(1<<2);
	  PORTD &= ~(1<<3);
	  PORTD |= (1<<4);
i	  _delay_us(1);
	  PORTD &= ~(1<<4); 
          _delay_us(100);
          ch2 = ch1 & 0x0f;
	  PORTC = ch2;	
	  PORTD |= (1<<4);
	  _delay_us(1);
	  PORTD &= ~(1<<4);
          _delay_us(100);	

  } 

void data(unsigned char ch3)
  {
          unsigned char ch4;
	  ch4 = (ch3 & 0xf0) >> 4;
	  PORTC = ch4;
	  PORTD |= (1<<2);
	  PORTD &= ~(1<<3);
	  PORTD |= (1<<4);
	  _delay_us(1);
	  PORTD &= ~(1<<4); 
          _delay_us(100);
          ch4 = ch3 & 0x0f;
	  PORTC = ch4;	
	  PORTD |= (1<<4);
	  _delay_us(1);
	  PORTD &= ~(1<<4);
          _delay_us(100);	

  } 
void gotoxy(unsigned char x,unsigned char y)
{
        unsigned char firstcharaddr[] = {0x80,0xC0};
        cmd(firstcharaddr[y-1] + x - 1);	       //telling the position of beginning on LCD 
}

void init(void)
{
	DDRD = 0xFF;
	DDRB = 0xFF;
        PORTD = 0x00;
	cmd(0x33);               //4 bit lcd initialization
	cmd(0x32);               //4 bit lcd initialization
	cmd(0x28);               //2 lines 5 x 7 matrix (4 bit)
	cmd(0x0E);               //display on cursor blinking
	cmd(0x01);               //clear diaplay
	_delay_us(2000);
	cmd(0x06);               //shift cursor to the right
}

void print(char *str)
{
	unsigned char i;
	while(str[i]!=0)
	{
		data(str[i]);
		i++;
	}
}

void main()
{
	init();
	gotoxy(1,1);
	print("happy");
	gotoxy(1,2);
	print("independence");
	while(1);
}
# AVR-LCD
# AVR-LCD
# AVR-LCD
# avr-lcd
# avrlcd
# avrlcd
# avrlcd
# avrlcd
# avrlcd
