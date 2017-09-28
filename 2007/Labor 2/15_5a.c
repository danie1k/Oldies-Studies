#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float n = 1.0;

    while(pow(1.02, n) <= 1000*n*n)
      n += 1.0;        

    printf("Najmniejsza liczba n spelniajaca zadanie to: %.0f\n\n", n);

    system("pause");
    return 0;
}
