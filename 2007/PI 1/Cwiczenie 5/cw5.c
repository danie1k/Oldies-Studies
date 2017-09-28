#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159

float floatScanf(char *komunikat);

int main(void) {
	float przyprostokatnaA, przyprostokatnaB, przeciwprostokatna, prawa, katA, katB;

	printf("Realizacja cwiczenia 5.5:\n");
	printf("Obliczanie przeciwprostokatnej C oraz katow trojkata prostokatnego\n\n");

	przyprostokatnaA = floatScanf("Podaj przyprostokatna A: ");
	przyprostokatnaB = floatScanf("Podaj przyprostokatna B: ");

	przeciwprostokatna = sqrt(przyprostokatnaA*przyprostokatnaA + przyprostokatnaB*przyprostokatnaB);
	katA = asin(przyprostokatnaA/przeciwprostokatna);
	katB = asin(przyprostokatnaB/przeciwprostokatna);
	printf("\nPrzeciwprostokatna C wynosi: %.2f", przeciwprostokatna);
	printf("\nKaty w tym trojkacie maja wartosci (w stopniach): ");
	printf("%.1f, %.1f, 90\n\n", katA*(180/PI), katB*(180/PI));

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
