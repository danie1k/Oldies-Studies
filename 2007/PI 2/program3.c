#include <stdio.h>
#include <stdlib.h>

int liczbaLosowa(int min, int max);
int intScanf(char *komunikat);

int main(void) {

    int tablica[10][10], x = 0, y = 0, i, j, suma = 0, licznik = 0, sumaWierszy[10] = {0}, sumaKolumn[10] = {0}; 
    double srednia;   

    printf("\n  Program oblicza srednia liczb w komorkach,\n  ktorych iloczyn indeksow jest liczba nieparzysta.\n\n");
    
    do {
        x = intScanf("Podaj pierwszy wymiar tablicy (maks. 10): ");
    }
    while((x < 1) || (x > 10));

    do {
        y = intScanf("Podaj drugi wymiar tablicy (maks. 10): ");
    }
    while((y < 1) || (y> 10));

    printf("\n");

	// Wype³nianie tablicy liczbami pseudolosowymi
	srand(time(0));
	for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            tablica[i][j] = liczbaLosowa(0, 99);

            // Pobieranie liczb do obliczenia œredniej
            if((i*j)%2 != 0){
                suma += tablica[i][j];
                licznik++;
            }

            // Wyœwietlanie wygenerowanych wartoœci
            if((i*j)%2 != 0){
                printf("  [%2d]", tablica[i][j]);
            }
            else {
                printf("   %2d ", tablica[i][j]);
            }
            if(j == (y - 1)) printf("\n");
        }
	}

	// Obliczanie œredniej
	srednia = ((double)suma/(double)licznik);
    printf("\n\nSUMA: %d\nLICZNIK: %d\nSrednia arytmetyczna zadanych liczb wynosi: %.3f", suma, licznik, srednia);

	// Sumowanie wierszy
	for(i = 0; i < x; i++) {
		for(j = 0; j < y; j++) {
			sumaWierszy[i] += tablica[i][j];
		}
	}
	// Sumowanie kolumn
	for(j = y-1; j >= 0; j--) {
		for(i = x-1; i >= 0; i--) {
			sumaKolumn[j] += tablica[i][j];
		}
	}
	printf("\n\nSuma wierszy:\n");
	for(i = 0; i < x; i++) {
		printf("  wiersz %d : %d\n", (i + 1), sumaWierszy[i]);
	}
	printf("\nSuma kolumn:\n");
	for(j = 0; j < y; j++) {
		printf(" kolumna %d : %d\n", (j + 1), sumaKolumn[j]);
	}

    printf("\n\n");
	system("pause");
	return 0;
}

int liczbaLosowa(int min, int max) {
	return (int)((((double)rand()/RAND_MAX)*max) + min);
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
