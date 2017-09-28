#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void odleglosc(int *x, int *y, int dlugosc1, int dlugosc2);
void normy(int *x, int *y, int dlugosc1, int dlugosc2);
void suma(int *x, int *y, int dlugosc1, int dlugosc2);
void roznica(int *x, int *y, int dlugosc1, int dlugosc2);

int main(void)
{
    int klawisz, dlugosc[2];
    int wektor1[] = {1, 2, 3, 4, 5};
    int wektor2[] = {10, 20, 30, 40, 50};
    
    do
    {
        printf("\nWybierz operacje na wektorach:\n  1 - odleglosc\n  2 - normy\n  3 - suma\n  4 - roznica\n\nPodaj cyfre: ");
        scanf("%d",&klawisz);
        if((klawisz != 1) || (klawisz != 2) || (klawisz != 3) || (klawisz != 4)) continue;
    }
    while((klawisz != 1) && (klawisz != 2) && (klawisz != 3) && (klawisz != 4));
    
    dlugosc[0] = sizeof wektor1/sizeof(int);
    dlugosc[1] = sizeof wektor2/sizeof(int);

    switch(klawisz)
    {
        case 1: odleglosc(wektor1, wektor2, dlugosc[0], dlugosc[1]);  break;
        case 2: normy(wektor1, wektor2, dlugosc[0], dlugosc[1]);      break;
        case 3: suma(wektor1, wektor2, dlugosc[0], dlugosc[1]);       break;
        case 4: roznica(wektor1, wektor2, dlugosc[0], dlugosc[1]);    break;
    }

    system("pause");
}

void odleglosc(int *x, int *y, int dlugosc1, int dlugosc2)
{
    int i;
    float ret=0;
    if(dlugosc1 == dlugosc2)
    {
        printf("\n\nWyznaczanie odleglosci wektorow . . . ");
        for(i=0; i<dlugosc1; i++) ret += (x[i] - y[i])*(x[i] - y[i]);
        ret = sqrt(ret);
        printf("zrobione!\nOdleglosc wektorow to: %.2f\n\n",ret);
    }
    else printf("\n\nNie mozna wyznaczyc odleglosci wektorow, gdyz maja rozna wielkosc.\n\n");
}

void normy(int *x, int *y, int dlugosc1, int dlugosc2)
{
    int i;
    float ret[2]={0,0};
    printf("\n\nWyznaczanie normy wektorow . . . ");
    for(i=0; i<dlugosc1; i++) ret[0] += x[i]*x[i];
    for(i=0; i<dlugosc2; i++) ret[1] += y[i]*y[i];
    ret[0] = sqrt(ret[0]);
    ret[1] = sqrt(ret[1]);
    printf("zrobione!\nWyniki to:\n  wektor1 -> %.2f\n  wektor1 -> %.2f\n\n",ret[0],ret[1]);
}
     
void suma(int *x, int *y, int dlugosc1, int dlugosc2)
{
    int i;
    int *ret;
    if(dlugosc1 == dlugosc2)
    {
        ret = (int*) malloc(dlugosc1);
        printf("\n\nWyznaczanie sumy wektorow . . . ");
        for(i=0; i<dlugosc1; i++) ret[i] = (x[i] + y[i]);
        printf("zrobione!\nSuma wekrorow to:\n  ret = [ ");
        for(i=0; i<dlugosc1; i++) printf("%d ",ret[i]);
        printf("]\n\n");
    }
    else printf("\n\nNie mozna wyznaczyc odleglosci wektorow, gdyz maja rozna wielkosc.\n\n");
}

void roznica(int *x, int *y, int dlugosc1, int dlugosc2)
{
    int i;
    int *ret;
    if(dlugosc1 == dlugosc2)
    {
        ret = (int*) malloc(dlugosc1);
        printf("\n\nWyznaczanie roznicy wektorow . . . ");
        for(i=0; i<dlugosc1; i++) ret[i] = (x[i] - y[i]);
        printf("zrobione!\nRoznica wekrorow to:\n  ret = [ ");
        for(i=0; i<dlugosc1; i++) printf("%d ",ret[i]);
        printf("]\n\n");
    }
    else printf("\n\nNie mozna wyznaczyc odleglosci wektorow, gdyz maja rozna wielkosc.\n\n");
}

