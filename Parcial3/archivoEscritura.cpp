#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(){
	printf("Palau Andrade Arturo, 178561\n\n");
	
	FILE *arch;
	char caracter;
	if( !(arch=fopen("fichero.txt", "r")) ){
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	printf("\nEl contenido del archivo de prueba es\n\n");
//	while(!feof(fp)){
	//	fscanf(fp," %s", buffer);
		fscanf(arch," %[^\n]", caracter);
		printf("%s",caracter);
//	}
	fclose(arch);
	
	/*arch=fopen("fichero.txt", "w+");
	
	printf("\nIntroduce un texto en el archivo: ");
	while((caracter=getchar()) !='\n'){
		printf("%c", fputc(caracter,arch));
	}*/
	fclose(arch);
	
	return 0;
}
