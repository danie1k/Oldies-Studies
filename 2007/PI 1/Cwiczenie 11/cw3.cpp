#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int liczbaLosowa(int min, int max);
void sortowanieBabelkowe(int *tab, int rozmiar);
void sortowaniePrzezWstawianie(int *tab, int rozmiar);
void sortowaniePrzezWybieranie(int *tab, int rozmiar);
int mniejsze(int x, int y);
int intScanf(char *komunikat);

int main(void) {
	int i, rozmiar, klawisz, *tablica;

	printf("Realizacja cwiczenia 11.3 i 11.4:\n");
	printf("[...]\n\n");

	rozmiar = intScanf("Okresl rozmiar tablicy na jakiej ma operowac program: ");

	tablica = new int[rozmiar];

	do {
		printf("\nWybierz jedna z ponizszych mozliwosci:\n");
		printf("  1. Program automatycznie wypelnia tablice.\n");
		printf("  2. Tablica jest wypelniana przez uzytkownika.\n");
		klawisz = intScanf("Podaj numer operacji: ");
		if((klawisz < 1) || (klawisz > 2)) {
			system("cls");
			printf("Wpisano nie rozpoznany znak, sproboj ponownie!\n");
			continue;
		}
	}
	while((klawisz < 1) || (klawisz > 2));

	switch(klawisz) {
		case 1:
			printf("\nAutomatyczne wypelnianie tablicy . . .\n");
			srand(time(0));
			for(i = 0; i < rozmiar; i++) {
				tablica[i] = liczbaLosowa(0, 1000);
			}
			break;

		case 2:
			printf("\nTablica wypelniana przez uzytkownika:\n");
			for(i = 0; i < rozmiar; i++) {
				tablica[i] = intScanf("  Podaj liczbe: ");
				//printf("Podaj %2d liczbe: ", (i + 1));
				//scanf("%d", &tablica[i]);
			}
			break;
	}


	do {
		printf("\nWybierz metode sortowania:\n");
		printf("  1. Sortowanie babelkowe.\n");
		printf("  2. Sortowanie przez wstawianie (\"karciane\").\n");
		printf("  3. Sortowanie przez wybieranie (\"proste\").\n\n");

		klawisz = intScanf("Podaj numer operacji: ");
		if((klawisz < 1) || (klawisz > 3)) {
			system("cls");
			printf("Wpisano nie rozpoznany znak, sproboj ponownie!\n");
			continue;
		}
	}
	while((klawisz < 1) || (klawisz > 3));

	system("cls");

	printf("\nZawartosc tablicy pzed sortowaniem:");
	printf("\n-----------------------------------\n\n ");
	for(i = 0; i < rozmiar; i++) {
		printf("%3d  ", tablica[i]);
	}

	switch(klawisz) {
		case 1:
			printf("\n\nSortowanie motoda babelkowa . . . ");
			sortowanieBabelkowe(tablica, rozmiar);

			printf("\n\nZawartosc tablicy po posortowaniu:\n");
			printf("----------------------------------\n\n ");
			for(i = 0; i < rozmiar; i++) {
				printf("%3d  ", tablica[i]);
			}

			break;

		case 2:
			printf("\n\nSortowanie przez wstawianie (\"karciane\") . . . ");
			sortowaniePrzezWstawianie(tablica, rozmiar);

			printf("\n\nZawartosc tablicy po posortowaniu:\n");
			printf("----------------------------------\n\n ");
			for(i = 0; i < rozmiar; i++) {
				printf("%3d  ", tablica[i]);
			}

			break;

		case 3:
			printf("\n\nSortowanie przez wybieranie (\"proste\") . . . ");
			sortowaniePrzezWybieranie(tablica, rozmiar);

			printf("\n\nZawartosc tablicy po posortowaniu:\n");
			printf("----------------------------------\n\n ");
			for(i = 0; i < rozmiar; i++) {
				printf("%3d  ", tablica[i]);
			}

			break;
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

void sortowaniePrzezWstawianie(int *tab, int rozmiar) {
	int i, j, k, tmp;

	for (i = 0; i < rozmiar; i++) {
		for(j = 0; j < i; j++) {
			if(tab[j] > tab[i]) {
				tmp = tab[i];
				for(k = i; k > j; k--) {
					tab[k] = tab[k - 1];
				}
				tab[j] = tmp;
				break;
			}
		}
	}
}

void sortowaniePrzezWybieranie(int *tab, int rozmiar) {
	int i, j, x, tmp;

	for(i = 0; i < (rozmiar - 1); i++) {
		tmp = i;
		for(j = i + 1; j < rozmiar; j++) {
			if(mniejsze(tab[j], tab[tmp])) {
				tmp = j;
			}
		}
		x = tab[tmp];
		tab[tmp] = tab[i];
		tab[i] = x;
	}
}

int mniejsze(int x, int y) {
	int ret;
	if(x < y) {
		ret = 1;
	}
	else {
		ret = 0;
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
