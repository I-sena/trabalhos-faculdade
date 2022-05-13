#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct pixed{
    int id_orig, id_dest;
    float valor;
    struct pixed* prox;
}PixED;

PixED* create_and_fill(int id_orig,int id_dest,float valor){
    PixED* new = malloc(sizeof(PixED));
    if(new){
        new->id_orig = id_orig;
        new->id_dest = id_dest;
        new ->valor = valor;
        new->prox = new;
    }return new;
}

struct queue{
    int qty, N;
    PixED* end;
};

Queue* Queue_create(int N){
    Queue* new = malloc(sizeof(Queue));
    if(new){
        new->qty = 0;
        new->end = NULL;
        new->N = N;
    }return new;
}

int Enqueue(Queue* fila,int orig,int des,float value){
    PixED* new = create_and_fill(orig,des,value);
    if(fila == NULL || new == NULL || IsFull(fila)) return 0;
    if(fila->end == NULL)
        fila->end = new;
    else{
        new->prox = fila->end->prox; 
        fila->end->prox = new; 
        fila->end = new;
    }
    fila->qty++;
    return 1;
}

int Dequeue(Queue* fila,int* orig,int* dest,float* valor){
    if(IsEmpty(fila) || fila == NULL) return 0;
    PixED* begin = fila->end->prox;
    *orig = begin->id_orig;
    *dest = begin->id_dest;
    *valor = begin->valor;
    if(fila->end == begin)
        fila->end = NULL;
    else
        fila->end->prox = begin->prox;
    free(begin);
    fila->qty--;
    return 1;
}

void Destroy(Queue* fila){
    if(fila){
        if(!IsEmpty(fila)){
            PixED* aux = fila->end->prox;
            while(aux != fila->end){
                fila->end->prox = aux->prox;
                free(aux);
                aux = fila->end->prox;
            }
            free(aux);
        }
        free(fila);
    }
}

int IsEmpty(Queue* fila){
    return fila->end == NULL;
}

int IsFull(Queue* fila){
    return fila->qty == fila->N;
}