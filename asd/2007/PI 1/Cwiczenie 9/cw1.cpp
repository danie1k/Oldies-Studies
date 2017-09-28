#include <stdio.h>
#include <stdlib.h>

int pierwsza(int liczba);
int intScanf(char *komunikat);

int main(void) {
	int i, liczba, licznikPar = 0, tablica[20][2];

	printf("Realizacja cwiczenia 9.1:\n");
	printf("Program wyszukije liczby blizniacze wieksze od zadanej\n\n");

	do {
		liczba = intScanf("Podaj liczbe calkowita a (1000 < a > 0): ");
	}
	while ((liczba <= 0) || (liczba >= 1000));

	for(i = liczba; licznikPar < 20; i++) {
		if(pierwsza(i) && pierwsza(i + 2)) {
			tablica[licznikPar][0] = i;
			tablica[licznikPar][1] = i + 2;
			licznikPar++;
			i += 2;
		}
	}

	system ("cls");

	printf("Sprawdzanie od liczby: %3d ", liczba);
	printf("           |  lp  |  liczby blizniacze  |\n");
	printf("                                      +------+---------------------+\n");
	for(i = 0; i < 20; i++) {
		printf("                                      |  %02d  |", (i + 1));
		printf("   %6d i %-6d   |\n", tablica[i][0], tablica[i][1]);
	}
	printf("                                      +------+---------------------+\n\n");


	system("pause");
	return 0;
}

int pierwsza(int liczba) {
	int i, ret = 1;

	for(i = 2; i < liczba; i++) {
		if(liczba%i == 0) {
			ret = 0;
		}
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
