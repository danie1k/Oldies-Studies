#include <stdio.h>
#include <stdlib.h>

float floatScanf(char *komunikat);

int main(void) {
	float x, fx;

	printf("Realizacja cwiczenia 5.6:\n");
	printf("Program oblicza wartosc funkcji w zaleznosci od wartosci liczby x\n\n");

	x =floatScanf("Podaj x: ");

	if((x >= -5) && (x <= 5)) {
		printf("\n/ fx = 2*x*x + 3*x - 1; /\n");
		fx = 2*x*x + 3*x - 1;
	}
	else {
		printf("\n/ fx = (x + 5)*(x + 5) - 10; /\n");
		fx = (x + 5)*(x + 5) - 10;
	}

	printf("\nx    = %.2f\nF(x) = %.2f\n\n", x, fx);	

	system("pause");
	return 0;
}

float floatScanf(char *komunikat) {
	char tmp[100];
	int tryAgain = 0;
	do {
		if(tryAgain) {
			printf("\nPodana wartosc jest nieprawidlowa!\n  ");
		}
		printf(komunikat);
		scanf("%s", tmp);
		if(atof(tmp) == 0.0) {
			tryAgain = 1;
		}
		else {
			tryAgain = 0;
		}
	}
	while(tryAgain);
	return atof(tmp);
}
