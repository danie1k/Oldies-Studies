#include <stdio.h>

int main(void)
{
  const float e = 0.0001;
  int n = 1, koniec = 0;
  float poprzedni = 0, bierzacy = 0, suma = 0;

  bierzacy = (1.0 / (n * (n + 1.0) ));

  do
  {
    n++;
    poprzedni = bierzacy;
    suma = suma + poprzedni;
    bierzacy = (1.0 / (n * (n + 1.0) ));

    if(fabs(poprzedni-bierzacy) < e)
      koniec = 1;
  }
  while(koniec != 1);

  printf("\nSuma wynosi: %f\n ...dla %d elementow.\n\n", suma, n);

  system("PAUSE");
  return 0;
}
