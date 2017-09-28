#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random();
void tablica(int *tab, int rozmiar);
void sortowanie_babelkowe();
void sortowanie_szybkie();
void sortowanie_wyb(int *tab, int rozmiar);
int mniejsze(int x, int y);

int main(void)
{
    int klawisz;
    int tab[100];

    do
    {
         printf("\nWybierz typ sortowania:\n  1 - babelkowe\n  2 - szybkie\n  3 - sortowanie przez wybierania\n\n");
         scanf("%d",&klawisz);
         //printf("\nWpisano: %d",klawisz);
         if((klawisz != 1) || (klawisz != 2) || (klawisz != 3)) continue;
    }
    while((klawisz != 1) && (klawisz != 2) && (klawisz != 3));

    switch(klawisz)
    {
        case 1: sortowanie_babelkowe(); break;
        case 2: sortowanie_szybkie(); break;
        case 3: sortowanie_wyb(tab,100); break;
    }

/*tablica(tab,100);
for(int i=0;i<100;i++) printf("\ntab[%d] = %d",i,tab[i]);*/

    system("pause");
    return 0;
}

int random()
{
    int iMin = 0;
    int iMax = 100;
    int ret;
    ret = ((((double)rand()/RAND_MAX)*iMax)+iMin);
    return ret;    
}

void tablica(int *tab, int rozmiar)
{
     srand(time(0));
     for(int i=0;i<rozmiar;i++)
         *(tab+i) = random();
}     

void sortowanie_babelkowe()
{
     printf("\n\nWybrano sortowanie babelkowe\n(jednak zadziala dopiero w wersji final ;)\n\n");
}

void sortowanie_szybkie()
{
     printf("\n\nWybrano sortowanie szybkie\n(jednak zadziala dopiero w wersji final ;)\n\n");
}

void sortowanie_wyb(int *tab, int rozmiar)
{
     int t, x;
     printf("\n\nWybrano sortowanie przez wybieranie.\n\n");
     
  /* from wiki :) */
  for(int i=0; i<rozmiar-1; i++)
  {
    t = i;
    for (int j=i+1; j<rozmiar; j++)
    {
      if (mniejsze(tab+j, tab+t)) t = j;
    }
    x = tab+t;
    tab+t = tab+i;
    tab+i = x;
  }
     
}

// funkcja porównuj¹ca
int mniejsze(int x, int y)
{
    int ret;
    if(x < y) ret = 1;
    else ret = 0;
    return ret;
}
