/*3- Faça um algoritmo que receba um número inteiro e verifique se o mesmo 
é um número primo ou não. */

/*4- Faça um algoritm que leia  uma quantidade indeterminada de números
 inteiros positivos e identifique qual foi o maior número digitado.
  O final da sequência de números é indicado pelo valor -1. */

#include<stdio.h>
int main(){
    int n,m=0;

    scanf("%d",&n);
    do{
        if(m<n){
            m=n;
        }
        scanf("%d",&n);
    }while(n!= -1);
    printf("%d eh o maior.... ",m);
    return 0;
}