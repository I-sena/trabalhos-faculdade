#include "redblack.h"
#include <stdio.h>

void print(redblack* t){
    puts("PRE:");
    Redblack_preorder(t->root,t->Nill);
    puts("");
    puts("SIMETRICA:");
    Redblack_simetrica(t->root,t->Nill);
}
int main(){
    redblack* t = Create_RB();
    int v[] = {12, 5, 2, 9, 18, 20, -1, -5};
    for(int i = 0; i < 8;i++){
        if(!RB_Insert(t,v[i]))
            puts("ERROR");
    }
    print(t);
    return 0;
}