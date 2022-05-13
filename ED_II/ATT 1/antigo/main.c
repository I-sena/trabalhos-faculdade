#include "BT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CHAR_TO_INT(char* numero,int qty){
    char *new, *token;
    int key;
    if(qty == 0){
        token = strtok(numero,"() ");
        key = strtol(token,&new,10);
    }else{        
        token = strtok(NULL,"() ");
        if(token != NULL){
          key = strtol(token,&new,10);
            return key;
        }
    }
}


int main(){
    int i = 1, countPT = 0, key, LR[1000],Count=0,p = 1;
    BinTree* New_Tree = BinTree_create();
    char P_tree[4097] = "(7(5()(6))(10()(12)))";
    char aux[strlen(P_tree)];
    strcpy(aux,"");
    strcat(aux,P_tree);

    int CountNO = 0, novazio =0;
    while(strncmp(&P_tree[countPT],"\n",strlen("\n")) && strncmp(&P_tree[countPT],"\0",strlen("\n"))){
        if(!strncmp(&P_tree[countPT],"(",strlen("(")) || !strncmp(&P_tree[countPT],")",strlen(")"))){
            CountNO++;
            if(!strncmp(&P_tree[countPT],"(",strlen("(")) && !strncmp(&P_tree[countPT+1],")",strlen(")"))){
                novazio++;
            }
        }
    }
    printf("%d %d",CountNO,novazio);
    /*printf("PREORDER: ");
    BinTree_preorder(New_Tree->root);
    printf("\nINORDER: ");
    BinTree_inorder(New_Tree->root);*/
    return 0;
}