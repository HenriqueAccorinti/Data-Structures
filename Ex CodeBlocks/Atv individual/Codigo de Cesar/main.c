//Henrique Fortuna Accorinti RA:20.00080-4
//Guilherme Sanches Rossi    RA:19.02404-5
//Artthur Augusto Pires      RA:20.01004-4
//Ana Luiza Negrao Miolini   RA:20.00875-9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

#include <stdio.h>
void lerString(char []);

int main(){
    char frase[MAX], novaFrase[MAX];
    int chave=3, i;

    lerString(frase);


        for(i=0; i<strlen(frase); i++){
            novaFrase[i] = frase[i] + chave;
            if((frase[i] + chave) >= (65+chave) && (frase[i] + chave) <= (87+chave) || (frase[i] + chave) >= 100 && (frase[i] + chave) <= 122){
                novaFrase[i] = frase[i] + chave;
            }else{
            if((frase[i] + chave) >= (120+chave) && (frase[i] + chave) <= (122+chave)){    //Para que 'x', 'y' e 'z' retornem para 'a', 'b' e 'c'
                novaFrase[i] -=26;
            }else{
            if((frase[i] + chave) >= (88+chave) && (frase[i] + chave) <= (90+chave)){      //Para que 'X', 'Y' e 'Z' retornem para 'A', 'B', 'C'
                novaFrase[i] -= 26;
            }else{
                novaFrase[i] = frase[i];
            }
            }
            }

        }

        novaFrase[i] = '\0';
        printf("Frase criptografada: %s ", novaFrase);

    printf("\n");
    return 0;
}

void lerString(char s[]){
    fflush(stdin);
    printf("Digite seu texto: ");
    fgets(s,MAX,stdin);

    if(s[strlen(s)-1] == '\n'){
        s[strlen(s)-1] = '\0';
    }
}
