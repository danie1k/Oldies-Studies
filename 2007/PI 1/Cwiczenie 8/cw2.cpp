#include <stdio.h>
#include <stdlib.h>

float oblicz(int n);
int intScanf(char *komunikat);

int main(void) {
	float **tablica;
	int a, b, tmp, i;

	printf("Realizacja cwiczenia 8.2:\n");
	printf("Program oblicza wartosc wyrazenia W(n)\n\n");

	printf("Podaj przedzial liczb naturalnych <a; b> (a,b > 1):\n");
	do {
		a = intScanf(" a: ");
	}
	while(a <= 1);
	do {
		b = intScanf(" b: ");
	}
	while(b <= 1);
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	tablica = new float*[b - a];
	for (i = 0; i <= (b - a); i++) {
		tablica[i] = new float[3];
	}

	for(i = 0; i <= (b - a); i++) {
		*(*(tablica+i)+0) = a + i;
		*(*(tablica+i)+1) = oblicz(a + i);
	}

	system ("cls");

	printf("Przedzial: <%d; %d>\n\n", a, b);
	printf("   +------+----------+--------------+\n");
	printf("   |  lp  |  liczba  |  wart. wyr.  |\n");
	printf("   +------+----------+--------------+\n");
	for(i = 0; i <= (b - a); i++) {
		printf("   |  %02d  |  %6.0f  |  %10.1f  |\n", (i + 1), *(*(tablica+i)+0), *(*(tablica+i)+1));

		if(((i + 1)%17 == 0) && (i != b - a)) {
			printf("   +------+----------+--------------+\n\n");
			system("pause");
			system("cls");
			printf("Przedzial: <%d; %d>\n\n", a, b);
			printf("   +------+----------+--------------+\n");
			printf("   |  lp  |  liczba  |  wart. wyr.  |\n");
			printf("   +------+----------+--------------+\n");
		}
	}
	printf("   +------+----------+--------------+\n\n");

	delete [] tablica;
	system("pause");
	return 0;
}

float oblicz(int n) {
	float wynik;
	if(n%2 == 0) { // Dla parzystych
		wynik = 0.5*n + n*n;
	}
	else { // Dla nieparzystych
		wynik = (n - 5)*n;
	}
	return wynik;
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
