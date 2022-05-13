#include <stdio.h>
#include "BinT.h"
#include <string.h>
int main(){
    char str[4097];
    fgets(str, 4097, stdin);
    int a=0;
    for(int i =0;i <=strlen(str);i++){
        if(str[i] == '\n'){
            a =2; 
            break;}
        else if(str[i] == '\0'){
            a=1;
            break;}
    }
    Bintree* tree = Create_bintree();
    insert(&(tree)->root,str,a);
    if(alltree(tree->root))
        printf("bst");
    else
        printf("notBst");


    return 0;
}


