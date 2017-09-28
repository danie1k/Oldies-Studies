#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float E, n = 0, suma = 0;

  do
  {
    printf("Podaj dowolna liczbe dodatnia E: ");
    scanf("%f", &E);
  }
  while (E < 0);

  printf("\nSuma:\n\n");

  do
  {
    n++;
    suma += (1/n);
    printf(" %.4f +\n", (1/n));
  }
  while (suma < E);      

  printf("___________\n= %.4f\n\nNajmniejsza liczba n spelniajaca zadanie to: %.0f\n\n", suma, n);

  system("pause");
  return 0;
}
