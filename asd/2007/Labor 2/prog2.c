#include <stdio.h>
#include <stdlib.h>

#define TABLICA 3

int main(void)
{
	char tab[TABLICA][3][50];
	int i, j, x, t, klawisz;

int xxx;

	for(i=0; i<TABLICA; i++)
	{
		printf("\n         Podaj imie studenta %d: ",i+1);
			scanf("%s",&tab[i][0]);
		printf("     Podaj nazwisko studenta %d: ",i+1);
			scanf("%s",&tab[i][1]);
		printf("Podaj numer indeksu studenta %d: ",i+1);
			scanf("%s",&tab[i][2]);
	}


    do
    {
         printf("\nWybierz kolumne sortowania:\n  1 - wg. imienia\n  2 - wg. nazwiska\n  3 - wg. numeru indeksu\n\nPodaj cyfre: ");
         scanf("%d",&klawisz);
         if((klawisz != 1) || (klawisz != 2) || (klawisz != 3)) continue;
    }
    while((klawisz != 1) && (klawisz != 2) && (klawisz != 3));


    switch(klawisz)
    {
        case 1:

for(xxx=0; xxx<50; xxx++)
{

  for (i=0; i<; i++)
    for (j=0; j<50-1; j++)
      if (tab[j][0][xxx]>tab[j+1][0][xxx])
      {
        t = tab[j][0];
        tab[j][0][xxx] = tab[j+1][0][xxx];
        tab[j+1][0][xxx] = t;
      }

}
		break;
        case 2:

		break;
        case 3:
			
		break;
    }

for(i=0; i<TABLICA; i++)
  for(j=0; j<3; j++)
    printf("%s ",tab[i][j]);



	printf("\n");
	system("pause");
	return 0;
}