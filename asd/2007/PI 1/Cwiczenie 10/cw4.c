#include <stdio.h>
#include <stdlib.h>

void hanoi(int iloscKrazkow, int przeniesZ, int przeniesDo);
int intScanf(char *komunikat);

int main(void) {
	int iloscKrazkow;

	printf("Realizacja cwiczenia 10.4:\n");
	printf("Wieze Hanoi\n\n");

	printf("Ile 'krazkow' ma zostac przelozonych?: ");
	scanf("%d", &iloscKrazkow);
	printf("\n");

	hanoi(iloscKrazkow, 1, 3);

	printf("\n");
	system("pause");
	return 0;
}

void hanoi(int iloscKrazkow, int przeniesZ, int przeniesDo) {
	int i;

	if(iloscKrazkow > 1) {
		hanoi((iloscKrazkow - 1), przeniesZ, (6 - przeniesZ - przeniesDo));
		printf("Przenoszenie krazka [%d] ze stosu  %d  na  %d\n", iloscKrazkow, przeniesZ, przeniesDo);
		hanoi((iloscKrazkow - 1), (6 - przeniesZ - przeniesDo), przeniesDo);
	}
	else {
		printf("Przenoszenie krazka [%d] ze stosu  %d  na  %d\n", iloscKrazkow, przeniesZ, przeniesDo);
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
