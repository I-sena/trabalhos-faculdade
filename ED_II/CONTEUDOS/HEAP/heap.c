#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

struct heap{
    int tree[MAX];
    int size;
    int length;
};
Heap* Create(){
    Heap* new = malloc(sizeof(Heap));
    if(new){
        new->size = 0;
        new->length = MAX;
    }return new;
}
int Heap_Insert(Heap* heap,int dada){
    if (heap == NULL)   return 0;
    if(!(heap->size == MAX-1)){
        heap->tree[++heap->size] = dada;
        return 1;
    }else return 0;
}
void Max_Heapify(Heap* heap, int father){
    int L = Left(father);
    int R = Right(father);
    int largest;
    if (L <= heap->size && heap->tree[L] > heap->tree[father])
        largest = L;
    else
        largest = father;
    if (R <= heap->size && heap->tree[R] > heap->tree[largest])
        largest = R;
    if (largest != father){
        int aux = heap->tree[largest];
        heap->tree[largest] = heap->tree[father];
        heap->tree[father] = aux;
        Max_Heapify(heap,largest);
    }
}
void Build_Max_Heap(Heap* heap){
    heap->size = heap->size-1; //length =10
    for(int i = (heap->length-1)/2; i >= 1; i--)
        Max_Heapify(heap,i);
}
void Print_Heap(Heap* heap){
    for(int i = 1; i <= MAX-1; i++)
        printf("%d ",heap->tree[i]);
    puts("");
}
int Left(int father){
    return 2*father;
}
int Right(int father){
    return (2*father)+1;
}
int Parent(int son){
    return son/2;
}
void att(Heap* att){
    Build_Max_Heap(att);
    for(int i = MAX-1; i >= 2; i--){
        int aux = att->tree[i];
        att->tree[i] = att->tree[1];
        att->tree[1] = aux; 
        att->length = att->length-1;
        printf("att --");
        Print_Heap(att);
        Max_Heapify(att,1);
    }
}
void troca(Heap* a){
    int aux = a->tree[9];
    a->tree[9] = a->tree[1];
    a->tree[1] = aux;
    Print_Heap(a);
    Max_Heapify(a,1);
    Print_Heap(a);
}