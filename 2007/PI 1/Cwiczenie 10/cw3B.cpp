#include <stdio.h>
#include <stdlib.h>

int generujLiczbyFibonacciego(int *tablica, int start, int koniec);
int intScanf(char *komunikat);

int main(void) {
	int i, k, l, tmp, iloscWygenerowanych, *liczbyFibonacciego;

	printf("Realizacja cwiczenia 10.3B:\n");
	printf("Program generuje liczby Fibonacciego z zadanego przedzialu\n\n");

	printf("Podaj przedzial <k; l>, w ktorym ma wykonac sie program:\n");
	k = intScanf(" k: ");
	l = intScanf(" k: ");
	if(k > l) {
		tmp = k;
		k = l;
		l = tmp;
	}

	liczbyFibonacciego = new int[l - k];
	iloscWygenerowanych = generujLiczbyFibonacciego(liczbyFibonacciego, k, l);

	printf("\nPrzedzial: <%d; %d>\n", k, l);
	printf("\nIlosc wygenerowanych liczb: %d\n\n", iloscWygenerowanych);
	for(i = 0; i < iloscWygenerowanych; i++) {
		printf(" %02d. %-10d\n", (i + 1), *(liczbyFibonacciego + i));
	}


	printf("\n");
	system("pause");
	return 0;
}

int generujLiczbyFibonacciego(int *tablica, int start, int koniec) {
	int i, element, licznikZewn = 0, calyCiag[koniec - start];

	calyCiag[0] = 1;
	calyCiag[1] = 1;

	if(start == 1) {
		tablica[0] = 1;
		tablica[1] = 1;
		licznikZewn = 2;
	}

	for(i = 2; i <= (koniec - start); i++) {
		calyCiag[i] = calyCiag[i - 2] + calyCiag[i - 1];
		//printf("elem. ciagu: %d\n", calyCiag[i]);
		if((calyCiag[i] >= start) && (calyCiag[i] <= koniec)) {
			tablica[licznikZewn++] = calyCiag[i];
		}
	}
	return licznikZewn;
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
