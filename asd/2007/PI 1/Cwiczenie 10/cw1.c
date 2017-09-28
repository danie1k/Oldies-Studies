#include <stdio.h>
#include <stdlib.h>

long long silniaIteracyjnie(int liczba);
long long silniaRekurencyjnie(int liczba);
int intScanf(char *komunikat);

int main(void) {
	int liczba;

	printf("Realizacja cwiczenia 10.1:\n");
	printf("Obliczniae silni dwiema metodami: iteracyjna i rekurencyjna\n\n");

	liczba = intScanf("Podaj liczbe do silni: ");

	printf("\nSilnia iteracyjnie:.. %lld", silniaIteracyjnie(liczba));
	printf("\nSilnia rekurencyjnie: %lld\n\n", silniaRekurencyjnie(liczba));

	system("pause");
	return 0;
}

long long silniaIteracyjnie(int liczba) {
	long ret = 1;
	int i;

	for(i = 1; i <= liczba; i++) {
		ret *= i;
	}
	return ret;
}

long long silniaRekurencyjnie(int liczba) {
	long ret = 1;

	if((liczba != 0) && (liczba > 1)) {
		ret = liczba*silniaRekurencyjnie(liczba - 1);
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
