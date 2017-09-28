#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double obliczWyznacznik(double *tablica, int rozmiar);

int liczbaLosowa(int min, int max);
int intScanf(char *komunikat);

int main(void) {

	int what, pierwszyWymiarMacierzy, drugiWymiarMacierzy, i, j, k, licznikWierszy, licznikKolumn;
	double *pierwszaMacierz, *drugaMacierz, *trzeciaMacierz, wyznacznik;

	do {
		what = 0;
		system("cls");
		printf("Podaj numer operacji do wykonania:\n");
		printf("\t1. Wyznaczyc macierz odwrotna do podanej.\n");
		printf("\t2. Pomnozyc dwie macierze.\n");
		printf("\t3. Dodac dwie macierze.\n");
		printf("\t4. Wykonac transpozycje wewnatrz podanej macierzy.\n");
		printf("\t5. Zakonczyc program!\n\n");

		do {
			what = intScanf("Wybrana operacja: ");
		}
		while((what < 1) || (what > 5));

		switch(what) {
			case 1:
				system("cls");
				printf("Wyznaczanie macierzy odwrotnej\n");
				printf("--------------------------------------------------------------------------------\n");

				printf("Macierz musi byc kwadratowa!\n");
				do {
					pierwszyWymiarMacierzy = intScanf("Podaj wymiar macierzy ( >0 ): ");
				}
				while(pierwszyWymiarMacierzy <= 0);

				pierwszaMacierz = new double[pierwszyWymiarMacierzy*pierwszyWymiarMacierzy];

				printf("\nWygenerowana macierz:\n\n");
				srand(time(0));
				for(i = 0; i < pierwszyWymiarMacierzy*pierwszyWymiarMacierzy; i++){
					pierwszaMacierz[i] = liczbaLosowa(1,11);
					printf(" %2.0f", pierwszaMacierz[i]);
					if((i+1)%pierwszyWymiarMacierzy == 0){
						printf("\n");
					}
				}

				wyznacznik = obliczWyznacznik(pierwszaMacierz, pierwszyWymiarMacierzy);
				printf("\nWyznacznik macierzy: %.0f\n", wyznacznik);

				/*printf("\nMacierz jednostkowa: \n");
				for(i = 0; i < pierwszyWymiarMacierzy*pierwszyWymiarMacierzy; i++){
					if(i%(pierwszyWymiarMacierzy + 1)) {
						0;
					}
					else {
						1;
					}
					printf(" %2.0f", ;
					if((i+1)%pierwszyWymiarMacierzy == 0){
						printf("\n");
					}
				}*/

				delete[] pierwszaMacierz;

				break;

			case 2:
				system("cls");
				printf("Mnozenie dwoch macierzy\n");
				printf("--------------------------------------------------------------------------------\n");

				break;

			case 3:
				system("cls");
				printf("Dodawanie dwoch macierzy\n");
				printf("--------------------------------------------------------------------------------\n");

				break;

			case 4:
				system("cls");
				printf("Transpozycja wewnatrz macierzy\n");
				printf("--------------------------------------------------------------------------------\n");

				break;

		}

		if(what != 5){
			system("pause");
		}

	}
	while(what != 5);

	return 0;
}

// http://forum.ks-ekspert.pl/index.php?showtopic=3190&st=0&p=21530&#entry21530
double obliczWyznacznik(double *tablica, int rozmiar) {
	int i, j, k;
	double wyznacznik = 1;
	
	for(i = 0; i < rozmiar - 1; i++) {
		for(j = i + 1; j < rozmiar; j++) {
			for(k = i + 1; k < rozmiar; k++) {
				tablica[j*rozmiar + k] -= tablica[j*rozmiar + i]/tablica[i*rozmiar + i]*tablica[i*rozmiar + k];
			}
		}
	}

	for(i = 0; i < rozmiar; i++) {
		wyznacznik *= tablica[i*rozmiar + i];
	}

	return wyznacznik;
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
