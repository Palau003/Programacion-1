#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main(){
	FILE *arch;
	char caracter;
	
	arch=fopen("prueba.txt", "r");
	
	if(arch==NULL){
		printf("Error al intentar leer el archivo");
		getch();
		exit(1);
	}
	printf("\nEl contenido del archivo de prueba es\n\n");
	while(!feof(arch)){
		caracter=fgetc(arch);
		printf("%c", caracter);
	}
	fclose(arch);
}
