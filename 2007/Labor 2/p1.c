#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR_TABLICY 10

int random(void);

int main(void)
{
    int i, j;
    int n, m;
    int punktY, punktX, x, y;
    int tablica[ROZMIAR_TABLICY][ROZMIAR_TABLICY], punkty[ROZMIAR_TABLICY][ROZMIAR_TABLICY], licznik=0, suma=0;
    
printf("Zape³nianie tablicy . . .");
for(i=0;i<ROZMIAR_TABLICY;i++) for(j=0;j<ROZMIAR_TABLICY;j++) tablica[i][j] = random();
printf(" zrobione!\n\n");

printf("Podaj wspolrzedne punktu odniesienia (X.Y): ");
scanf("%d.%d",&punktX,&punktY);



printf("\n###|    1    2    3    4    5    6    7    8    9   10\n---+--------------------------------------------------\n");
for(i=0; i<ROZMIAR_TABLICY; i++)
{
    printf("%2d | ",i+1);
    for(j=0; j<ROZMIAR_TABLICY; j++)
    {
          if( j==punktX-1 && i==punktY-1 ) printf("[%2d] ",tablica[i][j]);
          else printf("%4d ",tablica[i][j]);
    }
    printf("\n   |\n");
}



//printf("\n\nPunkty mniejsze: ");

if(punktY>punktX)
{
    for(n=1,m=1; n<punktY,m<=punktX; n++,m++)
    {
        x = punktX-n+1;
        y = punktY-m+1;
        if(x<1 || y<1) continue;
        else
        {
            //printf("%d.%d  ",x,y);
            punkty[licznik][0] = x;
            punkty[licznik++][1] = y;
        }
    }
}
else
{
    for(n=1,m=1; n<=punktY,m<punktX; n++,m++)
    {
        x = punktX-n+1;
        y = punktY-m+1;
        if(x<1 || y<1) continue;
        else
        {
            //printf("%d.%d  ",x,y);
            punkty[licznik][0] = x;
            punkty[licznik++][1] = y;
        }
    }
}


//printf("\n\nPunkty wieksze: ");

if(punktY>punktX)
{
    for(n=1,m=1; n<=ROZMIAR_TABLICY-punktY,m<ROZMIAR_TABLICY-punktX; n++,m++)
    {
        x = punktX+n;
        y = punktY+m;
        if(x>ROZMIAR_TABLICY || y>ROZMIAR_TABLICY) continue;
        else
        {
            //printf("%d.%d  ",x,y);
            punkty[licznik][0] = x;
            punkty[licznik++][1] = y;
        }
    }
}
else
{
    for(n=1,m=1; n<ROZMIAR_TABLICY-punktY,m<=ROZMIAR_TABLICY-punktX; n++,m++)
    {
        x = punktX+n;
        y = punktY+m;
        if(x>ROZMIAR_TABLICY || y>ROZMIAR_TABLICY) continue;
        else
        {
            //printf("%d.%d  ",x,y);
            punkty[licznik][0] = x;
            punkty[licznik++][1] = y;
        }
    }
}

printf("\n\nPunkty: ");
for(i=0; i<licznik; i++)
{
    printf("%d.%d  ",punkty[i][0],punkty[i][1]);
}

printf("\n\n");
    
for(i=0; i<licznik; i++)
{
    x = punkty[i][1]-1;
    y = punkty[i][0]-1;
    suma += tablica[x][y];
    printf("tablica[%d][%d] = %d\n",x,y,tablica[x][y]);
}
printf("\nSuma: %d",suma);

    
    printf("\n\n");
    system("pause");
    return 0;
}


int random(void)
{
    int iMin = 0;
    int iMax = 100;
    int ret;
    ret = ((((double)rand()/RAND_MAX)*iMax)+iMin);
    return ret;    
}
