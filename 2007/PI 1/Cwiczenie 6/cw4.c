#include <stdio.h>
#include <stdlib.h>

float floatScanf(char *komunikat);

int main(void) {
	float a, b, tmp;
	int i = 0, j, n, nMin, nMax, all = 1;

	printf("Realizacja cwiczenia 6.4:\n");
	printf("Program sprawdza czy liczby naturalne z przedzialu spelniaja nierownosc\n\n");

	printf("Podaj przedzial liczb <a; b>:\n");
	do {
		a = floatScanf(" a: ");
	}
	while (a < 0.0);

	do {
		b = floatScanf(" b: ");
	}
	while (b < 0.0);

	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	printf("\nZadeklarowany przedzial: <%.2f; %.2f>\n\n", a, b);

	nMin = (int) a;
	nMax = (int) b;

	printf("Liczby nie spelniajace nierownosci to:\n ");
	for(n = nMin; n <= nMax; n++) {
		if((n*n*n + 20*n) >= (3*n*n + 370)) {
			all = 0;
			printf("%3d ", n);
		}
	}
	if(all) {
		printf(" Wszystkie liczby z podanego przedzialu spelniaja ta nierownosc.");
	}
	printf("\n\n");

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
