#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n = 1;

	printf("Realizacja cwiczenia 6.5A:\n");
	printf("Program znajduje najmniejsza liczbe naturalne taka ze (1.2)^n > 1000*n^2\n\n");

	while(pow(1.02, n) <= 1000*n*n) {
		n++;
		printf("n = %d\n", n);
		/*if(n%20 == 0) {
			printf("\n");
			system("pause");
			system("cls");
		}*/
	}

	printf("\n(1.2)^n  = %.3f", pow(1.02, n));
	printf("\n1000*n*n = %.3f", 1000*n*n);
	printf("\n\nNajmniejsza liczba n spelniajaca zadanie to: %d\n\n", n);

	system("pause");
	return 0;
}
