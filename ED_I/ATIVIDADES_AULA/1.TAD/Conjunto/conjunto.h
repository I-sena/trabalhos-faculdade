#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct Conjunto conj;

conj* new(int);

void newdata(conj*,int);

void print(conj*);

void deleteC(conj*, int);

conj* interscConj(conj*, conj*);

conj* difeConj(conj*, conj*);


#endif