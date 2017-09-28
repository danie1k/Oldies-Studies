#include <stdio.h>
#include <stdlib.h>

float floatScanf(char *komunikat);

int main(void) {
	float e, suma = 0.0;
	int n = 0;

	printf("Realizacja cwiczenia 6.5B\n\n");

	do {
		e = floatScanf("Podaj dowolna liczbe dodatnia e: ");
	}
	while (e < 0);

	do {
		n++;
		suma += (1.0/n);
		printf("n    = %d\nsuma = %.2f\n\n", n, suma);
		if(n%7 == 0) {
			system("pause");
			system("cls");
		}
	}
	while (suma < e);
	printf("\nOsiagnieta suma ciagu: %.4f", suma);
	printf("\nNajmniejsza liczba n spelniajaca zadanie to: %d\n\n", n);

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
