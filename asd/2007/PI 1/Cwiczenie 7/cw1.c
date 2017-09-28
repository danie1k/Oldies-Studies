#include <stdio.h>
#include <stdlib.h>

int intScanf(char *komunikat);

int main(void) {
	float liczba, suma = 0;
	char tablica[9][3][50];
	int i, j, n;

	printf("Realizacja cwiczenia 7.1:\n");
	printf("Program wczytuje do tablicy imiona, nazwiska i miejsca zamieszkania studentow,\n");
	printf("a nastepnie drukuje zawartosc tablicy na ekranie w trzech kolumnach\n\n");

	do {
		n = intScanf("Podaj ilosc studentow n (n < 10): ");
		if(n >= 10) {
			printf("\nPodana wartosc jest za duza, sproboj ponownie!\n  ");
		}
	}
	while(n >= 10);

	for(i = 0; i < n; i++) {
		printf("\nPodaj dane %d studenta:\n", i + 1);
		printf(" imie: ");
		scanf("%s", &tablica[0][i]);
		printf(" nazwisko: ");
		scanf("%s", &tablica[1][i]);
		printf(" m-ce zamieszkania: ");
		scanf("%s", &tablica[2][i]);
	}

	printf("\n\n   +---------------------+---------------------+---------------------+\n");
	    printf("   |                Imie |            Nazwisko |   M-ce zamieszkania |\n");
	    printf("   +---------------------+---------------------+---------------------+\n");
	for(i=0; i<n; i++) {
		printf("|");
		for(j=0; j<3; j++) {
			printf(" %19s |", tablica[j][i]);
		}
		printf("\n");
	}
	    printf("   +---------------------+---------------------+---------------------+\n\n");

	system("pause");
	return 0;
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
