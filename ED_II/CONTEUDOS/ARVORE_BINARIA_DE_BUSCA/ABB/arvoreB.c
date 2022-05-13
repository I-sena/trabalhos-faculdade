#include "arvoreB.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int key;
    struct no* left;
    struct no* rigth;
    struct no* parent;
}Tno;

Tno* Create_No(int key){
    Tno* new = malloc(sizeof(Tno));
    if(new){
        new->key = key;
        new->left = NULL;
        new->rigth = NULL;
        new->parent = NULL;
    }
    return new;
}

struct tree{
    struct no* root;
};

Btree* Create_Tree(){
    Btree* new = malloc(sizeof(Btree));
    if(new){
        new->root = NULL;
    }
    return new;
}

Tno* Tree_Search( Tno* no, int key){
    if ( no == NULL || no->key == key)
        return no;
    if ( key < no->key)
        return Tree_Search( no->left, key);
    else
        return Tree_Search( no->rigth,key);
} 

Tno* Iterative_tree_search( Tno* no, int key){
    while ( no != NULL && key != no->key){
        if ( key < no->key)
            no = no->left;
        else
            no = no->rigth;
    }   
    return no;
}

Tno* Tree_Mininum(Tno* no){
    while( no->left != NULL)
        no = no->left;
    return no;
}

Tno* Tree_Maximum(Tno* no){
    while ( no->rigth != NULL)
        no = no->rigth;
    return no;
}

Tno* Tree_Successor(Tno* no){
    if(no->rigth != NULL)
        return Tree_Mininum(no->rigth);
    Tno* y = no->parent;
    while (y != NULL && no == y->rigth){
        no = y;
        y = y->parent;
    }
    return y;
}

int Tree_insert(Btree* tree, Tno* new){
    if(tree == NULL || new == NULL)  return 1;
    Tno* y = NULL;
    Tno* x = tree->root;
    while (x != NULL){
        y = x;
        if (new->key < x->key)
            x = x->left;
        else
            x = x->rigth;
    }
    new->parent = y;
    if (y == NULL)
        tree->root = new;
    else if(new->key < y->key)
        y->left = new;
    else
        y->rigth = new;
    return 0;
}

void Transplant(Btree* tree,Tno* one,Tno* two){
    if (one->parent == NULL)
        tree->root = two;
    else if (one == one->parent->left)
        one->parent->left = two;
    else
        one->parent->rigth = two;
    if (two != NULL)
        two->parent = one->parent;
}

void Tree_Delete(Btree* tree,Tno* delete){
    Tno* y;
    if(delete->left == NULL)
        Transplant(tree,delete,delete->rigth);
    else if (delete->rigth == NULL)
        Transplant(tree,delete,delete->left);
    else
        y = Tree_Mininum(delete->rigth);
        if(y->parent != delete){
            Transplant(tree,y,y->rigth);
            y->rigth = delete->rigth;
            y->rigth->parent = y;
        }
        Transplant(tree,delete,y);
        y->left = delete->left;
        y->left->parent = y;
}
