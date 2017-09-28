#include <stdio.h>
#include <stdlib.h>

#define WIELKOSC_TABLICY 100

int liczbaLosowa(int min, int max);
void sortowanieBabelkowe(int *tab, int rozmiar);

int main(void) {
	int i, tablica[WIELKOSC_TABLICY];

	printf("Realizacja cwiczenia 11.1:\n");
	printf("Program wypelnia tablice 100 elementowa losowymi liczbami <0; 1000>");
	printf("\na nastepnie sortuje je metoda bobelkowa.\n\n");

	//printf("Wypelnianie tablicy . . .\n\n");
	srand(time(0));
	for(i = 0; i < WIELKOSC_TABLICY; i++) {
		tablica[i] = liczbaLosowa(0, 1000);
	}

	printf("Zawartosc tablicy pzed sortowaniem:\n\n ");
	for(i = 0; i < WIELKOSC_TABLICY; i++) {
		printf("%3d  ", tablica[i]);
	}

	//printf("\n\nSortowanie motoda babelkowa . . . ");
	sortowanieBabelkowe(tablica, WIELKOSC_TABLICY);

	printf("\n\nZawartosc tablicy po posortowaniu:\n\n ");
	for(i = 0; i < WIELKOSC_TABLICY; i++) {
		printf("%3d  ", tablica[i]);
	}

	printf("\n\n");
	system("pause");
	return 0;
}

int liczbaLosowa(int min, int max) {
	return (int)((((double)rand()/RAND_MAX)*max) + min);
}

void sortowanieBabelkowe(int *tab, int rozmiar) {
	int i, j, tmp;

	for (i = 0; i < rozmiar; i++) {
		for (j = 0; j < (rozmiar - 1); j++) {
			if (tab[j] > tab[j + 1]) {
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}
