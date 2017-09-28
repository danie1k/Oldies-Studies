#include <stdio.h>
#include <stdlib.h>

void generujLiczbyFibonacciego(int *tablica, int licznik);
int intScanf(char *komunikat);

int main(void) {
	int i, ilosc, *liczbyFibonacciego;

	printf("Realizacja cwiczenia 10.3A:\n");
	printf("Program generuje zadana ilosc liczb Fibonacciego\n\n");

	ilosc = intScanf("Podaj ilosc liczb Fibonacciego do wygenerowania: ");

	liczbyFibonacciego = new int[ilosc];

	generujLiczbyFibonacciego(liczbyFibonacciego, ilosc);

	printf("\nWygenerowane liczby Fibonacciego:\n\n", ilosc);
	for(i = 0; i < ilosc; i += 2) {
		printf("  %02d. %-10d            ", (i + 1), *(liczbyFibonacciego + i));
		if((i + 2) <= ilosc) {
			printf("  %02d. %-10d\n", (i + 2), *(liczbyFibonacciego + i + 1));
		}
		else {
			printf("\n");
		}
	}

	printf("\n");
	system("pause");
	return 0;
}

void generujLiczbyFibonacciego(int *tablica, int licznik) {
	int i;
	tablica[0] = 1;
	tablica[1] = 1;
	for(i = 2; i < licznik; i++) {
		tablica[i] = tablica[i - 2] + tablica[i - 1];
	}

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
