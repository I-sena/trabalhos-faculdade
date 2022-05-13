#include<stdio.h>


float conversao(char op, float temp);

int main(){
    float temp, res;
    char op;
    scanf("%c",&op);
    switch (op)
    {
        case 'c':{
            scanf("%f",&temp);
            res=conversao(op,temp);
            printf("%.2f celsios p/ fahen",res);
            break;
        }
        case 'f':{
            scanf("%f",&temp);
            res=conversao(op,temp);
            printf("%.2f celsios p/ fahen",res);
            break;
        }
        default:{
            printf("opcao invalida");
        }
    }
    return 0;
}
float conversao(char op, float temp){
    float res;
    if(op=='c'){
         res=(1.8*temp)+(float)32;
        return res;
    }
    else if(op=='f'){
        res=(temp-(float)32)/1.8;
        return res;
    }
}
