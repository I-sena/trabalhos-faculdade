/**
*** ALUNA: Izabela Caldeira Sena 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta,int n);
void sorteia_valores(int *sorteio,int n);
int compara_aposta(int *aposta, int *sorteio,int *val_certos,int na, int ns);

int main(){
    int qty, qtycerto, n = 20;
    printf("|QUANTOS NUMEROS VAI APOSTAR| ");
    scanf("%d",&qty);
    int *aposta = (int*) malloc(qty*sizeof(int)); 
    ler_aposta(aposta,qty);
   //---------------------------------------------------//
    int *sorteio = (int*) malloc(n*sizeof(int));
    sorteia_valores(sorteio, n);
    //-----------------------------------------------------//
    int *val_certos = (int*) malloc(qty*sizeof(int));
    qtycerto = compara_aposta(aposta, sorteio, val_certos, qty, n);
    //------------------------------------------------------//
    if(qtycerto){
        printf("-> VOCE ACERTOU %d NUMEROS.\n",qtycerto);
        for(int i = 0; i < qtycerto; i++){
            printf("O %d NUMERO FOI %d\n",i+1, val_certos[i]);
        }
    }
    else    
        printf("-> VOCE NAO ACERTOU NENHUM NUMERO.\n");
    free(aposta);
    free(val_certos);
    free(sorteio);
    return 0;
}

void ler_aposta(int *aposta, int n){
    for(int i = 0; i < n; i++){
        printf("%d NUMERO:",i+1);
        scanf("%d",&aposta[i]);
    }
}
void sorteia_valores(int *sorteio, int n){
    srand(time(NULL));                   
    printf("\n| VALORES SORTEADOS:\n");
    for(int i = 0; i < n; i++){
        sorteio[i] = rand()%100;
        printf("* %d\n",sorteio[i]);
    }
    printf("------------------------\n");    
}
int compara_aposta(int *aposta, int *sorteio,int *val_certos,int na, int ns){
    int i, j, qtycerto = 0;
    for(i = 0; i < na; i++){
        for(j = 0; j < ns; j++){
            if(aposta[i] == sorteio[j]){
                val_certos[qtycerto] = aposta[i];
                qtycerto++;
                break;
            }
        }
    }
    val_certos = realloc(val_certos, qtycerto*sizeof(int));   
    return qtycerto;
}

