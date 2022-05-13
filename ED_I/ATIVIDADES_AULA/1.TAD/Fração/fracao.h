#ifndef FRACAO_H
#define FRACAO_H

typedef struct Fracao fracao;

fracao* newNum(int, int);

fracao* somaNum(fracao*, fracao*);

fracao* multNum(fracao*,fracao*);

void SameNumber(fracao*, fracao*);

void print(fracao*);

void deleteN(fracao*);

#endif