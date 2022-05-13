#include "redblack.h"
#include <stdio.h>
#include <stdlib.h>

TNo* CreateNFill(int key){
    TNo* NewTNo = malloc(sizeof(TNo));
    if(NewTNo){
        NewTNo->key = key;
    }return NewTNo;
}

redblack* Create_RB(){
    redblack* New = malloc(sizeof(redblack));
    if(New){
        New->Nill = CreateNFill(0);
        if(New->Nill == NULL){
            free(New);
            return NULL;
        }
        New->Nill->color = BLACK;
        New->root = New->Nill;
    }return New;
}

int RB_Insert(redblack* T, int key){
    TNo* z = CreateNFill(key);
    if( z == NULL || T == NULL) return 0;
    TNo* y = T->Nill;
    TNo* x = T->root;
    while (x != T->Nill){
        y = x;
        if (z->key < x->key)     x = x->right;
        else    x = x->left;
    }
    z->parent = y;
    if (y == T->Nill)    T->root = z;
    else 
        if (z->key < y->key)   y->right = z;
        else    y->left = z;
    z->left = T->Nill;
    z->right = T->Nill;
    z->color = RED;
    RB_Insert_Fixup(T,&z);
    return 1;
}

void Left_Rotate(redblack* T,TNo* x){
    TNo* y = x->right;
    x->right = y->left;
    if (y->left != T->Nill)    y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == T->Nill)    T->root = y;
    else 
        if (x == x->parent->left)  x->parent->left = y;
        else    x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void Right_Rotate(redblack* T, TNo* y){
    TNo* x = y->left;
    y->left = x->right;
    if(x->right != T->Nill)     x->right->parent = y;
    x->parent = y->parent;
    if(y->parent == T->Nill)    T->root = x;
    else 
        if(y == y->parent->right)  y->parent->right = x;
        else    y->parent->left = x;
    x->right = y;
    y->parent = x;  
}

void RB_Insert_Fixup(redblack* T, TNo** z){
    while ((*z)->parent->color == RED){
        if ((*z)->parent == (*z)->parent->parent->left){
            TNo* y = (*z)->parent->parent->right;
            if (y->color == RED){
                (*z)->parent->color = BLACK;
                y->color = BLACK;
                (*z)->parent->parent->color = RED;
                *z = (*z)->parent->parent;
            }else{
                if ((*z) == (*z)->parent->right){
                    z = &(*z)->parent;
                    Left_Rotate(T,*z);
                }
                (*z)->parent->color = BLACK;
                (*z)->parent->parent->color = RED;
                Right_Rotate(T, (*z)->parent->parent);
            }
        }else{
            TNo* y = (*z)->parent->parent->left;
            if(y->color == RED){
                (*z)->parent->color = BLACK;
                y->color = BLACK;
                (*z)->parent->parent->color = RED;
                *z = (*z)->parent->parent;
            }else{
                if((*z) == (*z)->parent->left){
                    z = &(*z)->parent;
                    Right_Rotate(T,*z);
                }
                (*z)->parent->color = BLACK;
                (*z)->parent->parent->color = RED;
                Left_Rotate(T,(*z)->parent->parent);
            }
        }
    }
    T->root->color = BLACK;
}

void Redblack_preorder(TNo* root,TNo* Nill){
  if(root != Nill){
    printf("%d, ", root->key);
    if(root->color == 1)    puts("RED");
    else    puts("BLACK");
    Redblack_preorder(root->left,Nill);
    Redblack_preorder(root->right,Nill);
  }
}

void Redblack_inorder(TNo* root, TNo* NIll){
  if(root != NIll){
    Redblack_inorder(root->left,NIll);
    printf("%d, ", root->key);
    if(root->color == 1)    puts("RED");
    else    puts("BLACK");
    Redblack_inorder(root->right,NIll);
  }
}

void Redblack_simetrica(TNo* root,TNo* nil){
    if(root->left != nil)
        Redblack_simetrica(root->left,nil);
    printf("%d  ", root->key);
    if(root->color == 1)    puts("RED");
    else    puts("BLACK");
    if(root->right != nil)
        Redblack_simetrica(root->right,nil);
}
