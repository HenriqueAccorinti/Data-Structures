#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float a, b;
    char forma; // 'c' ou 'p'
} Complexo;

Complexo LerComplexo();
Complexo CartesianoParaPolar(Complexo);
Complexo PolarParaCartesiano(Complexo);
Complexo SomarComplexos(Complexo, Complexo);
Complexo MultiplicarComplexos(Complexo, Complexo);
void ExibirComplexo(Complexo);


int main(){
    Complexo z1, z2, zS, zM;
    z1 = LerComplexo();
    z2 = LerComplexo();
    zS = SomarComplexos(z1,z2);

    ExibirComplexo(zS);
    zM = MultiplicarComplexos(z1,z2);
    ExibirComplexo(zM);

    return 0;
}


Complexo LerComplexo(){
Complexo z;
printf("Forma (c)artesiana ou (p)olar: ");
fflush(stdin);
scanf("%c", &z.forma);
if(z.forma== 'c')
    printf("Digite as componentes RE e IM:\n");
else
    printf("Digite o modulo e a fase:\n");
    scanf("%f", &z.a);
    scanf("%f", &z.b);
return z;
}


Complexo CartesianoParaPolar(Complexo z){
Complexo aux;
aux.forma= 'p';
aux.a= sqrt(pow(z.a,2.0) + pow(z.b,2.0));
aux.b= atan(z.b/z.a);
return aux;
}


Complexo PolarParaCartesiano(Complexo z){
Complexo aux;
aux.forma= 'c';
aux.a= z.a*cos(z.b);
aux.b= z.a*sin(z.b);
return aux;
}


Complexo SomarComplexos(Complexo z1, Complexo z2){
Complexo aux;
if(z1.forma == 'p')
    z1 = PolarParaCartesiano(z1);
if(z2.forma == 'p')
    z2 = PolarParaCartesiano(z2);
    aux.forma= 'c';
    aux.a= z1.a + z2.a;
    aux.b= z1.b + z2.b;
return aux;
}


Complexo MultiplicarComplexos(Complexo z1, Complexo z2){
Complexo aux;
if(z1.forma == 'c')
    z1 = CartesianoParaPolar(z1);
if(z2.forma == 'c')
    z2 = CartesianoParaPolar(z2);
    aux.forma= 'p';
    aux.a= z1.a * z2.a;
    aux.b= z1.b + z2.b;
return aux;
}


void ExibirComplexo(Complexo z){
if(z.forma== 'c')
    printf("%.4f%cj%.4f\n",z.a,z.b>0?'+':'-',fabs(z.b));
else
    printf("%.4f<%.4f",z.a,z.b);
}



