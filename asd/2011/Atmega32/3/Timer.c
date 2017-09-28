//
//  LABORATORIUM 3
//  Programowanie wy�wietlacza, licznik sekund 
//  z wy�wietlaniem warto�ci na wy�wietlaczu LCD
//  zliczanie od 0 do 60 z wykorzystaniem timera
//

// 
// TCCR0 - bity kontrolne do wyboru zegara licznika 0
// TCCR0: 0 0 0 0 0 CS02 CS01 CS00
//
// CS02 CS01 CS00                opis
//   0    0    0    brak �r�d�a (licznik wy��czony)
//   0    0    1    zbocze narastaj�ce ka�dego cyklu zegara
//   0    1    0    zbocze narastaj�ce co 8 cyklu zegara    |
//   0    1    1    zbocze narastaj�ce co 64 cyklu zegara   |__ preskaler
//   1    0    0    zbocze narastaj�ce co 256 cyklu zegara  |
//   1    0    1    zbocze narastaj�ce co 1024 cyklu zegara |
//   1    1    0    zbocze opadaj�ce na pinie T0 (PB0)
//   1    1    1    zbocze narastaj�ce na pinie T0 (PB0)
// 
// TCCR0 = 0b00000 001 - zbocze narastaj�ce ka�dego cyklu zegara
//
// TCNT0 zawiera zawiera aktualn� warto�� licznika 0
//
// Tryb pracy licznika: CTC (Clear Timer on Compare) kasowanie przy zr�wnaniu:
// licznik zlicza od 0 do OCR0 i potem zn�w od zera
//
// TCCR0 zawiera mi�dzy innymi bity ustawienia trybu pracy licznika 0
// TCCR0: 0 WGM00 COM01 COM00 WGM01 0 0 0
//
// TCCR0 = 0b0 0000 000 - tryb zwyk�y: licznik zlicza od 0 do 255 i potem zn�w od zera
//
//
// TIPS: (http://www.avrfreaks.net/index.php?name=PNphpBB2&file=viewtopic&t=50106)
//
// Target Timer Count = (Input Frequency / Prescale) / Target Frequency - 1 
// One Megahertz is 1/1000000 of a second
//
// Dla preskalera 1024 jedna sek. to 975.5625



#define F_CPU   1000000    // 16000000 = 16 MHz - tutaj: 1 Mhz

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "HD44780.h"

int main (void)
{
	// Obs�uga CHAR LCD:
	int i = 0;
	char chr[20];

	LCD_Initialize();

	LCD_GoTo(0,0);
	LCD_WriteText(itoa(i++, chr, 10));


		// Inicjalizacja TIMER1B. Preskaler na 1024, tryb CTC (generuje przerwania)
		TCCR1B |= (1<<CS12) | (1<<CS10) | (1<<CTC1);

		// Zlicza od zera
		TCNT1   = 0;
		
		// Zlicza do 976 dla preskalera 1024
		OCR1A   = 976; 

		// Enable CTC interrupt
		TIMSK |= (1 << OCIE1A);  

		sei();


	while(1){ };

	return 0;
}

ISR(TIMER1_COMPA_vect)
{
	if(i < 10)
	{
		LCD_GoTo(0,0);
		LCD_WriteText("0");

		LCD_GoTo(1,0);
		LCD_WriteText(itoa(i++, chr, 10));
	}
	else // je�li liczba < 10 to wy�wietla "0" (zero) z przodu
	{
		LCD_GoTo(0,0);
		LCD_WriteText(itoa(i++, chr, 10));
	}

	if(i >= 60)
	{
		i = 0;
	}
} 
