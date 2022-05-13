/**
**  ALUNA: IZABELA CALDEIRA SENA
*/

#include<stdio.h>

void positivo_int(int num);
int fun_soma(int num);

int main(){
    int n, num, i, soma;
    printf("Quantos numeros vao ser digitados: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        printf("-> Digite o %d numero: ",i+1);
        scanf("%d",&num);
        positivo_int(num);
        soma = fun_soma(num);
        printf("* A soma dos divisores de %d eh: %d\n", num, soma);
    }
    return 0;
}

void positivo_int(int num){
    if(num >= 0)
        printf("* O numero %d eh um numero positivo e inteiro\n",num);
    else
        printf("* %d nao eh um numero inteiro e positivo\n",num);
}

int fun_soma(int num){
    int i, soma = 0 ;
    for(i = 1; i < num; i++){
        if((num%i) == 0){
            soma = soma + i;
        }
    }
    return soma;
}

