#ifndef TLINKED_LIST_UTILS_H
#define TLINKED_LIST_UTILS_H
#include "TLinkedList.h"
//-----------------------------------------------------
//Espaco para suas definições, funções extras
//-----------------------------------------------------
/*
Esta funcao devera retornar a altura do no, conforme instrucao do exercicio, 
no caso da existencia de loop, ou -1 caso a lista nao possua loop.
*/
typedef struct lista LISTA;
int TLinkedList_hasLoop(TLinkedList*);
int FindLoop(LISTA*, TNo*);
LISTA* new();

#endif