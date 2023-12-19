#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
void LerString(char[]);

int main()
{

char senha[]="ABCD";
char tentativa[20];
int errou=1;   /* 0 se acertou ou 1 se errou */
int numErros=0;
  /* definir o valor inicial para numErros */

     /*verifica se errou*/          /*verifica a variável "numErros"*/
while((errou==1)&&(numErros<3)){

printf("Entre com a senha: ");
LerString(tentativa);
errou=strcmp(senha,tentativa);
    /* armazena na variável "errou" a comparação entre a senha e a tentativa */
if (errou)

numErros+=1;
    /*incrementa o num. de erros*/

}

if (errou)
printf("Excedeu o numero de tentativas.");
else
printf("Acertou a senha.");
return 0;
}


void LerString(char s[]){
    fflush(stdin);
    fgets(s,MAX,stdin);

    if(s[strlen(s)-1] == '\n'){
        s[strlen(s)-1] = '\0';
    }
}
