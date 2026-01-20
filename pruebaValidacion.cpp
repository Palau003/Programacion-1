#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int entero(const char mensaje[]){
	
	int continuar=0;
	int entero=0;
	do{
		//system("cls");
		//system("color 03");
		printf("\n%s",mensaje);
		continuar = scanf("%d", &entero);
		fflush(stdin);
	}while ((continuar != 1) && (strlen(entero)>1));
	
	return entero;
}
int columna(){ //verificamos que el rango numerico sea correcto (de 0 a 4)
	int col=0;
	do{
		col=entero("\nColumna: ");
	}while((col<0) || (col>4));
	return col;
}
int main(){
	int col=0;
	
	col=columna();
	
	printf("\nBien....");
	getch();
	
	return 0;
}
