#include <stdio.h>

int main(void){
    int rectA[5];
    int rectB[5];
    int cont = 0;

    printf("digite as cordenadas do retangulo conforme as posicoes indicadas:\n\t1 2 3 4\n\tX Y;X Y" );
    for(int i = 0;i<=3;i++){
        printf("\ndigite a cordenada da posicao %d do retangula A :",i+1);
        scanf("%d",&rectA[i]);
    }
    for(int i = 0;i<=3;i++){
        printf("\ndigite a cordenada da posicao %d do retangula B : ",i+1);
        scanf("%d",&rectB[i]);
    }
    printf("\n");
    if(rectA[0]>=rectB[0] && rectA[0]<=rectB[2])
        cont ++;
    else if(rectA[0]<=rectB[0] && rectA[0]>=rectB[2])
        cont ++;
    else if(rectA[2]>=rectB[0] && rectA[2]<=rectB[2])
        cont ++;
    else if(rectA[2]<=rectB[0] && rectA[2]>=rectB[2])
        cont ++;

    if(cont>0){
       if(rectA[1]>=rectB[1] && rectA[1]<=rectB[3])
        printf("intersects(A,B)=>true");
        else if(rectA[1]<=rectB[1] && rectA[1]>=rectB[3])
            printf("intersects(A,B)=>true");
        else if(rectA[3]>=rectB[1] && rectA[3]<=rectB[3])
            printf("intersects(A,B)=>true");
        else if(rectA[3]<=rectB[1] && rectA[3]>=rectB[3])
            printf("intersects(A,B)=>true");
        else{ 
            printf("intersects(A,B)=>false");
        }
    }
    else{ 
        printf("intersects(A,B)=>false");
    }
    return 0;    
}