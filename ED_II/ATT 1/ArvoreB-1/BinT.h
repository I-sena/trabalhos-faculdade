#ifndef BINT_H
#define BINT_H
#include <stdbool.h>

typedef struct no{
    struct no* left;
    struct no* right;
    struct no* p;
    int key;
}Tno;

typedef struct {
    Tno* root;
}Bintree;

Tno* Tno_CreateNFill(int);
Bintree* Create_bintree();
_Bool insert(Tno**,char*,int);
void print_inorder(Tno*);
void Print_preorder(Tno*);

#endif