#include<stdio.h>
#include<math.h>

float distancia(float x1, float y1, float x2, float y2);

int main(){

    float x1,x2,y1,y2;
    float res;

    scanf("%f %f",&x1, &y1);
    scanf("%f %f",&x2, &y2);
    res=distancia(x1,y1,x2,y2);
    printf(" %.2f",res);

    return 0;
}


float distancia(float x1, float y1, float x2, float y2){
    float resx,resy,retur;

    resx=(x2-x1)*(x2-x1);
    resy=(y2-y1)*(y2-y1);
    retur=sqrt(resx+resy);

    return retur;
}
