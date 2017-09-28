#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int i, x1, x2, temp;
	double wynik;

	printf("Podaj poczatek przedzialu x1 = ");
	scanf("%d",&x1);

	printf("Podaj koniec przedzialu x2 = ");
	scanf("%d",&x2);

	if(x1 > x2)
	{
		temp = x2;
		x2 = x1;
		x1 = temp;
	}

	printf("\nx1 = %d \nx2 = %d\n\n",x1,x2);


	for(i = x1; i <= x2; i++)
	{
		if((i >= -5) && (i <= 5))
			wynik = 2*i*i + 3*i - 1;
		else
			wynik = pow((i + 5),2) - 10;
		
		printf("Dla liczby: %d  --  wynik: %.0f\n\n",i,wynik);
	}

	system("PAUSE");	
	return 0;
}
