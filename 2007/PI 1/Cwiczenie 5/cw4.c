#include <stdio.h>
#include <stdlib.h>

float floatScanf(char *komunikat);

int main(void) {
	float liczbaA, liczbaB, lewa, prawa;

	printf("Realizacja cwiczenia 5.4:\n");
	printf("Program sprawdza tozsamosc (a + b)*(a - b) = a^2 - b^2\n\n");

	liczbaA = floatScanf("Podaj liczbe A: ");
	liczbaB = floatScanf("Podaj liczbe B: ");

	lewa  = (liczbaA + liczbaB)*(liczbaA - liczbaB);
	prawa = liczbaA*liczbaA - liczbaB*liczbaB;
	printf("\nLewa strona:  (a + b)(a - b) = %.2f", lewa);
	printf("\nPrawa strona:      a^2 - b^2 = %.2f\n", prawa);

	if(lewa == prawa) {
		printf("\nTozsamosc jest spelniona dla podanych liczb.\n\n");
	}
	else {
		printf("\nPodane liczby nie spelniaja tego rownania.\n\n");
	}

	system("pause");
	return 0;
}

float floatScanf(char *komunikat) {
	char tmp[100];
	int tryAgain = 0;
	do {
		if(tryAgain) {
			printf("\nPodana wartosc jest nieprawidlowa!\n  ");
		}
		printf(komunikat);
		scanf("%s", tmp);
		if(atof(tmp) == 0.0) {
			tryAgain = 1;
		}
		else {
			tryAgain = 0;
		}
	}
	while(tryAgain);
	return atof(tmp);
}
