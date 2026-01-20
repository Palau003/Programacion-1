#include <stdio.h>

int main(){
	printf("Palau Andrade Arturo, 178561 \n");
	float radio=0.0, resul=0.0;
	
	printf("\nDame el radio: ");
	scanf("%f", &radio);
	
	if (radio <= 8) {
		resul=(radio+radio)*(3.1416);
		printf("El perimetro del circulo es: %.2f", resul);
	}else{
		resul=(3.1416*radio*radio);
		printf("\nEl area del circulo es: %.2f", resul);
	}
	return 0;
}
