#include <stdio.h>

int main(){
	int par=0,impar=0, n=18;
	printf("Palau Andrade Arturo, 178561\n");
	
	printf("------------Con Ciclo while-----------\n\n");
	while(n<=50){
		printf("\n%d", n);
		if(n%2==0){
			par++;
			printf("\t<---Par");
		}else{
			impar++;
			printf("\t<---Impar");
		}
		n++;
	}
	printf("\n\nTotal Pares: %d\nTotal Impares: %d", par, impar);
	/*----------------------------------------------------------*/
	printf("\n\n------------Con Ciclo for-----------\n\n");
	
	par=0; impar=0;
	for(n=18; n<=50; n++){
		printf("\n%d", n);
		if(n%2==0){
			par++;
			printf("\t<---Par");
		}else{
			impar++;
			printf("\t<---Impar");
		}
	}
	printf("\n\nTotal Pares: %d\nTotal Impares: %d", par, impar);
	
	return 0;
}
