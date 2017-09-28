
#ifndef F_CPU  
  #define F_CPU   16000000    // 16 MHz - turn on external resonator (fuse bits)
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdlib.h>
#include "HD44780.h"


// SPI INTERFACE CONFIG ---------------
#define SPI_HW_PORT PORTB
#define SPI_HW_DIR  DDRB
#define SPI_HW_PIN  PINB

#define SPI_HW_SCK  PB7
#define SPI_HW_MISO PB6
#define SPI_HW_MOSI PB5
#define SPI_HW_CS   PB4 // uaktywnienie uk³adu "slave" - uklad tylko do odczytu!
//-------------------------------------

void initSPI(void) {
	SPI_HW_DIR |= (1<<SPI_HW_CS) | (1<<SPI_HW_SCK) | (1<<SPI_HW_MOSI);

	SPCR |= (1<<SPE);  // SPI Enable
	//SPCR |= (1<<SPIE); // SPI Interrupt Enable
	SPCR |= (1<<MSTR); // [1] Master / [0] Slave

	SPCR |= (1<<SPR0);

	// Kkonfiguracja czêstotliwoœci sygna³u zegara SPI generowanego przez Master'a na linii SCK.
	// SPR1 | SPR0 | Czêstotliwoœæ SCK
	//  0   |  0   |       fosc/4
	//  0   |  1   |       fosc/16
	//  1   |  0   |       fosc/64
	//  1   |  1   |      fosc/128
}

char getSPDR(void) {
    SPDR = 0;                      // Wysy³a sygna³ sterujacy do pobrania wartoœci; najpierw MSB potem LSB
    while( !(SPSR & (1<<SPIF)) );  // Oczekiwanie na zakoñczenie transmisji - do ustawienia SPIF
	return SPDR;                   // Zwraca dane, które nadesz³y
}

void readModeSPI(int sw) {
	if(sw)
		// Communication with the TC77 is initiated when the CS goes to a logic ‘0’
		SPI_HW_PORT &= ~(1<<SPI_HW_CS);
	else
		// Then CS goes to the inactive state;
		SPI_HW_PORT |= (1<<SPI_HW_CS);
}


int getRawTemperature(void) {
	char MSB, LSB;

	readModeSPI(1);
	MSB = getSPDR();
	LSB = getSPDR();
	readModeSPI(0);

	//return ((MSB<<8) + LSB);
	return ((MSB<<8) + LSB)>>3;
}


//SIGNAL(SPI_STC_vect) { }


int main(void) {
	int temperatura, tempCalkowita, tempUlamkowa;
	double tempStC;
	char tempCalk[5], tempUlamk[5];

	initSPI();

	LCD_Initialize();
	LCD_Clear();

	for(;;){
		temperatura = getRawTemperature();
		tempStC = (double)temperatura*0.625;

		tempCalkowita = (int)floor(tempStC);
		tempUlamkowa  = (int)floor((tempStC - tempCalkowita)*1000);
		itoa(tempCalkowita, tempCalk,  10);
		itoa(tempUlamkowa,  tempUlamk, 10);

		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteText("Temperatura: ");
		LCD_WriteText(tempCalk);
		LCD_WriteText(".");
		LCD_WriteText(tempUlamk);
		LCD_WriteText("°C");
		_delay_ms(200);
	}

	return 0;
}
