#include"circular.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct fila{
    int position;
    struct fila* prox;
}FILA;

struct lista{
    struct fila* inicio;
};

LISTA* newList(){
    LISTA* nova = malloc(sizeof(LISTA));
    if(nova){
        nova->inicio = NULL;
    }
    return nova;
}

int insertEnd(LISTA* list, int position){
    FILA* novo = malloc(sizeof(FILA));
    if(novo == NULL || list == NULL)
        return 0;
    if(list->inicio == NULL){
        novo->position = position;
        novo->prox = novo;
        list->inicio = novo;
    }
    else{
        FILA* aux = list->inicio;
        while(aux->prox != list->inicio){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->position = position;
        novo->prox = list->inicio;
    }
    return -1;
}

int rightPosition(LISTA* list, int solder, int luckyOne){
    int theOne;
    FILA* aux = list->inicio;
    if (luckyOne == 1)
        return solder; 
    while(solder != 1){
        FILA* ant = NULL;                        
        for(int i = 1; i < luckyOne; i++){   
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = aux->prox;
        theOne = ant->position;
        free(aux);                  
        aux = ant->prox;            
        solder--;
    }
    return theOne;
}
