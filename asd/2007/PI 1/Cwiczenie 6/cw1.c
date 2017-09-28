#include <stdio.h>
#include <stdlib.h>

int intScanf(char *komunikat);
float floatScanf(char *komunikat);

int main(void) {
	float liczba, suma = 0;
	int i, n;

	printf("Realizacja cwiczenia 6.1:\n");
	printf("Program liczy sume n liczb rzeczywistych\n\n");

	n = intScanf("Podaj ilosc liczb n: ");
	printf("\n");

	for(i = 0; i < n; i++) {
		liczba = floatScanf("Podaj liczbe: ");
		suma += liczba;
	}
	printf("\nSuma podanych liczb wynosi: %.2f\n\n", suma);

	system("pause");
	return 0;
}

int intScanf(char *komunikat) {
	char tmp[10];
	int tryAgain = 0;
	do {
		if(tryAgain) {
			printf("\nPodana wartosc jest nieprawidlowa!\n  ");
		}
		printf(komunikat);
		scanf("%s", tmp);
		if(atoi(tmp) == 0) {
			tryAgain = 1;
		}
		else {
			tryAgain = 0;
		}
	}
	while(tryAgain);
	return atoi(tmp);
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
