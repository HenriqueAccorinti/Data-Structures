#include <stdio.h>
#include <stdlib.h>

int soma(double v[],int n);

int main()
{
    int resp;
    double v[]={1,2,3,4};
    int n=4;

    resp = soma(v,n);
    printf("Soma: %d",resp);
    return 0;
}

int soma(double v[], int n){
    int resp;

    if(n==1){
        resp = v[0];
    }else{
        resp = soma(v,n-1)+v[n-1];
    }

    return resp;
}
