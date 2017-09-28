#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char input[100];

	printf("Realizacja cwiczenia 5.1:\n");
	printf("Wyswietlanie dowolnego tekstu wprowadzonego przez uzytkownika\n\n");

	printf("Podaj dowolny ciag znakow: ");
	gets(input);
	printf("\nWpisano: \"%s\"\n\n", input);

	system("pause");
	return 0;
}
