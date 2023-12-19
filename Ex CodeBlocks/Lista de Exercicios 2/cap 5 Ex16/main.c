#include <stdio.h>
#include <time.h>

int main(){

int i;
float n, Hn = 0;

printf("Caro amigo, Informe o enesimo termo da serie harmonica, por favor. Obrigado:  ");
scanf("%f", &n);

for(i = 1; i <= n; i++){
Hn += 1.0/i;
}

printf("O valor de Hn vai ser, brother: %.2f\n", Hn);
return 0;
}
