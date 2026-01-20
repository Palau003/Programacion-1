#include <stdio.h>

int main(){
	int i=0,j=0,k=0, array[6], array2[j],array3[k], mayor=0, menor=0;
	printf("Palau Andrade Arturo, 178561\n\n");
	
	for(i=0; i<6; i++){
		printf("Dame un numero: ");
		scanf("%d", &array[i]);
		fflush(stdin);
		
		if(array[i]%3==0){
			array2[j]=array[i];
			j++;
		}else{
			array3[k]=array[i];
			k++;
		}
	}
	for(i=0; i<6; i++){
		printf("\n[%d]: %d", i, array[i]);
	}
	
	for(i=0; i<6; i++){
		if(array[i]>=mayor){
			mayor=array[i];	
		}
	}
	menor=mayor;
	
	for(i=0; i<6; i++){
		if(array[i]<=menor){
			menor=array[i];
		}
	}
	for(i=0; i<6; i++){
		if(mayor==array[i]){
			printf("\n\nValor mayor--> [%d]: %d", i, array[i]);	
		}if(menor==array[i]){
			printf("\n\nValor menor--> [%d]: %d", i, array[i]);
		}
	}
	
	printf("\n\n------------Arreglo 1-----------");
	for(i=0; i<6; i++){
		printf("\n[%d]: %d", i, array[i]);
	}
	printf("\n\n------------Arreglo 2 con valores multiplos de 3-----------");
	for(i=0; i<j; i++){
		printf("\n[%d]: %d", i, array2[i]);
	}
	printf("\n\n------------Arreglo 3 con los valores restantes-----------");
	for(i=0; i<k; i++){
		printf("\n[%d]: %d", i, array3[i]);
	}
	
	return 0;
}
