#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortowanie (int*, int);

int wczytajPlik(const char*, int *, int); // Funkcja zwraca ilosc odczytanych liczb
void zapiszPlik(const char*, int *, int, int);

void najmniejszaLiczba(int*, int, int[]);

int main(void) {
	int KONIEC = 0, licznik, licznikb, i, j = 0, *dane3,
	    ile1, *dane1, *dane1b, najmniejszaLiczba1[2], // [0] -> liczba, [1] -> liczba wystapien
	    ile2, *dane2, *dane2b, najmniejszaLiczba2[2],
	    ileWynik, *daneWynik;
	const int odczytajMax = 50;
	const char *nazwaPliku1 = "dane1.txt", 
	           *nazwaPliku2 = "dane2.txt", 
	  *nazwaPlikuWynikowego = "danePosortowane.txt";
	FILE *plik1, *plik2, *plikWynikowy;

	dane1  = new int[odczytajMax];
	dane1b = new int[odczytajMax];
	dane2  = new int[odczytajMax];
	dane2b = new int[odczytajMax];
	dane3  = new int[odczytajMax*2];
	daneWynik  = new int[odczytajMax*2];

	system("cls");

	// PÊTLA PRZETWARZANIA
	while(!KONIEC) {
		// Zerowanie zmiennych
		ile1 = 0;
		ile2 = 0;
		licznik = 0;
		memset(dane1, 0, odczytajMax*sizeof(int)); 
		memset(dane1b, 0, odczytajMax*sizeof(int)); 
		memset(dane2, 0, odczytajMax*sizeof(int)); 
		memset(dane2b, 0, odczytajMax*sizeof(int)); 
		memset(dane3, 0, odczytajMax*2*sizeof(int)); 

		// Odczyt plików
		ile1 = wczytajPlik(nazwaPliku1, dane1, odczytajMax);
		ile2 = wczytajPlik(nazwaPliku2, dane2, odczytajMax);

		// Analiza pierwszego pliku
		if(ile1 > 0) {
			licznikb = 0;

			// Znajkdowanie najmniejszej liczby w pliku
			najmniejszaLiczba(dane1, ile1, najmniejszaLiczba1);
			//printf("PLIK1:\n liczba: %d\n wystapienia: %d\n", najmniejszaLiczba1[0], najmniejszaLiczba1[1]);

			// Sytuacja, gdy zostaja ostatnie liczby (liczba)
			if(najmniejszaLiczba1[1] == ile1) {
				//printf("Zostala ostatnia liczba: %d, ktora wystepuje %d razy", najmniejszaLiczba1[0], najmniejszaLiczba1[1]);
				for(i = 0; i < ile1; i++) {
					dane3[licznik++] = dane1[i];
				}
				zapiszPlik(nazwaPliku1, dane1b, 1, 0);
			}
			else {
				for(i = 0; i < ile1; i++) {
					if(dane1[i] != najmniejszaLiczba1[0]) {
						dane1b[licznikb++] = dane1[i];
					}
					else {
						dane3[licznik++] = dane1[i];
					}
				}
			}

			zapiszPlik(nazwaPliku1, dane1b, licznikb, 0);
		}
		else if(ile1 == 1) {
			licznikb = 0;
			dane3[licznik++] = dane1[i];
		}

		// Analiza drugiego pliku
		if(ile2 > 0) {
			licznikb = 0;

			// Znajkdowanie najmniejszej liczby w pliku
			najmniejszaLiczba(dane2, ile2, najmniejszaLiczba2);
			//printf("\n\nPLIK2:\n liczba: %d\n wystapienia: %d\n", najmniejszaLiczba2[0], najmniejszaLiczba2[1]);

			// Sytuacja, gdy zostaja ostatnie liczby (liczba)
			if(najmniejszaLiczba2[1] == ile2) {
				//printf("Zostala ostatnia liczba: %d, ktora wystepuje %d razy", najmniejszaLiczba2[0], najmniejszaLiczba2[1]);
				for(i = 0; i < ile2; i++) {
					dane3[licznik++] = dane2[i];
				}
				zapiszPlik(nazwaPliku2, dane2b, 1, 0);
			}
			else {
				for(i = 0; i < ile2; i++) {
					if(dane2[i] != najmniejszaLiczba2[0]) {
						dane2b[licznikb++] = dane2[i];
					}
					else {
						dane3[licznik++] = dane2[i];
					}
				}
		}

			zapiszPlik(nazwaPliku2, dane2b, licznikb, 0);
		}

		// Ostatnie przetwarzanie plikow, gdy zostaje w nich po jednej liczbie if(ile2 == 0) {

		// Przetwarzanie pliku wynikowego
		if((ile1 > 0) || (ile2 > 0)) {
			sortowanie(dane3, licznik);
		}
		else {
			// Sortowanie koncowe pliku wynikowego
			ileWynik = wczytajPlik(nazwaPlikuWynikowego, daneWynik, odczytajMax);
			sortowanie(daneWynik, ileWynik);
			zapiszPlik(nazwaPlikuWynikowego, daneWynik, ileWynik, 0);

			KONIEC = 1;
			break; // Jesli w plikach danych sa tylko pojedyncze zera ptogram od razu konczy dzialanie
		}

		zapiszPlik(nazwaPlikuWynikowego, dane3, licznik, 1);

		printf("Przetwarzanie . . . [%d]\n", ++j);
		system("pause");
		system("cls");
	}

	printf("Koniec programu!\n");
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
		printf("Wskazany plik (%s) nie istnieje!\n", nazwaPliku);
		system("pause");
		exit(1);
	}
    
	while (!feof(plik)) {
		if(licznik >= maxSize) {
			printf("Pelny odczyt pliku niemozliwy! Plik ma wiecej danych niz program moze odczytac!\n");
			system("pause");
			exit(1);
		}

		fscanf(plik, "%d ", &tablicaWynikow[licznik]);
		licznik++;
	}

	/*for(i = 0; i < licznik; i++){
		printf("tablicaWynikow[%d] = %d\n", i, tablicaWynikow[i]);
	}*/

	// Gdy zostalo jedno zero w pliku
	if((licznik == 1) && (tablicaWynikow[0] == 0)) {
		licznik = 0;
	}

	fclose(plik);
	return licznik;
}

void zapiszPlik(const char *nazwaPliku, int *input, int size, int tryb) {
    FILE *plik;
	int i;
	char temp[5], *tekstWynikowy;

    tekstWynikowy = new char[size*2];

	memset(tekstWynikowy, 0, size*2*sizeof(char)); 

	//printf("\n\nDo pliku '%s' zapisuje dane: ", nazwaPliku);
	for(i = 0; i < size; i++) {
		//sprintf(temp, "%d ", input[i]);
		//strcat(tekstWynikowy, temp);
    	if(tryb == 1) { // Tylko dopisywanie
			plik = fopen(nazwaPliku, "a");
		}
		else {
			plik = (i == 0) ? fopen(nazwaPliku, "w") : fopen(nazwaPliku, "a");
		}
		fprintf(plik, "%d ", input[i]);
		//printf("%d ", input[i]);
		fclose(plik);
	}

}

void najmniejszaLiczba(int *tablica, int rozmiar, int wartosci[]) {
	int i, temp, licznik = 0;

	temp = tablica[0];
	//printf("\n\ntemp = %d\n\n", temp);

	for(i = 0; i < rozmiar; i++) {
		//printf(" tablica[%d] = %d\n", i, tablica[i]);
		if(tablica[i] < temp) {
			temp = tablica[i];
		}
	}
	
	for(i = 0; i < rozmiar; i++) {
		if(temp == tablica[i]) {
			licznik++;
		}
	}
	
	wartosci[0] = temp;
	wartosci[1] = licznik;
}
