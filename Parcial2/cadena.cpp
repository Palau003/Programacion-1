#include <stdio.h>
#include <string.h>

int main(){
	printf("Palau Andrade Arturo, 178561\n");
	int largo=0;
	char cadena[10]="chocolate", cadena2[10]="rompope";
	
	printf("Escribe una palabra: ");
	scanf("%[^\n]", cadena);
	largo=strlen(cadena);
	strcpy(cadena2,cadena);
	printf("\nPalabra insertada: %s\nPalabra copiada: %s\nLongitud de la palabra: %d", cadena, cadena2, largo);
	
	
	return 0;
}

