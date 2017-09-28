#include <stdio.h>
#include <stdlib.h>

float floatScanf(char *komunikat);

int main(void) {
	float liczba1, liczba2;

	printf("Realizacja cwiczenia 5.3:\n");
	printf("Obliczanie sredniej arytmetycznej dwoch dowolnych liczb\n\n");

	liczba1 = floatScanf("Podaj pierwsza liczbe: ");
	liczba2 = floatScanf("Podaj druga liczbe: ");
	printf("\nSrednia arytmetyczna tych liczb wynosi: %.2f\n\n", (liczba1 + liczba2)/2);

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
