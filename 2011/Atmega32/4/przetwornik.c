#ifndef F_CPU
	#define F_CPU 16000000
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <math.h>
#include "HD44780.h"
#include "USART.h"

char static wartADCH[5], napiecieCalkowite[5], napiecieUlamkowe[5];


SIGNAL(SIG_ADC)
{
	cli(); // Disable Global Interrupts

	int wartosc, wartCalkowita, wartUlamkowa;
	double napiecie;

	wartosc  = (int)ADCH; // Wartoœæ wskazywana przez przetwornik 0-255
	napiecie = ((double)wartosc)/51.0; // Przelcizanie wartoœci ADCH na napiêcie

	wartCalkowita = (int)floor(napiecie);
	wartUlamkowa  = (int)floor((napiecie - wartCalkowita)*1000);

	itoa(wartosc,       wartADCH,          10);
	itoa(wartCalkowita, napiecieCalkowite, 10);
	itoa(wartUlamkowa,  napiecieUlamkowe,  10);

	LCD_Clear();


	LCD_GoTo(0,0);
	LCD_WriteText("ADCH: ");
	LCD_WriteText(wartADCH);

		//USART_PutString("ADCH: ");
		//USART_PutString(wartADCH);
		//USART_PutChar('\r');

	LCD_GoTo(0,1);
	LCD_WriteText("Nap.: ");
	LCD_WriteText(napiecieCalkowite);
	LCD_WriteText(",");
	LCD_WriteText(napiecieUlamkowe);
	LCD_WriteText(" V");

	_delay_ms(250); // Aby wyœwietlacz LCD nie wariowa³

	sei(); // Enable Global Interrupts
} 

int main(void) {
	LCD_Initialize();
	LCD_Clear();

		//USART_Init(BAUD(1000));
		//USART_PutString("**    UART   **\r");


	ADMUX  |= (1 << REFS0); // ródo odniesienia AVCC + zewnêtrzny kondensator na AREF pin
	ADMUX  |= (1 << ADLAR); // Wynik konwersji przesuniêty w lewo, wystarczy odczytywaæ tylko 8 starszych bitów z rejestru ADCH (0-255 = 0-5V)

	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // Set ADC prescaler to 128
	ADCSRA |= (1<<ADEN);    // Enable ADC
	ADCSRA |= (1<<ADSC);    // Start A2D Conversions
	ADCSRA |= (1<<ADATE);   // W³¹czenie automatycznego trybu wyzwalania
	ADCSRA |= (1<<ADIE);    // Enable ADC Interrupt

	sei(); // Enable Global Interrupts

	for(;;);

	return 0;
}

