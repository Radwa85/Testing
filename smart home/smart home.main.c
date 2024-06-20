#include <avr/io.h>
#define _OPEN_SYS_ITOA_EXT
#include <stdlib.h>
#include <stdio.h>
#define F_CPU 16000000ul
#include <util/delay.h>
#define focs 4000000
#define baud 9600
#define BAUD_PRESCALE focs/16/baud - 1
int A ;
char data [5];
unsigned short x=0,i=0;
char TempSTR[2];
void UART_init()
{
	UBRRL =(unsigned char)( BAUD_PRESCALE);
	UBRRH = (unsigned char)((BAUD_PRESCALE) >> 8);
	UCSRB |= (1 << 4) | (1 << 3);
	UCSRC |= (1 << 2) | (1 << 1) ;
	
}
void UART_TxChar(unsigned char ch)
{
	while (!(UCSRA & (1<<5) ));
	UDR = ch ;
}
unsigned char UART_RxChar()
{
	while (!(UCSRA & (1 << 7) ));
	return UDR;
}
void UART_SendString(char*str )
{
	unsigned char j=0;
	
	while (str[j]!=0)
	{
		UART_TxChar(str[j]);
		j++;
	}
}

void display_menu()
{
	UART_SendString("\r*******MENU*******\r0-logout\r1-show tempreture \r2-toggle red led \r3-toggle yellow led\r4-toggle green led\rplease choose serviece: \r");
}
void verify_pass (void)
{  
	
	UART_SendString("password:");
	for(int i=0;i<5;i++)
	{
		data[i]=UART_RxChar();
	}
	UART_SendString("\r");
	if (data[0]=='r'&&data[1]=='a'&& data[2]=='d'&& data[3]=='w'&& data[4]=='a')
	{
		display_menu();
		i=0;
	
	}
}

void init_ADC();
uint16_t ADC_Read(uint8_t channel);
int main()
{
	init_ADC();
	UART_init();
	char s;
    verify_pass ();	
	while(1)
	{
		s=UART_RxChar();
		UART_SendString("\r");
		if   ((s=='2'))
		{
			DDRB |=(1<<0);
			PORTB|=(1<<0);
			display_menu();
		}
		if ((s=='3'))
		{
			DDRB |=(1<<1);
			PORTB|=(1<<1);
		    display_menu();
		}
		if ((s=='4'))
		{
			DDRB |=(1<<2);
			PORTB|=(1<<2);
			display_menu();
		}
		if ((s=='1'))
		{  
			A = ADC_Read(0)*0.489;
			itoa(A, TempSTR,10);
			UART_TxChar(TempSTR[2]);
			UART_SendString("the Temperature is:\r");
		    UART_SendString(TempSTR);
			display_menu();
		}
		if ((s=='0'))
		{
			verify_pass ();
			
		}
	}
}
void init_ADC(void)
{
	ADMUX  |=(1<<REFS0) ;
	ADCSRA |=(1<<ADEN) ;
	ADCSRA |=(1<<ADSC) ;
	ADCSRA |=((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
}
uint16_t ADC_Read(uint8_t channel)
{
	ADCSRA |=(1<<ADSC) ;
	ADMUX &= 0xF0;
	ADMUX |= channel;
	while (ADCSRA &(1<<ADSC));
	return ADC;
}