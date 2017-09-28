#include<stdio.h>
#include<conio.h>
void odczyt(int t[],int ile);
void sortowanie(int tab[],int ile );
void wyswietl(int t[], int ile);
void zapis(int t[], int ile);

int main(void)
{
    int ile,i,tab[20]={0};
    
    
     printf("podaj ile liczb ma odczytac: ");
     scanf("%d",&ile);
     odczyt(tab,ile);
     wyswietl(tab,ile);
     printf("\n\n");
     sortowanie(tab,ile);
     wyswietl(tab,ile);
     zapis(tab,ile);

     return 0;
}



//------------------------sortowanie-------------------------------------
void sortowanie (int tab[],int ile )


{
    int i,p,j;

    for(j=0;j<ile;j++)
    for(i=1;i<ile;i++)
    {
        if(tab[i]<tab[i-1])
        {
            p=tab[i-1];
            tab[i-1]=tab[i];
            tab[i]=p;
        }
    }
}
    
//--------------------wyswietlanie-----------------------------------------------

void wyswietl(int t[], int ile)
{
     int i;
     
     for(i=0;i<ile;i++)
      printf("  %d",t[i]);
      
     getch();
}
//------------------------odczyt----------------------------------------
void odczyt(int t[], int ile)
{
int i;
    FILE *plik=fopen("dane.txt","r");

    if(plik == NULL)
    {
      printf("\nBlad: plik z danymi nie istnieje.\n");
    }
    else
    {
      printf("\nPlik istnieje i mozna czytac.\n\n");
    }
    
    for(i=0;i<ile;i++)
      fscanf(plik,"%d",&t[i]);
    

    fclose(plik);
}
//-------------------zapis----------------------------------------

void zapis(int t[], int ile)
{
     int i;
     FILE *p=fopen("zapis.txt","w");
     for(i=0;i<ile;i++)
      fprintf(p,"  %d",t[i]);
     fclose(p);
}
