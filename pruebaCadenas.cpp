#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

bool bandera=true;

void nombre(const char mensaje[], char cadena[10]){
	
	while(bandera){
		system("cls");
		
		printf("%s", mensaje);
		fflush(stdin);
		scanf(" %[^\n]", cadena);
		
		if((cadena[strlen(cadena)-1]==' ')){
			printf("\nError");
			getche();
		}
		printf("Tam cadena -> %d", strlen(cadena));
		getch();
	}	
}

int main(){
	char cadena[10]="";
	nombre("Escribe tu nombre: ", cadena);
	
	return 0;
}
