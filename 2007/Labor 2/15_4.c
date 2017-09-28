#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a, b, temp, i;
  

  printf("Podaj przedzial liczb naturalnych <a, b>:\n");
  do
  {
    printf(" a:  ");
    scanf("%d", &a);
  }
  while (a < 0);

  do
  {
    printf(" b:  ");
    scanf("%d", &b);
  }
  while (b < 0);

  if(a > b)
  {
    temp = b;
    b = a;
    a = temp;
  }

  printf("\nLiczby nie spelniajace nierownosci to:\n ");
  for(i = a; i <= b; i++)
  {
    if((i*i*i + 20*i)  >= (3*i*i + 370))
      printf("%3d ", i);
  }

  printf("\n\n");

  system("pause");
  return 0;
}
