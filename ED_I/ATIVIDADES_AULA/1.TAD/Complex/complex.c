#include <stdlib.h>
#include <stdio.h>
#include "complex.h"

// 1. Um número complexo é escrito na forma x+iy onde i2=−1 sendo x sua parte real e y
// a parte imaginária (tanto x quanto y são números reais). Crie um TAD que represente os
// números complexos com as seguintes funções de interface:

struct Complex{
  float x, y;  
};

// a) criar um número complexo (recebendo os parâmetros x e y);
complex* newComplex(float x, float y){
    complex* new = malloc(sizeof(complex));
    if(new){
        new->x = x;
        new->y = y;
    }
    return new;
}

// b) destruir um número complexo;
void deleteComplex(complex* num){
    free(num);
}

// c) soma dois números complexos (recebe dois tipos e retorna um novo tipo que é a soma);
complex* somaComplex(complex* n1, complex* n2){
    complex* new = newComplex(n1->x + n2->x, n1->y + n2->y);
    return new;
}

// d) subtração de números complexos (mesma interface da c));
complex* subComplex(complex* n1, complex* n2){
    complex* new = newComplex(n1->x - n2->x, n1->y - n2->y);
    return new;
}

void printComplex(complex* num){
    printf("%.1f, %.1f\n",num->x, num->y);
}
