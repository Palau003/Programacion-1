#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void escribirEnArchivo();
FILE *arch;

struct boletos{
	int basico;
	int premium;
	int oro;
};
struct Registro{
	char nombre[30];
	char domicilio[20];
	char codigo[5];
	boletos comprados; //estructura anidada
	float saldo;
};

void escribirEnArchivo(){
	Registro participantes; //<- Nuestra variable
	
	if(!(arch=fopen("prueba.xls", "a"))){
		printf("Error al leer el archivo");
		exit(1);
	}
	printf("\nNombre: ");
	fflush(stdin);
	scanf(" %[^\n]", participantes.nombre);
	
	printf("\nDomicilio: ");
	fflush(stdin);
	scanf(" %[^\n]", participantes.domicilio);
	
	for(int i=0; i<5; i++){
		participantes.codigo[i]='B';
	}
	
	participantes.comprados.basico=4;
	participantes.comprados.oro=2;
	participantes.comprados.premium=12;
	
	fprintf(arch," %s\t", participantes.nombre);
	fprintf(arch," %s\t", participantes.domicilio);
	fprintf(arch, "%s\t", participantes.codigo);
	fprintf(arch, "%d\t", participantes.comprados.basico);
	fprintf(arch, "%d\t", participantes.comprados.oro);
	fprintf(arch, "%d\n", participantes.comprados.premium);
	
	fclose(arch);
}

int main(){

	/*if(! (arch=fopen("prueba.xls", "w"))){
		printf("Error al crear el archivo! :(");
		exit(1);
	}*/
	printf("\nPalau Andrade Arturo, 178561");
	fclose(arch);
	escribirEnArchivo();
	
	return 0;
}
