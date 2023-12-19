#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,m,fa=2,fm=1,fantes;
    int i=0;

    printf("Informe o inicio do intervalo (a): ");
    scanf("%f", &a);

    printf("Informe o fim do intervalo (b): ");
    scanf("%f", &b);

    while((fabs(fantes-fm))>0.0000000001 || fm!=0){

        fantes= fm;
        m = (a+b)/2;

        fa= (a * a)-1;
        fm= (m * m)-1;

        printf("\nFa[%i]: %.2f",i, fa);
        printf("\nFm[%i]: %.2f\n",i, fm);

        if(fa * fm<0){
            b=m;
        }else{
            a=m;
        }

    }
    printf("\nRaiz da funcao: %.2f\n", fm);
    return 0;
}
