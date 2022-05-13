#include "BT.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

void Transplant(BinTree*, TNo*, TNo*);

BinTree* BinTree_create(){
    BinTree* tree = malloc(sizeof(BinTree));
    if(tree != NULL){
        tree->root = NULL;
    }return tree;
}

TNo* TNo_createNFill(int key){
    TNo* node = malloc(sizeof(TNo));
    if(node != NULL){
        node->p = NULL;
        node->left = NULL;
        node->right = NULL;
        node->key = key;
    }   return node;
}

_Bool BinTree_insert_r(TNo** root, TNo* z,int* path,int position){
  if((*root) == NULL){
    *root = z;
    return true;
  }
  z->p = *root; 
    printf("funco path[%d] = %d\n",position,path[position]);
  if (path[position] == 1)
    return BinTree_insert_r(&(*root)->left, z,path,position+1);
  else
    return BinTree_insert_r(&(*root)->right, z,path, position+1);
}

void BinTree_preorder(TNo* root){
    if(root != NULL){
        printf("%d, ", root->key);
        BinTree_preorder(root->left);
        BinTree_preorder(root->right);
    }
}

void BinTree_inorder(TNo* root){
    if(root != NULL){
        BinTree_inorder(root->left);
        printf("%d, ", root->key);
        BinTree_inorder(root->right);
    }
}