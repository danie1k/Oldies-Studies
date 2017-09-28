#include <stdio.h>
#include <stdlib.h>

float potegaIteracyjnie(int wykladnik);
float potegaRekurencyjnie(int wykladnik);
int intScanf(char *komunikat);

int main(void) {
	int liczba;

	printf("Realizacja cwiczenia 10.1:\n");
	printf("Obliczniae potegi liczby 2 dwiema metodami: iteracyjna i rekurencyjna\n\n");

	liczba = intScanf("Podaj wykladnik potegi n: ");

	printf("\n2^n iteracyjnie:.. %.0f", potegaIteracyjnie(liczba));
	printf("\n2^n rekurencyjnie: %.0f\n\n", potegaRekurencyjnie(liczba));

	system("pause");
	return 0;
}

float potegaIteracyjnie(int wykladnik) {
	float ret = 1;
	int i;

	for(i = 1; i <= wykladnik; i++) {
		ret *= 2;
	}
	return ret;
}

float potegaRekurencyjnie(int liczba) {
	float ret = 1;

	if(liczba > 0) {
		ret = 2 * potegaRekurencyjnie(liczba - 1);
	}
	return ret;
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
