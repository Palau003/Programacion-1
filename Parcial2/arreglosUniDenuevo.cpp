#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){
	int array[9], array2[9], array3[9];
	printf("Palau Andrade Arturo, 178561\n\n");
	srand(time(NULL));
	
	for(int i=0; i<9; i++){
		array[i]=5+rand()%(20-5)+1;
	}
	for(int i=0; i<9; i++){
		if(array[i]%5==0){
			array2[i]=array[i];
			array2[i]*=3;
		}else array2[i]=array[i];
		array3[i]=(array[i]+array2[i]);
	}
	printf("Arreglo 1");
	for(int i=0; i<9; i++){
		printf("\t%d", array[i]);
		if(array[i]%2==0){
			system("COLOR 3");
			printf(" Rojo");
		}else{
			system("COLOR 2");
			printf(" Rosa");
		}
	}
	printf("\nArreglo 2");
	for(int i=0; i<9; i++){
		printf("\t%d", array2[i]);
		if(array2[i]%2==0){
			system("COLOR 3");
			printf(" Rojo");
		}else{
			system("COLOR 2");
			printf(" Rosa");
		}
	}
	printf("\nArreglo 3");
	for(int i=0; i<9; i++){
		printf("\t%d", array3[i]);
		if(array3[i]%2==0){
			system("COLOR 3");
			printf(" Rojo");
		}else{
			system("COLOR 2");
			printf(" Rosa");
		}
	}
	printf("\n\nPares ---> Rojo\nImpares ----> Rosa");
	
	return 0;
}
