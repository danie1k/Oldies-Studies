#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const float E = 0.0001;
	float biezacy = 0, poprzedni = 0, suma = 0;
	int n = 1, koniec = 0;

	printf("Realizacja cwiczenia 6.2:\n");
	printf("Program wyznacza sume kolejnych wyrazow szeregu\n\n");

	system("pause");
	system("cls");

	biezacy = (1.0/(n*(n + 1.0)));

	do {
		n++;
		printf("\n n = %d", n);
		printf("\n poprzedni = %.4f", biezacy);
		poprzedni = biezacy;
		suma += poprzedni;

		biezacy = (1.0/(n*(n + 1.0)));
		printf("\n biezacy = %.4f", biezacy);
		printf("\n suma = %.4f\n\n", suma);

		if(((n-1)%4 == 0)) {
			system("pause");
			system("cls");
		}

		if(fabs(poprzedni - biezacy) < E) {
			koniec = 1;
		}
	}
	while(koniec != 1);

	printf("\n\nDla %d elementow suma wynosi: %.3f\n\n", n, suma);

	system("pause");
	return 0;
}
