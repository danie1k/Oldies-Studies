#include <stdio.h>
#include <stdlib.h>

#define IL_LICZB_P 13

int main(void) {
	int i, j, k, znalezione[IL_LICZB_P*2], licznik = 0, wyswietl, 
	    liczbyPierwsze[IL_LICZB_P] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

	printf("Realizacja cwiczenia 9.2:\n");
	printf(" Program sprawdza hipoteze Goldbacha, ktora mowi, ze kazda liczbe parzysta\n");
	printf(" wieksza od 2 mozna przedstawic za pomoca sumy dwoch liczb pierwszych.\n\n");
	printf("Program dziala na pierwszych dwudziestu liczbach parzystych wiekszych od 2.\n\n\n");
	system("pause");
	system("cls");

	for(i = 4; i <= 42; i += 2) {
		licznik = 0;
		printf("\nPrzetwarzana liczba parzysta:  [ %d ]\n", i);
		for(j = 0; j < IL_LICZB_P; j++) {
			for(k = 0; k < IL_LICZB_P; k++) {
				if(liczbyPierwsze[j] + liczbyPierwsze[k] == i) {
					//printf("%d i %d, ", liczbyPierwsze[j], liczbyPierwsze[k]);
					znalezione[licznik++] = liczbyPierwsze[j];
					znalezione[licznik++] = liczbyPierwsze[k];
					break;
				}
			}
		}

		// Okreœlanie liczby wyœwietlanych liczb pierwszych
		// Bez tego pary bêd¹ wyœwietlane podwójnie, np. /7 i 3/ oraz /3 i 7/
		if((licznik%2 == 0) && (licznik > 2)) {
			if((licznik/2)%2 != 0) {
				wyswietl = (licznik/2) + 1;
			}
			else {
				wyswietl = licznik/2;
			}
		}
		else {
			wyswietl = licznik;
		}

		printf(" %c Ta liczbe mozna utworzyc przez zsumowanie nastepujacych liczb pierwszych:\n %c ", 179, 179, 179, 179);
		for(j = 0; j < wyswietl; j += 2) {
			printf("[ %d + %d ]   ", znalezione[j], znalezione[j+1]);
		}

		printf("\n");
		if(((i - 2)%10 == 0)) {
			printf("\n\n");
			if(i == 42) {
				printf("KONIEC.");
			}
			printf("\n");
			system("pause");
			system("cls");
		}
	}

	return 0;
}
