#include <stdio.h>
#include <stdlib.h>

int pierwsze(int *tablica, int poczatek, int koniec);
int intScanf(char *komunikat);

int main(void) {
	int a, b, tmp, klawisz, 
	    *liczbyPierwsze, *liczbyBlizniacze;

	printf("Realizacja cwiczenia 9.3:\n");
	printf("[...]\n\n");

	printf("Podaj przedzial liczb naturanlnych na jakim ma dzialac program:\n");
	do {
		a = intScanf(" a: ");
	}
	while(a <= 0);
	do {
		b = intScanf(" b: ");
	}
	while(b <= 0);
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	printf("\n");
	system("pause");
	system("cls");

	do {
		printf("Co ma wykonac program?\n");
		printf("  1. Wyznaczyc wszystkie liczby pierwsze w przedziale <%d; %d>.\n", a, b);
		printf("  2. Wyznaczyc liczby blizniacze w przedziale <%d; %d>.\n", a, b);
		printf("  3. Sprawdzic hipoteze Goldbacha w przedziale <%d; %d>.\n", a, b);
		printf("  4. Zakonczyc prace.\n\n", a, b);
		klawisz = intScanf("Podaj numer operacji: ");
		if((klawisz < 1) || (klawisz > 4)) {
			system("cls");
			printf("Wpisano nie rozpoznany znak, sproboj ponownie!\n");
			continue;
		}
	}
	while((klawisz < 1) || (klawisz > 4));

	system("cls");

	switch(klawisz) {
		case 1:
			printf("Wyznaczane liczb pierwszych . . .\n\n");
			liczbyPierwsze = new int*[b - a];
			pierwsze(*liczbyPierwsze, a, b);
			printf("Liczby pierwsze w przedziale: <%d; %d> to: \n", a, b);
			break;

		/*case 2:
			break;

		default:
			break;*/
	}

	system("pause");
	return 0;
}

int pierwsze(int *tablica, int poczatek, int koniec) {
	int liczba, i, licznikPierwszych = 0;

	for(liczba = poczatek; liczba <= koniec; liczba++) {
		for(i = 2; i < liczba; i++) {
			if(liczba%i != 0) {
				*(tablica + licznikPierwszych) = liczba;
				licznikPierwszych++;
			}
		}
	}

	return licznikPierwszych;
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
