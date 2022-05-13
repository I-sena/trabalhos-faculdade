#include "fracao.h"
#include <stdlib.h>
#include <stdio.h>

// 2. Crie um TAD que represente os números racionais (frações) que contenha as seguintes
// funções de interface:

struct Fracao{
    int num, deno;
    float theN;
};

// a) Cria racional (recebe dois inteiros: numerador e denominador);
fracao* newNum (int up, int down){
    fracao* new = malloc(sizeof(fracao));
    if (new){
        new->num = up;
        new->deno = down;
        new->theN = (float)up/down;
    }return new;
}

// b) Soma dois números racionais (um novo elemento deve ser criado contendo a soma dos
// dois);
fracao* somaNum (fracao* n1, fracao* n2){ //ERRADO
    fracao* new = newNum(n1->num + n2->num, n1->deno + n2-> deno);
    return new;
}

// c) Multiplica dois números racionais (mesma interface da letra b)).
fracao* multNum(fracao* n1,fracao* n2){
    fracao* new = newNum(n1->num*n2-> num, n1->deno*n2-> deno);
    return new;
}

// d) Testa se são iguais.
void SameNumber(fracao* n1, fracao* n2){
    if(n1->num == n2->num){
        if(n1->deno == n2->deno)
            printf("mesmo numero.\n");
    }
    else
        printf("numeros diferentes.\n");
}

void print(fracao* num){
    printf("-> %d/%d \nnumerador=%d, denominador= %d, resultado= %.1f\n",num->num,num->deno,num->num,num->deno,num->theN);
}

void deleteN(fracao* nm){
    free(nm);
}

