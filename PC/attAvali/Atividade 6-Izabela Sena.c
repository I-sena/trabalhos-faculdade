/** 1- Escreva um programa em C que, através de recursividade, encontre e retorne o maior elemento
    de um vetor. Os elementos do vetor deverão ser informados pelo usuário.
 **ALUNA: Izabela Caldeira Sena.
*/

#include <stdio.h>

int maiorNum(int*, int);

int main(){
    int index;
    printf("QUANTOS NUMEROS TERA O VETOR\? ");
    scanf("%d",&index);
    int vetor[index];
    for(int i = 0; i < index; i++){
        printf("INFORME O %d VALOR DO VETOR: ",i+1);
        scanf("%d",&vetor[i]);
    }
    printf("--O MAIOR NUMERO DO VETOR EH: %d", maiorNum(vetor,index));
    return 0;
}

int maiorNum(int* vetor,int index){
    int valorAtual, valorAnterior;
    if (index == 1) return vetor[0];
    valorAtual = vetor[index-1];
    valorAnterior = maiorNum(vetor,index-1);
    if (valorAtual > valorAnterior)
        return valorAtual;
    else 
        return valorAnterior;
}