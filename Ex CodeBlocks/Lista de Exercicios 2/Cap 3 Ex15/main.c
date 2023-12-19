#include <stdio.h>
#include <stdlib.h>


int main()
{
int x, D1, D2, C, U;

printf("Digite o valor desejado, amigo: ");
scanf("%i",&x);

C = x/100;

D1 = x/10;

D2 = D1 - (C*10);

U = x%10;

printf("O novo numero gerado sera: %i%i%i\n\n", U, D2, C);

return 0;
}
