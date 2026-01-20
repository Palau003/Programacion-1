#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	printf("Palau Andrade Arturo, 178561\n\n");
	int array[7], par=0, impar=0;
	srand(time(NULL));
	
	for (int i=0; i<7; i++){
		array[i]=1+rand()%(39-1)+1;
	}
	
	printf("\n\n---------Arreglo Unidimensional----------\n\n");
	for(int i=0; i<7; i++){
		printf("[%d]: %d\n", i, array[i]);
	}
	
	printf("\n\n---------De modo invertido----------\n\n");
	for(int i=6; i>0; i--){
		printf("[%d]: %d\n", i, array[i]);
	}
	
	printf("\n\n---------Multiplo de 3----------\n\n");
	for (int i=0; i<7; i++){
		array[i]*=3;
	}
	for(int i=0; i<7; i++){
		printf("[%d]: %d\n", i, array[i]);
	}
	
	printf("\n\n---------Restando 10 a posiciones pares----------\n\n");
	for(int i=0; i<7; i++){
		if(i%2==0){
			array[i]-=10;
		}
		printf("[%d]: %d\n", i, array[i]);
	}
	
	printf("\n\n----------Valores pares--------------\n\n");
	for(int i=0; i<7; i++){
		printf("[%d]: %d", i, array[i]);
		if(array[i]%2==0){
			printf("\tPar");
			par++;
		}else impar++;
		
		printf("\n");
	}
		
	printf("Numeros pares: %d\nNumeros impares: %d", par, impar);
	
	return 0;
}
