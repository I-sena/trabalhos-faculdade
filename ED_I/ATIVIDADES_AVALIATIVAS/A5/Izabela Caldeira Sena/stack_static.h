#ifndef STACK_STATIC_H
#define STACK_STATIC_H

typedef struct stack Stack;

Stack* Stack_create();
int PushMain(Stack*,int);
int PopMain(Stack*,int*);
//------------------------------
int pushSecondary(Stack*,int);
int popSecondary(Stack*,Stack*);
//----------------------------------
int IsFull(Stack*);
int IsEmpty(Stack*);
void Stack_Destroy(Stack*);

#endif