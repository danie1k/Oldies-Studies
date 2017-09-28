#include <stdio.h>
#include <stdlib.h>

int pierwsza(int liczba);
int podzielna(int liczba);
int intScanf(char *komunikat);

int main(void) {
	int a, b, tmp, i, j, **tablica;

	printf("Realizacja cwiczenia 8.3:\n");
	printf("Sprawdzanie jakie z podanych liczb to l. pierwsze a jakie podzielne przez 23\n\n");

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

	tablica = new int*[b - a];
	for (i = 0; i <= (b - a); i++) {
		tablica[i] = new int[3];
	}

	for(i = 0; i <= (b - a); i++) {
		*(*(tablica+i)+0) = a + i;
		*(*(tablica+i)+1) = pierwsza(a + i);
		*(*(tablica+i)+2) = podzielna(a + i);
	}

	system("cls");

	printf("Przedzial: <%d; %d>\n\n", a, b);
	printf("   +------+----------+-------------+--------------+\n");
	printf("   |  lp  |  liczba  |  pierwsza?  |  podzielna?  |\n");
	printf("   +------+----------+-------------+--------------+\n");
	for(i = 0; i <= (b - a); i++) {
		printf("   |  %02d  |  %6d  |       ", (i + 1), *(*(tablica+i)+0));
		if(*(*(tablica+i)+1)) {
			printf("TAK");
		}
		else {
			printf("  -");
		}
		printf("   |        ");
		if(*(*(tablica+i)+2)) {
			printf("TAK");
		}
		else {
			printf("  -");
		}
		printf("   |\n");

		if(((i + 1)%17 == 0) && (i != b - a)) {
			printf("   +------+----------+-------------+--------------+\n\n");
			system("pause");
			system("cls");
			printf("Przedzial: <%d; %d>\n\n", a, b);
			printf("   +------+----------+-------------+--------------+\n");
			printf("   |  lp  |  liczba  |  pierwsza?  |  podzielna?  |\n");
			printf("   +------+----------+-------------+--------------+\n");
		}
	}
	printf("   +------+----------+-------------+--------------+\n\n");

	delete [] tablica;
	system("pause");
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

int podzielna(int liczba) {
	int ret = 0;

	if(liczba%23 == 0) {
		ret = 1;
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
