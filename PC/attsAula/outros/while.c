#include<stdio.h>
int main(){

    int v[15],i,c,me,vme=0,vma=0,ma,nv[15],j,gMA,gME;
    scanf("%d",&v[0]);
    me=v[0];
    ma=v[0];
    c=1;
    while(c!=15){
        scanf("%d",&v[c]);
        if(v[c]>ma){
            ma=v[c];
            vma=c;
        }
        else if(v[c]<me){
            me=v[c];
            vme=c;
        }
        c++;
    }

    for(i=0, j=13; i<7, j>0; i++, j=j-2){
        nv[i]=v[j];
    }
        
    for(i=7,j=0; i<15, j<15; i++, j=j+2){
        if(i==7){
            nv[i]=v[vme];
        }
        else if(i==14){
            nv[i]=v[vma];
        }
        else{
                nv[i]=v[j];
        }
    }
    
    for(i=0; i<15; i++){
        printf("V[%d] = %d\n",i,nv[i]);
    }

    return 0;
}
