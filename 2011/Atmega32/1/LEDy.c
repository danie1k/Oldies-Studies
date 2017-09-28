//
//  LABORATORIUM 1
//  W��czanie i wy��czanie diod
//

#ifndef F_CPU  
  #define F_CPU   16000000    // 16000000 = 16 MHz - tutaj: 1 Mhz
#endif


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

	// Ustawienie port�w jako wyj��
	DDRB = 0xFF;
	//DDRD = 0xFF;

	// Ustawienie niskich stan�w port�w
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
