//
//  LABORATORIUM 2
//  Wykorzystanie przerwania generowanego przycikiem 
//  do za�wiecenia diod przez 1 sek.
//


// 
// WERSJA DLA INT0 (port PD2)
// ----------------------------------------------------------------------------
//
// MCUR okre�la jaki rodzaj zdarzenia ma by� obserwowany (slajd 23)
// MCUR: 0 0 0 0 0 0 0 1 - Dowolna zmiana stanu logicz. INT0 wywo�a przerwanie
//
// MCUR |= (0<<ISC01) | (1<<ISC00);
// MCUR = 0b00000001;
//
//
// "odpowiednia maska przerwa� w GICR odblokowuj�ca przerwania"
//
// GICR: INT1 INT0 INT2 0 0 0 0 0
//
// GICR |= (0<<INT1) | (1<<INT0) | (0<<INT2);
// GICR = 0b01000000;
//


//#ifndef F_CPU  
//  #define F_CPU   16000000    // 16 MHz - turn on external resonator (fuse bits)
//#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h> 

int main(void)
{

	// PORTB jako wyj�cie
	DDRB = 0xFF;

	// Inicjalizacja portu B
    PORTB = 0x00;


	// Obs�uga przerwa� INT0
	MCUCR = 0b00000001;
	GICR = 0b01000000;

	// Uruchamia przerwania
	sei();

	while(1){}; 

	return 0;
}


SIGNAL(SIG_INTERRUPT0)
{ 
	PORTB = 0xFF;

	// 1 sekunda?
   	_delay_ms(10000);

	PORTB = 0x00;
}
