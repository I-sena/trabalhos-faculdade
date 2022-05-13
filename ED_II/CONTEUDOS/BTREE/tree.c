#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    Tno* left, *rigth;
    int info, height;
}Tno;
Tno* create_No(int info){
    Tno* new = malloc(sizeof(Tno));
    if(new){
        new->left = NULL;
        new->rigth = NULL;
        new->info = info;
    }return new;
}
struct tree{
    Tno* raiz;
};
Tree* Create_Tree(){
    Tree* new = malloc(sizeof(Tree));
    if(new){
        new->raiz = NULL;
    }return new;
}

int Tree_Insert(Tree* tree, int info){
    Tno* new = create_No(info);
    if(tree == NULL || new == NULL) return 0;
    if(tree->raiz == NULL)
        tree->raiz = new;  
    else{

    }   
}

void height(Tno* no){
    int alt1, alt2;
    if(no->left != NULL)
        alt1 = no->left->height;
    else
        alt1 = 0;
    if(no->rigth != NULL)
        alt2 - no->rigth->height;
    else
        alt2 = 0;
    if(alt1 > alt2)
        no->height = alt1+1;
    else
        no->height = alt2+1;
}

Tno* Run_Tree(Tno* NoRaiz){
    Tno* Last_N;
    if(NoRaiz->left != NULL)
        Run_Tree(NoRaiz->left);
    else
        return NoRaiz;
    if(NoRaiz->rigth != NULL)
        Run_Tree(NoRaiz->rigth);
    else
        Last_N = NoRaiz;
}
