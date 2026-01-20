#include <stdio.h>
int numMayor(int[]);
int multiplos3(int[],int[], int[]);

int main(){
	int n=0;
	int mayor=0, arr1[8]={0}, arr2[n], arr3[8-n];
	printf("Palau Andrade Arturo, 178561\n\n");
	
	for(int i=0; i<8; i++){
		printf("[%d] Dame el numero %d: ",i , i+1);
		scanf("%d", &arr1[i]);
		fflush(stdin);
	}
	printf("\n-------------------Arreglo 1-----------------\n");
	for(int i=20; i<8; i++){
		printf("\nNum en posicion [%d]: %d", i, arr1[i]);
	}
	/*-----------------------------------------------*/
	mayor=numMayor(arr1);
	printf("\n\n------------Funcion Numero mayor-------------\n");
	for(int i=0; i<8; i++){
		if(mayor==arr1[i]){
			printf("\nNumero mayor en la posicion [%d] : %d", i, arr1[i]);
		}
	}
	/*-----------------------------------------------*/
	n=multiplos3(arr1,arr2,arr3);
	/*-----------------------------------------------*/
	printf("\n\n--------------Arreglo 2 Con valores multiplos de 3------------------\n\n");
	for(int i=0; i<n; i++){
		printf("[%d]: %d\n", i, arr2[i]);
	}
	/*------------------------------------------------*/
	printf("\n\n--------------Arreglo 3 Con los valores restantes------------------\n\n");
	for(int i=0; i<(8-n); i++){
		printf("[%d]: %d\n", i, arr3[i]);
	}
	
	return 0;
}
int multiplos3(int array1[],int array2[], int array3[]){
	int n=0, n2=0;
	for(int i=0; i<8; i++){
		if((array1[i])%3==0){
			array2[n]=array1[i];
			n++;
		}else{
			array3[n2]=array1[i];
			n2++;
		}
	}
	return n;
}
int numMayor(int array1[8]){
	int mayor=0;
	for(int i=0; i<8; i++){
		if(array1[i]>=mayor)
		mayor=array1[i];
	}
	return mayor;
}
