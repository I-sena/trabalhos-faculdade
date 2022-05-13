#include "stack_static.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

struct stack{      
    int index;
    int cars[MAX];
};

Stack* Stack_create(){
    Stack* new = malloc(sizeof(Stack));
    if(new){
        new->index = -1;
    }return new;
}

int PushMain(Stack* carPark,int carID){
    if(!IsFull(carPark)){
        carPark->cars[++carPark->index] = carID;
        return -1;
    }return 0;
}

int PopMain(Stack* carPark,int* owner){
    if(!IsEmpty(carPark)){
        *owner = carPark->cars[carPark->index--];
        return -1;
    }return 0;
}

int pushSecondary(Stack* carpark_sec,int carID){
    if(!IsFull(carpark_sec)){
        carpark_sec->cars[++carpark_sec->index] = carID;
        return -1;
    }return 0;
}

int popSecondary(Stack* carpark_Sec,Stack* mainCarpark){
    if(!IsEmpty(carpark_Sec)){
        while(carpark_Sec->index > -1){
            mainCarpark->cars[++mainCarpark->index] = carpark_Sec->cars[carpark_Sec->index--];
        }return -1;
    }return 0;
}

int IsFull(Stack* carPark){
    return carPark->index == MAX-1;
}

int IsEmpty(Stack* carPark){
    return carPark->index == -1;
}

void Stack_Destroy(Stack* CarPark){
    free(CarPark);
}