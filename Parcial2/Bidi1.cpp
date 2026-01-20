#include <stdio.h>

int main(){
    printf("Palau Andrade Arturo, 178561\n\n");
    
    float bidi[2][3]={0};
    
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("Dame un numero: ");
            scanf("%f", &bidi[i][j]);
            fflush(stdin);
        }
        printf("\n");
    }
    for(int i=1; i>=0; i--){
        for(int j=2; j>=0; j--){
            printf("[%d][%d]: %.2f\t", i, j, bidi[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
