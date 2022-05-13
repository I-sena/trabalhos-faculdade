/*
    *3. Utilizando a função da questão 1, escreva uma função que, 
    recebendo um parâmetro n, retorne o valor de: 1 + 1/2! + 1/3! + ... + 1/n!

*/
#include<stdio.h>

int fatorial(int x){
    int fat=1,i;
    for(i=x;i>=1;i--){
        fat=fat*i;
    }
    return fat;
}

float divisao(float x){
    int i,r;
    float resul=0;
    for(i=1;i<=x;i++){
        r=fatorial(i);
        resul=resul+(float)1/r;
    }
    return resul;
}

int main(){
    float resul,n;
    scanf("%f",&n);
    resul=divisao(n);
    printf("%.2f",resul);
    return 0;
}

