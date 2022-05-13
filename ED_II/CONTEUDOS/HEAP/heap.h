#ifndef HEAP_H
#define HEAP_H
#define MAX 10


typedef struct heap Heap;
Heap* Create();
int Heap_Insert(Heap*, int);
int Heap_Remove(Heap*, int);
void Max_Heapify(Heap*, int);
int Left(int);
int Right(int);
int Parent(int);
void Build_Max_Heap(Heap*);
void Print_Heap(Heap*);
void att(Heap*);
void troca(Heap*);
#endif