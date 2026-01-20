#include <stdio.h>

int main(){
    printf("Palau Andrade Arturo, 178561\n\n");
    
    float resul=0, bidi[2][3]={0};
    
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            bidi[i][j]=j+2;
        }
        printf("\n");
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            resul+=bidi[i][j];
            printf("[%d][%d]: %.2f\t", i, j, bidi[i][j]);
        }
        printf("\n");
    }
    printf("\nSuma= %.2f", resul);
    
    return 0;
}
