#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortowanie (int*, int);

// Funkcja zwraca ilosc odczytanych liczb
int wczytajPlik(const char *, int *, int);
void zapiszPlik(const char *, int *, int);


int main(void) {
	int *tablica, ile;
	const int odczytajMax = 50;
	tablica = new int[odczytajMax];

	printf("Odczyt pliku... ");

	ile = wczytajPlik("dane.txt", tablica, odczytajMax);

	printf(" Sukces!\n\nIlosc wczytanych liczb: %d\n\nSortowanie... ", ile);

	sortowanie(tablica, ile);

	printf("Sukces!\n\nZapisywanie nowego pliku...");

	zapiszPlik("danePosortowane.txt", tablica, ile);
	
	printf("Sukces!");

	printf("\n\n");
	system("pause");
	return 0;
}


void sortowanie (int *tablica, int rozmiar) {
	int i, j, tmp;

	for(i = 0; i < rozmiar; i++) {
		for(j = 1; j < rozmiar; j++) {
			if(tablica[j] < tablica[j-1]) {
				tmp = tablica[j-1];
				tablica[j-1] = tablica[j];
				tablica[j] = tmp;
			}
		}
	}
}

int wczytajPlik(const char *nazwaPliku, int *tablicaWynikow, int maxSize) {
	FILE *plik;
	int licznik = 0, i;

	if(!(plik = fopen(nazwaPliku, "r"))) {
		printf("\nWskazany plik nie istnieje!\n");
		system("pause");
		exit(1);
	}
    
	while (!feof(plik)) {
		if(licznik >= maxSize) {
			printf("\nPelny odczyt pliku niemozliwy! Plik ma wiecej danych niz program moze odczytac!\n");
			system("pause");
			exit(1);
		}

		fscanf(plik, "%d", &tablicaWynikow[licznik]);
		licznik++;
	}

	fclose(plik);
	return licznik;
}

void zapiszPlik(const char *nazwaPliku, int *input, int size) {
    FILE *plik;
	int i;
    
    plik = fopen(nazwaPliku, "w");

	for(i = 0; i < size; i++) {
    	plik = (i == 0) ? fopen(nazwaPliku, "w") : fopen(nazwaPliku, "a");
		fprintf(plik, "%d ", input[i]);
		fclose(plik);
	}
}
