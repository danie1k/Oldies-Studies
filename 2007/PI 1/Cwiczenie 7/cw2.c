#include <stdio.h>
#include <stdlib.h>

int liczbaLosowa(void);

int main(void) {
	int wiersze, kolumny, i, j, tablica[20][20], sumaWierszy[20] = {0}, sumaKolumn[20] = {0};

	printf("Realizacja cwiczenia 7.2:\n");
	printf("Program wczytuje do tablicy imiona, nazwiska i miejsca zamieszkania studentow,\n");
	printf("a nastepnie drukuje zawartosc tablicy na ekranie w trzech kolumnach\n\n");

	do {
		printf("Podaj wymiary macierzy:\n");
		printf(" wiersze ( < 20): ");
		scanf("%d", &wiersze);
		printf(" kolumny ( < 20): ");
		scanf("%d", &kolumny);
	}
	while((wiersze < 1) || (wiersze > 20) || (kolumny < 1) || (kolumny > 20));

	/*for(i = 0; i < wiersze; i++) {
		for(j = 0; j < kolumny; j++) {
			printf("Podaj wartosc elementu [%d,%d]: ", i + 1, j + 1);
			scanf("%f", &tablica[i][j]);
		}
	}*/

	// Wype³nianie tablicy
	for(i = 0; i < wiersze; i++) {
		for(j = 0; j < kolumny; j++) {
			tablica[i][j] = liczbaLosowa();
		}
	}

	printf("\n");
	system("pause");
	system("cls");

	// Sumowanie wierszy
	for(i = 0; i < wiersze; i++) {
		for(j = 0; j < kolumny; j++) {
			sumaWierszy[i] += tablica[i][j];
		}
	}
	// Sumowanie kolumn
	for(j = kolumny-1; j >= 0; j--) {
		for(i = wiersze-1; i >= 0; i--) {
			sumaKolumn[j] += tablica[i][j];
		}
	}

	// Drukowanie zawartoœci tablicy
	for(i = 0; i < wiersze; i++) {
		printf("\n");
		for(j = 0; j < kolumny; j++) {
			printf(" %2d ", tablica[i][j]);
		}
		printf("\n");
	}

	printf("\nSuma wierszy:\n");
	for(i = 0; i < wiersze; i++) {
		printf("  wiersz %d : %d\n", (i + 1), sumaWierszy[i]);
	}

	printf("\nSuma kolumn:\n");
	for(j = 0; j < kolumny; j++) {
		printf(" kolumna %d : %d\n", (j + 1), sumaKolumn[j]);
	}

	printf("\n");
	system("pause");
	return 0;
}

int liczbaLosowa(void) {
	int iMin = 0;
	int iMax = 99;
	return ((((double)rand()/RAND_MAX)*iMax) + iMin);
}
