#include <stdio.h>
#include <stdlib.h>

int main()
{
float a, b;

printf("Digite os valores desejados, por favor: ");
scanf("%f , %f", &a, &b);

printf("O valor de b e a vao ser: %.2f, %.2f", b , a);
return 0;
}

/*#include<stdio.h>

void trocar(int*x, int*y){
int t = *x;
*x = *y;
*y = t;
}

int main(void) {
int a = 10, b = 20;

printf("Valores originais: de a = %d e b = %d\n", a, b);
trocar( &a, &b );
printf("Depois da troca: de a = %d e b = %d\n", a, b);

return 0;
}
*/
