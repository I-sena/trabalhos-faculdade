#include "BinT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Tno* Tno_CreateNFill(int key){
    Tno* node =  malloc(sizeof(Tno));
    if(node){
        node->key = key;
        node->left = NULL;
        node->p = NULL;
        node->right = NULL;
    }return node;
}
Bintree* Create_bintree(){
    Bintree* new = malloc(sizeof(Bintree));
    if(new){
        new->root = NULL;
    }return new;
}
_Bool insert(Tno** root,char* str,int a){
    char *new, *token,aux[strlen(str)];
    Tno* path[strlen(str)];
    strcpy(aux,"");
    strcat(aux,str);
    int key,count = -1;
    int L_empty = 0, R_empty = 0;
    token = strtok(str,"() ");
    key = strtol(token,&new,10);
    Tno* node = Tno_CreateNFill(key);
    for(int i = 2; i < (strlen(aux))-a; i++){
        if(aux[i] == '\n') break;
        if(!strncmp(&aux[i],"(",strlen("("))){
                count++;
                path[count] = node;
        }
        else if(!strncmp(&aux[i],")",strlen(")"))){
            if(!strncmp(&aux[i-1],"(",strlen("("))){
                if(!strncmp(&aux[i+1],"(",strlen("("))){ //NO DA ESQUERDA É VAZIO
                    L_empty = 1;
                    R_empty = 0;
                }
                else if(!strncmp(&aux[i+1],")",strlen(")"))){
                    R_empty = 1;
                    L_empty = 0;
                }
            }
            else{
                L_empty = 0;
                R_empty = 0;
            }
            node = path[count];
            count--;
        }
        else if(!strncmp(&aux[i-1],"(",strlen("("))){
            token = strtok(NULL,"() ");
            if(token != NULL){
                key = strtol(token,&new,10);
                if(node->left == NULL && L_empty == 0){
                    Tno* leftNode = Tno_CreateNFill(key);
                    node->left = leftNode;
                    leftNode->p = node;
                    node = leftNode;
                }
                else if(node->right == NULL && R_empty == 0){
                    Tno* rightNode = Tno_CreateNFill(key);
                    node->right = rightNode;
                    rightNode->p = node;
                    node = rightNode;
                }
            }
        }
    }
    (*root) = node;
    return true;
}

void print_inorder(Tno* node){
    if(node){
        print_inorder(node->left);
        printf("%d, ",node->key);
        print_inorder(node->right);
    }
}
void Print_preorder(Tno* node){
    if(node){
        printf("%d, ",node->key);
        Print_preorder(node->left);
        Print_preorder(node->right);
    }
}
_Bool IsBTree(Tno* node,int key){
    if(node){
        if (node->left != NULL && key < node->left->key)
            return false;
        if(node->right != NULL && key > node->right->key)
            return false;
        IsBTree(node->left,key);
        IsBTree(node->right,key);
    }return false;
}
_Bool alltree(Tno* node){
    if(node){
        if(IsBTree(node,node->key)){
            alltree(node->left);
            alltree(node->right);
            return true;
        }
    }return false;
}