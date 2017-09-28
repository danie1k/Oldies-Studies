#include <stdio.h>
#include <stdlib.h>

int pierwsza(int liczba);
int intScanf(char *komunikat);

int main(void) {
	int a, b, i, j, k, l, tmp, klawisz, 
	    *liczbyPierwsze, licznikP = 0, **liczbyBlizniacze, *hipotezaG, licznikG, licznik = 0;

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
			printf("Wyznaczanie liczb pierwszych . . .\n\n");
			liczbyPierwsze = new int[b - a];
			for(i = 0; i <= (b - a); i++) {
				if(pierwsza(a + i)) {
					*(liczbyPierwsze + licznikP) = a + i;
					licznikP++;
				}
			}
			printf("Liczby pierwsze w przedziale: <%d; %d> to:\n  ", a, b);
			for(i = 0; i < licznikP; i++) {
				printf("%d, ", *(liczbyPierwsze + i));
			}
			printf("\n\n");
			system("pause");
			break;

		case 2:
			printf("Wyznaczane liczb blizniaczych . . .\n\n");
			liczbyBlizniacze = new int*[b - a];
			for (i = 0; i <= (b - a); i++) {
				liczbyBlizniacze[i] = new int[2];
			}
			for(i = a; i <= b; i++) {
				if(pierwsza(i) && pierwsza(i + 2)) {
					//printf("Liczby blizniacze: %d i %d\n", i, i + 2);
					*(*(liczbyBlizniacze + licznik) + 0) = i;
					*(*(liczbyBlizniacze + licznik) + 1) = i + 2;
					licznik++;
					i += 2;
				}
			}
			printf("Liczby blizniacze w przedziale: <%d; %d> to:\n\n", a, b);
			for(i = 0; i < licznik; i++) {
				printf(" %3d i %-3d\n", *(*(liczbyBlizniacze + i)), *(*(liczbyBlizniacze + i) +1 ));
			}
			printf("\n\n");
			system("pause");
			break;

		case 3:
			printf("Sprawdzanie hipotezy Goldbacha . . .\n\n");
			printf(" 1. Wyznaczane porzebnych liczb pierwszych . . .\n");
			liczbyPierwsze = new int[b - a];
			hipotezaG = new int[(b - a)*2];
			for(i = 2; i <= (b - a); i++) {
				if(pierwsza(i)) {
					*(liczbyPierwsze + licznikP) = i;
					licznikP++;
				}
			}
			printf("    Liczby pierwsze w przedziale: <%d; %d> to:\n    ", a, b);
			for(i = 0; i < licznikP; i++) {
				printf("%d, ", *(liczbyPierwsze + i));
			}

			printf("\n\n 2. Przetwarzanie liczb parzystych . . .");
			if(a < 4) {
				i = 4;
			}
			else if(a%2 != 0) {
				i = a + 1;
			}
			else {
				i = a;
			}
			if(b%2 != 0) {
				j = b - 1;
			}
			else {
				j = b;
			}
			for(i; i <= j; i += 2) {
				licznik = 0;
				printf("\n    [ %3d ] :: ", i);
				for(k = 0; k < licznikP; k++) {
					for(l = 0; l < licznikP; l++) {
						if(*(liczbyPierwsze + k) + *(liczbyPierwsze + l) == i) {
							//printf("%d i %d, ", *(liczbyPierwsze + k), *(liczbyPierwsze + l));
							hipotezaG[licznik++] = *(liczbyPierwsze + k);
							hipotezaG[licznik++] = *(liczbyPierwsze + l);
							break;
						}
					}
				}
				// Okreœlanie liczby wyœwietlanych liczb pierwszych
				// Bez tego pary bêd¹ wyœwietlane podwójnie, np. /7 i 3/ oraz /3 i 7/
				if((licznik%2 == 0) && (licznik > 2)) {
					if((licznik/2)%2 != 0) {
						licznikG = (licznik/2) + 1;
					}
					else {
						licznikG = licznik/2;
					}
				}
				else {
					licznikG = licznik;
				}
				for(k = 0; k < licznikG; k += 2) {
					printf("%d + %d,  ", hipotezaG[k], hipotezaG[k + 1]);
				}
			}
			printf("\n\n");
			system("pause");
			break;
	}

	return 0;
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
