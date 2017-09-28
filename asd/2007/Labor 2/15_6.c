#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float liczba, suma = 0, srednia;
  int ilosc_podanych_liczb = 0, liczby_dodatnie = 0, wyrazy_mniejsze = 0;

  do {
    printf("Podaj liczbe: ");
    scanf("%f", &liczba);

    if(liczba != 0)
      ilosc_podanych_liczb++;

    if((liczba != 0) && (liczba > 0))
    {
      suma += liczba;
      liczby_dodatnie++;
    }

    if((liczba != 0) && (fabs(liczba) < 100))
      wyrazy_mniejsze++;

  }
  while (liczba != 0);

  srednia = (suma/liczby_dodatnie);

  printf("\nPodanych liczb: %d\nWyrazy o module < 100: %d\n", ilosc_podanych_liczb, wyrazy_mniejsze);
  printf("\nSrednia arytmetyczna liczb dodatnich: %.3f\n\n", srednia);

  system("pause");
  return 0;
}
