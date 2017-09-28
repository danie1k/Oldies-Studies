#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR_TABLICY 10

int dlugosc(char *tab);
void sortowanie(char *tab[]);

int main(void)
{
    char *tab[ROZMIAR_TABLICY] = {
         "jeden", 
         "dwa", 
         "tszy", 
         "abacadaba", 
         "piec", 
         "bleeeeeeeeeeeeeeeeeeeeeeeeee", 
         "x", 
         "costam", 
         "Lorem ipsum dolor sit amet", 
         "koniec."
    };
    int x, i;

for(i=0; i<ROZMIAR_TABLICY; i++)
         printf("%s \n",tab[i]);

sortowanie(tab);
    
for(i=0; i<ROZMIAR_TABLICY; i++)
         printf("%s \n",tab[i]);

    printf("\n\n");
    system("pause");
    return 0;
}

int dlugosc(char *tab)
{
    int i = 0;
    while(*(tab+i) != 0) i++;
    return i;
}

void sortowanie(char *tab[])
{
   int i, j, t;
   char *temp;

   printf("\n----------------------------\nSortowanie . . .");

   for(i=0; i<ROZMIAR_TABLICY-1; i++)
   {
      t = i;
      for (j=i+1; j<ROZMIAR_TABLICY; j++)
         if( dlugosc(tab[j]) < dlugosc(tab[t]) )
            t = j;
      temp = (char*) malloc(dlugosc(tab[t]));
      temp = tab[t];
      tab[t] = tab[i];
      tab[i] = temp;
      free(temp);
   }

   printf(" zakonczono!\n----------------------------\n\n");
}
