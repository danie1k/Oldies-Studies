#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int intScanf(char *komunikat);
float floatScanf(char *komunikat);

int main(void) {
	float sumaPomiarow = 0.0, sredniaPomiarow = 0.0, wariancja = 0.0, *pomiary;
	int i, liczbaPomiarow;

	printf("Realizacja cwiczenia 6.3:\n");
	printf("Program oblicza wariancje i odchylenie standardowe\n\n");

	do {
		liczbaPomiarow = intScanf("Podaj liczbe pomiarow m (m < 200): ");
	}
	while (liczbaPomiarow >= 200);

	pomiary = new float[liczbaPomiarow];

	for(i = 0; i < liczbaPomiarow; i++) {
		pomiary[i] = floatScanf("Podaj wynik pomiaru: ");
		sumaPomiarow += pomiary[i];
	}
	sredniaPomiarow = sumaPomiarow/liczbaPomiarow;

	for(i = 0; i < liczbaPomiarow; i++ ) {
		wariancja += (pomiary[i] - sredniaPomiarow)*(pomiary[i] - sredniaPomiarow);
	}

	wariancja /= (liczbaPomiarow - 1);

	printf("\nSuma wynikow pomiarow:... %.2f", sumaPomiarow);
	printf("\nSrednia wynikow pomiarow: %.2f", sredniaPomiarow);
	printf("\nWariancja:............... %.2f", wariancja);
	printf("\nOdchylenie standardowe:.. %.2f\n\n", sqrt(wariancja));

	delete [] pomiary;
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
