#include "Section.h"
#include "Grade.h"
#include "Course.h"
#include <stdio.h>

void _Right_Way_(int,int);
void _Status_(int);

int main(){
    int DataTypes, OperationType, op, IsValid = 0;
    do{
        puts("---------------------- MENU ----------------------");
        printf("QUAL TIPO DE OPERACAO \?\n");   
        while(!IsValid){
            printf("| 1. CREATE | 2. READ | 3. UPDATE | 4. DELETE | \n-> ");
            scanf("%d",&OperationType);
            if(OperationType >= 1 && OperationType <= 4)
                IsValid = 1;
            else
                printf("OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
        }
        printf("QUAL O TIPO DE DADO \?\n");
        while(IsValid){
            printf("| 1. COURSE | 2. GRADE | 3. SECTION |\n-> ");
            scanf("%d",&DataTypes);
            if(DataTypes >= 1 && DataTypes <= 3)
                IsValid = 0;
            else
                printf("OPCAO INVALIDA, DIGITE NOVAMENTE!\n");
        }
        puts("-------------------------------------------------------");
        _Right_Way_(OperationType,DataTypes);
        printf("\nDESEJA REALIZAR UMA NOVA OPERACAO? <1> SIM OU <0> NAO: ");
        scanf("%d%*c",&op);
    }while(op == 1);
    return 0;
}

void _Right_Way_(int OperationType,int DataTypes){
    if(OperationType == 1){                                 //CREATE
        if(DataTypes == 1)
            _Status_(Create_New_Course());
        else if(DataTypes == 2)
            _Status_(Create_New_Grade());
        else
            _Status_(Create_New_Section());
    }
    else if(OperationType == 2){                            //READ
        if(DataTypes == 1)
            _Status_(Print_Course());
        else if(DataTypes == 2)
            _Status_(Print_Grade());
        else
            _Status_(Print_Section());
    }
    else if(OperationType == 3){                         //UPDATE
        if(DataTypes == 1)
            _Status_(Update_Course());
        else if(DataTypes == 2)
           _Status_(Update_Grade());
        else
           _Status_(Update_Section());
    }
    else{                                               //DELETE
        if(DataTypes == 1)
            _Status_(Delete_Course());
        else if(DataTypes == 2)
            _Status_(Delete_Grade());
        else
            _Status_(Delete_Section());       
    }
}

void _Status_(int retorno){
    if(retorno == 0){
        printf("\n| OPERACAO EFEITUADA COM SUCESSO! |\n");
    }
    
    else if(retorno == 1){
        printf("\n| ERROR! |\n");
    }
}