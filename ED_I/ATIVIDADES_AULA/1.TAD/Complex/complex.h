#ifndef COMPLEX_H
#define COMLPLEX_H

typedef struct Complex complex;

complex* newComplex(float, float);

void deleteComplex(complex*);

complex* somaComplex(complex*, complex*);

complex* subComplex(complex*, complex*);

void printComplex(complex*);

#endif 