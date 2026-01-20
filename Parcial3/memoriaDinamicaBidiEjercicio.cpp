#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void llena(int **bidi, int, int);
void mostrar(int **bidi, int, int);
void modif(int **bidi, int, int);

void llena(int **bidi, int filas, int columnas){
	srand(time(NULL));
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			bidi[i][j]=11+rand()%(21);
		}
	}
}
void mostrar(int **bidi, int filas, int columnas){
	for(int i=0; i<filas; i++){
		for(int j=0; j<columnas; j++){
			printf("\t%d", bidi[i][j]);
		}
		printf("\n");
	}
}
void modif(int **bidi, int filas, int columnas){
	for(int i=0; i<filas; i++){
		for(int j=0;j<columnas;j++){
			if(bidi[i][j]%3==0) bidi[i][j]-=10;
		}
	}
}
int main(){
	printf("Palau Andrade Arturo, 178561\n\n");
	
	int **bidi,fils=0,cols=0;
	
	printf("\nDame el numero de filas: ");
	fflush(stdin);
	scanf("%d",&fils);
	
	printf("\nDame el numero de columnas: ");
	fflush(stdin);
	scanf("%d",&cols);
	
	//crear(bidi,f,c);
	bidi = (int **) malloc ( fils* sizeof(int *));
	if(bidi==NULL){
		printf("\nError al asignar memoria... :(");
		exit(1);
	}
	for(int i=0; i<fils; i++){
		bidi[i]=(int *)malloc(cols*sizeof(int));
		if(bidi[i]==NULL){
			printf("\nMemoria insuficiente :( ");
			exit(1);
		}
	}
	printf("\nReserva de memoria exitosa!! \n\n");
	llena(bidi,fils,cols);
	printf("\nArreglo Llenado\n\n");
	mostrar(bidi,fils,cols);
	
	modif(bidi,fils,cols);
	printf("\nArreglo Final\n\n");
	mostrar(bidi,fils,cols);
	
	for(int i=0; i<fils; i++){
		free(bidi[i]);
	}
	free(bidi);
	return 0;
}
