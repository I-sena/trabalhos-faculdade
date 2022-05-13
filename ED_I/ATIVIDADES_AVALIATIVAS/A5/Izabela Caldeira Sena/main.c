#include<stdio.h>
#include"stack_static.h"

int main(){
    int id_Car;
    char op;
    Stack* MainCarpark = Stack_create();
    Stack* secondaryCarpark = Stack_create();
    scanf("%c %d",&op,&id_Car);
    do{
        if(op == 'i' || op == 'I'){
            if(!PushMain(MainCarpark,id_Car))
                printf("overflow\n");
        }
        else if(op == 'r' || op == 'R'){
            int owner = id_Car+1;
            while(owner != id_Car){
                if(!PopMain(MainCarpark,&owner)){
                    printf("underflow\n");
                    break;
                }
                printf("%d,",owner);
                if(owner != id_Car)
                    pushSecondary(secondaryCarpark,owner);
                else 
                    puts("");
            }
            popSecondary(secondaryCarpark,MainCarpark);
        }
        else
            printf("ERRO: opcao invalida.\n");
        scanf(" %c %d",&op,&id_Car);
    }while(!(op == '0' && id_Car == 0));
    Stack_Destroy(MainCarpark);
    Stack_Destroy(secondaryCarpark);
    return 0;
}