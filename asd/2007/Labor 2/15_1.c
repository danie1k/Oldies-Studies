#include <stdio.h>

int main(void)
{
  int liczba = 0, suma = 0;

  do {
      printf("Podaj liczbe: ");
      scanf("%d", &liczba);
      suma += liczba;
      printf("  Suma podanych liczb: %d\n\n", suma);
  } while (!isdigit(liczba));

  system("pause");
  return 0;
}
