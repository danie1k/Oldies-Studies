#include <stdio.h>
#include <stdlib.h>

#include "funkcjeSortowania.h"

void sortowaniePrzezWstawianie(int *tab, int rozmiar);
int intScanf(char *komunikat);

int main(void) {
	int i, ilosc, *tablica;

	printf("Realizacja cwiczenia 11.2:\n");
	printf("Program wpisuje do tablicy okreslona ilosc liczb podanych przez uzytkownika");
	printf("\na nastepnie sortuje je niemalejaco metoda sortowania karcianego.\n\n");

	ilosc = intScanf("Podaj ilosc liczb jakie chcesz wprowadzic pozniej do programu: ");

	tablica = new int[ilosc];

	for(i = 0; i < ilosc; i++) {
		tablica[i] = intScanf("Podaj liczbe: ");
		//printf("Podaj %2d liczbe: ", (i + 1));
		//scanf("%d", &tablica[i]);
	}

	printf("\n\nZawartosc tablicy pzed sortowaniem:\n\n ");
	for(i = 0; i < ilosc; i++) {
		printf("%3d  ", tablica[i]);
	}

	printf("\n\nSortowanie . . .");
	sortowaniePrzezWstawianie(tablica, ilosc);

	printf("\n\nZawartosc tablicy po sortowaniu:\n\n ");
	for(i = 0; i < ilosc; i++) {
		printf("%3d  ", tablica[i]);
	}


	printf("\n\n\n");
	system("pause");
	return 0;
}

void sortowaniePrzezWstawianie(int *tab, int rozmiar) {
	int i, j, k, tmp;

	for (i = 0; i < rozmiar; i++) {
		for (j = 0; j < i; j++) {
			if (tab[j] > tab[i]) {
				tmp = tab[i];
				for (k = i; k > j; k--) {
					tab[k] = tab[k - 1];
				}
				tab[j] = tmp;
				break;
			}
		}
	}
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
