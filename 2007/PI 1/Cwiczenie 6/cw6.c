#include <stdio.h>
#include <stdlib.h>

float floatScanf(char *komunikat);

int main(void) {
	float liczba, suma = 0;
	int iloscPodanychLiczb = 0, liczbyDodatnie = 0, wyrazyMniejsze = 0;

	printf("Realizacja cwiczenia 6.6:\n\n");
	printf("Obliczanie sredniej arytmetycznej danego ciagu\n");
	printf("i ustalenie ile wyrazow ma modul mniejszy od 100\n");
	printf("Wpisanie 0 (zero) konczy dzialanie programu\n\n");

	do {
		printf("Podaj liczbe: ");
		scanf("%f", &liczba);

		if(liczba != 0) {
			iloscPodanychLiczb++;
		}
		if((liczba != 0) && (liczba > 0)) {
			suma += liczba;
			liczbyDodatnie++;
		}
		if((liczba != 0) && (fabs(liczba) < 100)) {
			wyrazyMniejsze++;
		}
	}
	while (liczba != 0);

	printf("\nPodanych liczb: %d\n", iloscPodanychLiczb);
	printf("\nSuma podanych liczb: %.3f", suma);
	printf("\nSrednia arytmetyczna liczb dodatnich: %.3f", suma/liczbyDodatnie);
	printf("\nWyrazy o module < 100: %d\n\n", wyrazyMniejsze);

	system("pause");
	return 0;
}
