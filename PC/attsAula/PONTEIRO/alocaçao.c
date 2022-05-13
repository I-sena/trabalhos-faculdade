#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    int *p,*p1;
    p= (int*) malloc(5* sizeof(int));
    p1= (int*) calloc(5, sizeof(int));
    printf("calloc \t\t malloc\n");
    for(i=0;i<5;i++){
        printf("Malloc p [%d]= %d\t",i,p[i]);
        printf("Calloc p1 [%d]= %d\n",i,p1[i]);
    }

    system("pause");
    return 0;
}