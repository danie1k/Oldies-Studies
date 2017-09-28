#include <stdio.h>
#include <stdlib.h>

float floatScanf(char *komunikat);

int main(void) {
	float bokA, bokB;

	printf("Realizacja cwiczenia 5.2:\n");
	printf("Obliczanie pola powierzchni prostokata\n\n");

	bokA = floatScanf("Podaj dlugosc boku A: ");
	bokB = floatScanf("Podaj dlugosc boku B: ");
	printf("\nPole tego prostokata wynosi: : %.1f\n\n", bokA*bokB);

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
