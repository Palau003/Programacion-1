#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stddef.h>

int main(){
	FILE *fp;
	char buffer[100];
	
	if( !(fp=fopen("prueba.txt", "r")) ){
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	
	printf("\nEl contenido del archivo de prueba es\n\n");
//	while(!feof(fp)){
	//	fscanf(fp," %s", buffer);
		fscanf(fp," %[^\n]", buffer);
		printf("%s",buffer);
//	}
	fclose(fp);
}
/*int main(){
	FILE *fp;
	char buffer[100];
	
	if( !(fp=fopen("prueba.txt", "r+")) ){
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	
	printf("\nEl contenido del archivo de prueba es\n\n");
	while(!feof(fp)){
		printf("%s",buffer);
		fread(buffer,sizeof(char),100,fp);
	}
	fclose(fp);
}*/
/*int main(){
	FILE *arch;
	char caracteres[100];
	
	if(!(arch=fopen("prueba.txt", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	
	printf("\nEl contenido del archivo de prueba es\n\n");
	while(!feof(arch)){
		fgets(caracteres,100,arch);
		printf("%s", caracteres);
	}
	fclose(arch);
}*/
/*int main(){
	FILE *arch;
	char caracter;
	
	if(!(arch=fopen("prueba.txt", "r"))){
		printf("Error al intentar leer el archivo");
		exit(1);
	}
	
	printf("\nEl contenido del archivo de prueba es\n\n");
	while(!feof(arch)){
		caracter=fgetc(arch);
		printf("%c", caracter);
	}
	fclose(arch);
}*/
