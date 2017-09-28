//
//  LABORATORIUM 1
//  W³¹czanie i wy³¹czanie diod
//

#ifndef F_CPU  
  #define F_CPU   16000000    // 16000000 = 16 MHz - tutaj: 1 Mhz
#endif


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

	// Ustawienie portów jako wyjœæ
	DDRB = 0xFF;
	//DDRD = 0xFF;

	// Ustawienie niskich stanów portów
	PORTB = 0x00;
	//PORTD = 0x00;

	do
	{
		PORTB = 0b00001110;
			_delay_ms(100);

		PORTB = 0b00000000;
			_delay_ms(100);

		PORTB = 0b10000000;
			_delay_ms(100);

		PORTB = 0b01100000;
			_delay_ms(100);

		PORTB = 0b11100000;


	} while(1);

	return 0;
}
