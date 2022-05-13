#include "AVLTREE.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


Tno* TNo_Create(int key){
    Tno* new = malloc(sizeof(Tno));
    if(new){
        new->balance = 0;
        new->key = key;
        new->left = NULL;
        new->p = NULL;
        new->right = NULL;
    }return new;
}
AVL_Tree* AVL_create(){
    AVL_Tree* new = malloc(sizeof(AVL_Tree));
    if(new){
        new->root = NULL;
    }return new;
}
_Bool insert(Tno** root,Tno* z){
    int k = z->key;
    if((*root) == NULL){
        *root = z;
        return true;
    }
    z->p = *root; 
    if (k < (*root)->key)
        return BinTree_insert_r(&(*root)->left, z);
    else
        return BinTree_insert_r(&(*root)->right, z);
}

_Bool Ins_AVL(Tno* New,Tno* root,bool* a){
    if(root == NULL){
        root = New;
        a = true;
    }
    else{
        if (root->key == New->key) return false;
        if(New->key < root->key){
            Ins_AVL(New,root->left,a);
            if(a){
                if(root->balance == 1){
                    root->balance = 0;
                    a = false;
                }
                else if(root->balance == 0)
                    root->balance = -1;
                else if(root->balance == -1)
                    case_1(root,a);
            }
        }else{
            Ins_AVL(New,root->right,a);
            if(a){
                if(root->balance == -1){
                    root->balance = 0;
                    a = false;
                }
                else if(root->balance == 0)
                    root->balance = 1;
                else if(root->balance == 1)
                    case_2(root,a);
            }
        }
    }
}

bool case_1(Tno* root,bool* h){ // CODIGO DAS ROTAÇÕES
    Tno* ptu = root->left;
    if(ptu->balance == -1){         //SIMPLES
        root->left = ptu->right;
        ptu->right = root;
        root->balance = 0;
        root = ptu;
    }else{                              //DUPLA
        ptu = ptu->right;
        ptu->right = ptu->left;
        ptu->left = ptu;
        root->left = ptu->right;
        ptu->right = root;
        if(ptu->balance == -1)
            root->balance = 1;
        else
            root->balance = 0;
        if(ptu->balance == 1)
            ptu->balance = -1;
        else
            ptu->balance = 0;
        root = ptu;
    }
    root->balance = 0;
    h = false;
}

bool case_2(Tno* root,bool* h){
    Tno* ptu = root->right;
    if(ptu->balance == 1){              //SIMPLES
        root->right = ptu->left;
        ptu->left = root;
        root->balance = 0;
        root = ptu;
    }else{                              //DUPLA
        ptu = ptu->left;
        ptu->left = ptu->right;
        ptu->right = ptu;
        root->right = ptu->left;
        ptu->left = root;
        if(ptu->balance == 1)
            root->balance = -1;
        else
            root->balance = 0;
        if(ptu->balance == -1)
            ptu->balance = 1;
        else
            ptu->balance = 0;
        root = ptu;
    }
    root->balance = 0;
    h = false;
}

void BinTree_preorder(Tno* root){
  if(root != NULL){
    printf("%d, ", root->key);
    BinTree_preorder(root->left);
    BinTree_preorder(root->right);
  }
}