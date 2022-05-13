#include <stdio.h>
#include "AVLTREE.h"
#include <stdbool.h>

int main(){
    int v[] = {10,5,2,20,15,30};
    AVL_Tree* T = AVL_create();
    bool a;
    for(int i = 0; i < 6;i++){
        Ins_AVL(TNo_Create(v[i]),T->root,a);
    }
    puts("Print:");
    BinTree_preorder(T->root);
    return 0;
}