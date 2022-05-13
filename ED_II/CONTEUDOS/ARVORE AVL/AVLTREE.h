#ifndef AVLTREE_H
#define AVLTREE_H
#include <stdbool.h>

typedef struct no{
    struct no* left;
    struct no* right;
    struct no* p;
    int key;
    int balance;
}Tno;

typedef struct{
    Tno* root;
}AVL_Tree;

Tno* TNo_Create(int);
AVL_Tree* AVL_create();
_Bool insert(Tno**,Tno*);
_Bool Ins_AVL(Tno*,Tno*,bool*);
bool case_1(Tno*,bool*);
bool case_2(Tno*,bool*);
void BinTree_preorder(Tno* root);


#endif