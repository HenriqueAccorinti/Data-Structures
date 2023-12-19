#include <stdio.h>
#include <time.h>

int main(){

int N, i, j, valor = 1;

printf("Digite o valor de N, por favor: ");
scanf("%i", &N);

for (i = 0; i < N; i++)
{
    for(j = 0; j<=i; j++)
    {
        printf("%i  ", valor);
        valor ++;
    }
    printf("\n");
}
return 0;

}
