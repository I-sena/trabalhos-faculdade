#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue* Queue_create(int);
int Enqueue(Queue*,int,int,float);
int Dequeue(Queue*,int*,int*,float*);
void Destroy(Queue*);
int IsEmpty(Queue*);
int IsFull(Queue*);

#endif