#ifndef CIRCULAR_H
#define CIRCURLAR_H

typedef struct lista LISTA;

LISTA* newList();
int insertEnd(LISTA*, int);
int rightPosition(LISTA*, int, int);

#endif