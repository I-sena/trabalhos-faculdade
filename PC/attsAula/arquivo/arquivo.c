#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* p;
    int n = 0;
    p = fopen("myfile.txt","rb");
    if(p == NULL)
        perror("ERRO ");
    else{
        while(fgetc(p) != EOF)
            n++;
        if(feof(p)){
            puts("final arquivo");
            printf("total de bytes lidos: %d\n",n);       
        }
        else{
            puts("final do arquivo");
            fclose(p);
        }
    }
    return 0;
}