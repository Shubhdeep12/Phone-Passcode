#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void loc(char a);
void data(char b);
void ini();
void string(char *str);
unsigned char keypad();
void main()
{
DDRA=0b11110000;
DDRB=0b11111111;
DDRC=0b11111111;
PORTA=0b11111111;
ini();
while(1)
{
int i=4;
loc(0X80);
string("ENTER THE PIN :-");

char x=keypad();
loc(0xc0);
num(x);
char y=keypad();
loc(0xc1);
num(y);
char z=keypad();
loc(0xc2);
num(z);
char q=keypad();
loc(0xc3);
num(q);
_delay_ms(10);
loc(0x01);
_delay_ms(10);
while(((x!=1)|(y!=1)|(z!=1)|(q!=0))&&(i<7))
{
if(i<5)
{
loc(0x85);
string("WRONG PIN");
loc(0xc4);
string("TRY AGAIN");
_delay_ms(100);
loc(0x01);
_delay_ms(5);
}
else if(i>4&&i<6)
{

for(int j=29;j>=0;j--)
{
loc(0x80);
string("WAIT 30 SECONDS");
loc(0xc0);
string("TIME LEFT :-");
loc(0xcd);
num(j);
_delay_ms(100);
loc(0x01);
_delay_ms(5);
}

}
else if(i>5)
{
loc(0x01);
_delay_ms(5);
string("SYSTEM BLOCKED");
while(1)
{}
}
loc(0X80);
string("ENTER THE PIN :-");
i++;
char x=keypad();
loc(0xc0);
num(x);
char y=keypad();
loc(0xc1);
num(y);
char z=keypad();
loc(0xc2);
num(z);
char q=keypad();
loc(0xc3);
num(q);
_delay_ms(10);
loc(0x01);
_delay_ms(5);


}
loc(0x85);
string("WELCOME");
_delay_ms(1);
loc(0x01);

}
}

void string(char *str)
{
int i=0;
while(str[i]!='\0')
{
data(str[i]);
i++;
}}
void loc(char a)
{
PORTC=((a&0xf0)|0x04);
PORTC=PORTC-0X04;
_delay_us(10);
PORTC=((a<<4)&0xf0|0x04);
PORTC=PORTC-0X04;
_delay_us(10);
}
void data(char b)
{
PORTC=((b&0xf0)|0x05);
PORTC=PORTC-0X04;
_delay_us(10);

PORTC=((b<<4)&0xf0|0x05);
PORTC=PORTC-0X04;
_delay_us(10);
}
void ini()
{
loc(0x02); //for home screen
loc(0x28); //to work lcd in  bit mode
loc(0x0c); //display on , cursor off

}
 void num(char ch)
{
int x;
if(ch==0)
data(48);
while(ch!=0)
{
loc(0x04);
x=ch%10;
data(48+x);
ch=ch/10;
}}

unsigned char keypad()
{
while(1)
{
PORTB=0B00000110;
_delay_us(10);

if(PINA==0b11111110)
{
while(PINA==0b11111110);
return 1;
}
else if(PINA==0B11111101)
{
while(PINA==0b11111101);
return 4;
}
else if(PINA==0B11111011)
{
while(PINA==0B11111011);
return 7;
}
else if(PINA==0B11110111)
{
while(PINA==0B11110111);
return '#';
}


PORTB=0B00000101;
_delay_us(10);

if(PINA==0b11111110)
{
while(PINA==0b11111110);
return 2;
}
else if(PINA==0B11111101)
{
while(PINA==0b11111101);
return 5;
}
else if(PINA==0B11111011)
{
while(PINA==0B11111011);
return 8;
}
else if(PINA==0B11110111)
{
while(PINA==0B11110111);
return 0;
}

PORTB=0B00000011;
_delay_us(10);

if(PINA==0b11111110)
{
while(PINA==0b11111110);
return 3;
}
else if(PINA==0B11111101)
{
while(PINA==0b11111101);
return 6;
}
else if(PINA==0B11111011)
{
while(PINA==0B11111011);
return 9;
}
else if(PINA==0B11110111)
{
while(PINA==0B11110111);
return '*';
}
}
}

