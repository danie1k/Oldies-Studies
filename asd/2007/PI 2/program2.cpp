#include <stdio.h>
#include <stdlib.h>

void NWDodejmowanie(int liczba1, int liczba2, int &licznik, int &wynik);
void NWDdzielenie(int liczba1, int liczba2, int &licznik, int &wynik);

int pierwsza(int liczba);
int intScanf(char *komunikat);

int main(void) {

	int pierwszaLiczba, drugaLiczba, temp,
	    wynikOdejmowanie = 0, licznikOdejmowanie = 0,
	    wynikDzelenie = 0, licznikDzelenie = 0;

	pierwszaLiczba = intScanf("Podaj pierwsza liczbe: ");
	drugaLiczba = intScanf("Podaj druga liczbe: ");

	if(pierwszaLiczba == drugaLiczba) {
		printf("\nPodane liczby sa rowne, program konczy dzialanie!");
	}
	else {

		if(pierwszaLiczba > drugaLiczba) {
			printf("\nPierwsza liczba jest wieksza od drugiej, zamienianie kolejnosci!\n\n");
			temp = drugaLiczba;
			drugaLiczba = pierwszaLiczba;
			pierwszaLiczba = temp;
		}

		if(pierwsza(pierwszaLiczba) && pierwsza(drugaLiczba)) {
			printf("Podane liczby to liczby pierwsze, zatem ich najwiekszy wspolny dzielnik to 1.");
		}
		else {
			

			NWDodejmowanie(pierwszaLiczba, drugaLiczba, licznikOdejmowanie, wynikOdejmowanie);
			NWDdzielenie(pierwszaLiczba, drugaLiczba, licznikDzelenie, wynikDzelenie);

			printf("Podstawowa wersja algorytmu Euklidesa (roznica liczb)\n");
			printf("NWD: %d Liczba krokow: %d \n\n", wynikOdejmowanie, licznikOdejmowanie);

			printf("Zoptymalizowana wersja algorytmu Euklidesa (reszta z dzielenia)\n");
			printf("NWD: %d Liczba krokow: %d ", wynikDzelenie, licznikDzelenie);

		}

	}

	printf("\n\n");
	system("pause");
	return 0;
}


void NWDodejmowanie(int liczba1, int liczba2, int &licznik, int &wynik){
	while (liczba1 != liczba2) {
		++licznik;
		if (liczba1 > liczba2) {
			liczba1 = liczba1 - liczba2;
			printf("%d. liczba1 = %d\n", liczba1, licznik);
		}
		else {
			liczba2 = liczba2 - liczba1;
			printf("%d. liczba2 = %d\n", liczba2, licznik);
		}
	}
	wynik = liczba1;
}

void NWDdzielenie(int liczba1, int liczba2, int &licznik, int &wynik) {
	int temp;

	while (liczba2 != 0) {
		++licznik;
		temp = liczba1%liczba2;
		liczba1 = liczba2;
		liczba2 = temp;
	}
	wynik = liczba1;
}


int pierwsza(int liczba) {
	int i, ret = 1;

	for(i = 2; i < liczba; i++) {
		if(liczba%i == 0) {
			ret = 0;
		}
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
