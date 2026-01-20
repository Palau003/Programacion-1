#include <stdio.h>



int main(){
    printf("Palau Andrade Arturo, 178561\n\n");
    
    int b1[3][3]={{1,1,2},{0,1,3},{2,0,0}}, b2[3][3]={{1,2,0},{0,1,2},{2,0,1}}, bidi3[3][3]={0};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", b1[i][j]);
        }
        printf("\n");
    }printf("\n\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", b2[i][j]);
        }
        printf("\n");
    }printf("\n\n");
    printf("\n\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            bidi3[i][j]=((b1[i][0]*b2[0][j])+(b1[i][1]*b2[1][j])+(b1[i][2]*b2[2][j]));
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf(" %d ", bidi3[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
