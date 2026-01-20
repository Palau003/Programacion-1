#include <stdio.h>
#include <stdlib.h>
#define FILAS 5
void llena(int **MatrizNum, int COLS);
void mostrar(int **MatrizNum, int COLS);
int main(){
	int x,y,COLS;
	int **MatrizNum; //puntero doble para la matriz de calificaciones
	printf ("numero de calificaciones ");
	scanf("%d",&COLS); //reserva de memoria dinamica
	MatrizNum = (int **)malloc (FILAS*sizeof(int *));  //reserva de memoria para las filas
	if(MatrizNum==NULL){
		printf("No hay memoria suficiente ");
		exit (1);
	}
	for(x=0;x<FILAS;x++){ //cada fila tiene un numero de columnas
		MatrizNum[x] = (int *) malloc (COLS*sizeof(int));   // Revisamos los malloc para cada columna
		if(MatrizNum[x] == NULL){
			printf("No hay memoria suficiente\n");
			return -1;
		}
	}
	printf("\n\nRESERVA DE MEMORIA EXITOSA PODEMOS CONTINUAR \n\n");
	
	llena(MatrizNum,COLS);
	mostrar(MatrizNum,COLS); // liberamos la memoria que habíamos reservado para la matriz en 2 partes
	
	for (x=0;x<FILAS;x++){  //liberamos la memoria para todas las filas
		free(MatrizNum[x]);
	}
	free (MatrizNum);  //liberamos la memoria del vector de vectores
	
	return 0;
}
void llena(int **MatrizNum, int COLS){
	int x,y;  // llenamos la matriz
	
	for(x=0;x<FILAS;x++){
		for (y=0;y<COLS;y++){
			printf("Dame un numero ");
			scanf("%d",&MatrizNum[x][y]);
		}
		printf("\n"); //Salto para la siguiente fila
	}
}
void mostrar(int **MatrizNum, int COLS){
	int x,y;
	for(x=0;x<FILAS;x++){
		for(y=0;y<COLS;y++){
			printf("%d\t",MatrizNum[x][y]);
		}
		printf("\n"); //Salto para la siguiente fila
	}
}
