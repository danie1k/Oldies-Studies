#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double obliczWyznacznik(double *tablica, int rozmiar);
double sumujMacierze(double *tablica1, double *tablica2, double *tablicaWynikow, int rozmiar1, int rozmiar2);
void pomnozMacierze(double *tablica1, double *tablica2, double *tablicaWynikow, int rozmiar1, int rozmiar2, int rozmiar3);
void transpozycja(double *tablica, int rozmiar1, int rozmiar2);

void saveFile(const char *nazwaPliku, const char *mode, char *input);

int liczbaLosowa(int min, int max);
int intScanf(char *komunikat);

int main(void) {

	int what, pierwszyWymiarMacierzy, drugiWymiarMacierzy, wymiarPomocniczy, i, j, k;
	double *pierwszaMacierz, *drugaMacierz, *trzeciaMacierz, wyznacznik;
	char tekst[2000];
	const char nazwaPliku[] = "PLIK.txt";

	do {
		what = 0;
		system("cls");
		printf("Podaj numer operacji do wykonania:\n");
		printf("\t1. Wyznaczyc macierz odwrotna. [tylko wyznacznik]\n");
		printf("\t2. Pomnozyc dwie macierze. [ok]\n");
		printf("\t3. Dodac dwie macierze. [ok]\n");
		printf("\t4. Wykonac transpozycje macierzy. [ok]\n");
		printf("\t5. Zakonczyc program!\n\n");

		do {
			what = intScanf("Wybrana operacja: ");
		}
		while((what < 1) || (what > 5));

		switch(what) {
			case 1:
				system("cls");
				sprintf(tekst, "Wyznaczanie macierzy odwrotnej\n--------------------------------------------------------------------------------\n");
				printf("%s", tekst);
				saveFile(nazwaPliku, "w+", tekst);

				printf("Macierz musi byc kwadratowa!\n");
				do {
					pierwszyWymiarMacierzy = intScanf("Podaj wymiar macierzy ( >0 ): ");
				}
				while(pierwszyWymiarMacierzy <=0);

				pierwszaMacierz = new double[pierwszyWymiarMacierzy*pierwszyWymiarMacierzy];

				printf("\nWygenerowana macierz:\n\n");
				saveFile(nazwaPliku, "a", "\nMacierz:\n\n");
				srand(time(0));
				for(i = 0; i < pierwszyWymiarMacierzy*pierwszyWymiarMacierzy; i++){
					pierwszaMacierz[i] = liczbaLosowa(1,11);
					sprintf(tekst, " %2.0f", pierwszaMacierz[i]);
					printf("%s", tekst);
					saveFile(nazwaPliku, "a", tekst);

					if((i+1)%pierwszyWymiarMacierzy == 0){
						printf("\n", tekst);
						saveFile(nazwaPliku, "a", "\n");
					}
				}

				sprintf(tekst, "\nWyznacznik macierzy: %.0f\n", wyznacznik = obliczWyznacznik(pierwszaMacierz, pierwszyWymiarMacierzy));
				printf("%s", tekst);

				saveFile(nazwaPliku, "a", tekst);

				/*
				 *
				 */

				delete[] pierwszaMacierz;

				break;

			case 2:
				system("cls");
				sprintf(tekst, "Mnozenie dwoch macierzy\n--------------------------------------------------------------------------------\n");
				printf("%s", tekst);
				saveFile(nazwaPliku, "w+", tekst);

				printf("Drugi wymiar pierwszej macierzy musi byc taki sam,\n");
				printf("jak pierwszy wymiar drugiej macierzy!\n");
				do {
					pierwszyWymiarMacierzy = intScanf("Podaj pierwszy wymiar pierwszej macierzy ( >0 ): ");
				}
				while(pierwszyWymiarMacierzy <=0);
				do {
					drugiWymiarMacierzy = intScanf("Podaj drugi    wymiar pierwszej macierzy ( >0 ): ");
				}
				while(drugiWymiarMacierzy <=0);

				pierwszaMacierz = new double[pierwszyWymiarMacierzy*drugiWymiarMacierzy];

				do {
					wymiarPomocniczy = intScanf("Podaj drugi    wymiar drugiej   macierzy ( >0 ): ");
				}
				while(wymiarPomocniczy <=0);

				drugaMacierz = new double[drugiWymiarMacierzy*wymiarPomocniczy];

				trzeciaMacierz = new double[pierwszyWymiarMacierzy*wymiarPomocniczy];
				for(i = 0; i < pierwszyWymiarMacierzy*wymiarPomocniczy; i++) {
					trzeciaMacierz[i] = 0;
				}

				srand(time(0));

				printf("\nWygenerowana 1 macierz:\n\n");
				saveFile(nazwaPliku, "a", "\nPierwsza macierz:\n\n");
				for(i = 0; i < pierwszyWymiarMacierzy*drugiWymiarMacierzy; i++){
					pierwszaMacierz[i] = liczbaLosowa(1,11);
					sprintf(tekst, " %2.0f", pierwszaMacierz[i]);
					printf("%s", tekst);
					saveFile(nazwaPliku, "a", tekst);
					if((i+1)%drugiWymiarMacierzy == 0){
						printf("\n");
						saveFile(nazwaPliku, "a", "\n");
					}
				}
				printf("\nWygenerowana 2 macierz:\n\n");
				saveFile(nazwaPliku, "a", "\nDruga macierz:\n\n");
				for(i = 0; i < drugiWymiarMacierzy*wymiarPomocniczy; i++){
					drugaMacierz[i] = liczbaLosowa(1,11);
					sprintf(tekst, " %2.0f", drugaMacierz[i]);
					printf("%s", tekst);
					saveFile(nazwaPliku, "a", tekst);
					if((i+1)%wymiarPomocniczy == 0){
						printf("\n");
						saveFile(nazwaPliku, "a", "\n");
					}
				}

				pomnozMacierze(pierwszaMacierz, drugaMacierz, trzeciaMacierz, pierwszyWymiarMacierzy, drugiWymiarMacierzy, wymiarPomocniczy);

				printf("\nMacierze pomnozone:\n\n");
				saveFile(nazwaPliku, "a", "\n\nMacierze pomnozone:\n\n");
				for(i = 0; i < pierwszyWymiarMacierzy*wymiarPomocniczy; i++){
					sprintf(tekst, " %3.0f", trzeciaMacierz[i]);
					printf("%s", tekst);
					saveFile(nazwaPliku, "a", tekst);
					if((i+1)%wymiarPomocniczy == 0){
						printf("\n");
						saveFile(nazwaPliku, "a", "\n");
					}
				}

				delete[] pierwszaMacierz, drugaMacierz, trzeciaMacierz;

				break;

			case 3:
				system("cls");
				printf("Dodawanie dwoch macierzy\n");
				printf("--------------------------------------------------------------------------------\n");

				printf("Macierze musza miec ten sam rozmiar!\n");
				do {
					pierwszyWymiarMacierzy = intScanf("Podaj pierwszy wymiar macierzy ( >0 ): ");
				}
				while(pierwszyWymiarMacierzy <=0);
				do {
					drugiWymiarMacierzy = intScanf("Podaj drugi    wymiar macierzy ( >0 ): ");
				}
				while(drugiWymiarMacierzy <=0);

				pierwszaMacierz = new double[pierwszyWymiarMacierzy*drugiWymiarMacierzy];
				drugaMacierz = new double[pierwszyWymiarMacierzy*drugiWymiarMacierzy];
				trzeciaMacierz = new double[pierwszyWymiarMacierzy*drugiWymiarMacierzy];

				srand(time(0));

				printf("\nWygenerowana 1 macierz:\n\n");
				for(i = 0; i < pierwszyWymiarMacierzy*drugiWymiarMacierzy; i++){
					pierwszaMacierz[i] = liczbaLosowa(1,11);
					printf(" %2.0f", pierwszaMacierz[i]);
					if((i+1)%drugiWymiarMacierzy == 0){
						printf("\n");
					}
				}
				printf("\nWygenerowana 2 macierz:\n\n");
				for(i = 0; i < pierwszyWymiarMacierzy*drugiWymiarMacierzy; i++){
					drugaMacierz[i] = liczbaLosowa(1,11);
					printf(" %2.0f", drugaMacierz[i]);
					if((i+1)%drugiWymiarMacierzy == 0){
						printf("\n");
					}
				}

				sumujMacierze(pierwszaMacierz, drugaMacierz, trzeciaMacierz, pierwszyWymiarMacierzy, drugiWymiarMacierzy);

				printf("\nSuma macierzy:\n\n");
				for(i = 0; i < pierwszyWymiarMacierzy*drugiWymiarMacierzy; i++){
					printf(" %2.0f", trzeciaMacierz[i]);
					if((i+1)%drugiWymiarMacierzy == 0){
						printf("\n");
					}
				}

				delete[] pierwszaMacierz, drugaMacierz, trzeciaMacierz;

				break;

			case 4:
				system("cls");
				printf("Transpozycja macierzy\n");
				printf("--------------------------------------------------------------------------------\n");

				do {
					pierwszyWymiarMacierzy = intScanf("Podaj pierwszy wymiar macierzy ( >0 ): ");
				}
				while(pierwszyWymiarMacierzy <=0);
				do {
					drugiWymiarMacierzy = intScanf("Podaj drugi    wymiar macierzy ( >0 ): ");
				}
				while(drugiWymiarMacierzy <=0);

				pierwszaMacierz = new double[pierwszyWymiarMacierzy*drugiWymiarMacierzy];
				drugaMacierz = new double[pierwszyWymiarMacierzy*drugiWymiarMacierzy];

				srand(time(0));
				printf("\nWygenerowana macierz:\n\n");
				for(i = 0; i < pierwszyWymiarMacierzy*drugiWymiarMacierzy; i++){
					pierwszaMacierz[i] = liczbaLosowa(1,11);
					printf(" %2.0f", pierwszaMacierz[i]);
					if((i+1)%drugiWymiarMacierzy == 0){
						printf("\n");
					}
				}

				transpozycja(pierwszaMacierz, pierwszyWymiarMacierzy, drugiWymiarMacierzy);

				printf("\nPrzetransponowana macierz:\n\n");
				for(i = 0; i < pierwszyWymiarMacierzy*drugiWymiarMacierzy; i++){
					printf(" %2.0f", pierwszaMacierz[i]);
					if((i+1)%pierwszyWymiarMacierzy == 0){
						printf("\n");
					}
				}

				delete[] pierwszaMacierz, drugaMacierz;

				break;

		}

		if(what != 5){
			system("pause");
		}

	}
	while(what != 5);

	return 0;
}

double obliczWyznacznik(double *tablica, int rozmiar) {
	int i, j, k;
	double wyznacznik = 1;

	for(i = 0; i < rozmiar - 1; i++) {
		for(j = i + 1; j < rozmiar; j++) {
			for(k = i + 1; k < rozmiar; k++) {
				tablica[j*rozmiar + k] -= tablica[j*rozmiar + i] / tablica[i*rozmiar + i] * tablica[i*rozmiar + k];
			}
		}
	}

	for(i = 0; i < rozmiar; i++) {
		wyznacznik *= tablica[i*rozmiar+i];
	}

	return wyznacznik;
}

double sumujMacierze(double *tablica1, double *tablica2, double *tablicaWynikow, int rozmiar1, int rozmiar2) {
	int i;

	for(i = 0; i < rozmiar1*rozmiar2; i++) {
		tablicaWynikow[i] = tablica1[i] + tablica2[i];
	}
}

void pomnozMacierze(double *tablica1, double *tablica2, double *tablicaWynikow, int rozmiar1, int rozmiar2, int rozmiar3) {
	int i, j, k;

	for(i = 0; i < rozmiar1; i++) {
		for(j = 0; j < rozmiar3; j++) {
			for(k = 0; k < rozmiar2; k++) {
				tablicaWynikow[i*rozmiar3 + j] += tablica1[i*rozmiar2 + k] * tablica2[k*rozmiar3 + j];
			}
		}
	}
}

void transpozycja(double *tablica, int rozmiar1, int rozmiar2) {
	int i, j, licznik = 0;
	double *tablicaWynikowa;

	tablicaWynikowa = new double[rozmiar1*rozmiar2];

	for(i = 0; i < rozmiar2; i++){
		for(j = 0; j <= (rozmiar1*rozmiar2 - rozmiar2); j += rozmiar2) {
			tablicaWynikowa[licznik++] = tablica[j+i];
		}
	}

	while(*tablica++ = *tablicaWynikowa++);
	
	delete[] tablicaWynikowa;
}


void saveFile(const char *nazwaPliku, const char *mode, char *input) {
	int temp;
	FILE *plik;

	/*printf("\n");
	do {
		temp  = intScanf("Czy chcesz zapisac wynik do pliku (1 - tak, 2 - nie)? ");
	}
	while((temp != 1) && (temp != 2));

	if(temp == 1) {*/

		if (!(plik = fopen(nazwaPliku, mode))) {
			//printf ("Nie mozna otworzyc pliku!\n");
		}
		if(fprintf(plik, "%s", input)) {
			//printf("Plik zapisany.\n");
		}
		else {
			//printf ("Nie mozna zapisac pliku!\n");
		}
		fclose(plik);
	//}
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
