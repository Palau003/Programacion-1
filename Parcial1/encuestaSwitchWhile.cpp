#include <stdio.h>



int main(){
    int choc=0,fres=0, romp=0, opc=0, i=0;
    printf("Palau Andrade Arturo, 178561");
    
    while(i<30){
        printf("\n\t1)Chocolate\t)Fresa\t3)Rompope\n\nEncuesta Numero %d) Seleccione el No. de pastel que mas le guste-->", i+1);
        scanf("%d", &opc);
        switch(opc){
            case 1: choc++;
                    break;
            case 2: fres++;
                    break;
            case 3: romp++;
                    break;
            default: printf("\nOpcion no valida");
                    break;
        }
        i++;
    }
    printf("\n\nResultado final de la encuesta: \nChocolate: %d\tFresa: %d\tRompope: %d", choc, fres, romp);
    
    return 0;
}
