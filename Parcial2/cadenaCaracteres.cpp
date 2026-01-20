#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	printf("Palau Andrade Arturo, 178561\n");
	char cad1[20]="", cad2[20]="";
	int resul=0;
	
	printf("Escribe una palabra: ");
	scanf("%[^\n]", cad1);
	fflush(stdin);
	printf("Escribe otra palabra: ");
	scanf("%[^\n]", cad2);
	fflush(stdin);
	resul=strcmp(cad1,cad2);
	for(int i=0; i<strlen(cad1); i++){
		cad1[i]=toupper(cad1[i]);
	}
	for(int i=0; i<strlen(cad2); i++){
		cad2[i]=tolower(cad2[i]);
	}
	//Devuelve 0 si ambas cadenas son iguales
	//Devuelve 1 si cadena 1 es MAYOR que cadena 2
	//Devuelve -1 si cadena 1 es menor que cadena 2
	printf("\nValor retornado con strcmp: %d ", resul);
	printf("\nPalabra 1 con toupper: %s\nPalabra 2 con tolower: %s", cad1, cad2);
	
	return 0;
}
/*int main(){
	printf("Palau Andrade Arturo, 178561\n");
	char cad1[20]="", cad2[20]="";
	int resul=0;
	
	printf("Escribe una palabra: ");
	scanf("%[^\n]", cad1);
	fflush(stdin);
	printf("Escribe otra palabra: ");
	scanf("%[^\n]", cad2);
	fflush(stdin);
	resul=strcmp(cad1,cad2);
	//Devuelve 0 si ambas cadenas son iguales
	//Devuelve 1 si cadena 1 es MAYOR que cadena 2
	//Devuelve -1 si cadena 1 es menor que cadena 2
	printf("\n%d ", resul);
	return 0;
}*/
/*int main(){
	printf("Palau Andrade Arturo, 178561\n");
	char cad1[20]="", cad2[20]="";
	
	printf("Escribe una palabra: ");
	scanf("%[^\n]", cad1);
	fflush(stdin);
	printf("Escribe otra palabra: ");
	scanf("%[^\n]", cad2);
	fflush(stdin);
	strcat(cad1,cad2);
	
	printf("\nPalabra 1 con strcat: %s", cad1);
	
	return 0;
}*/
/*int main(){
	printf("Palau Andrade Arturo, 178561\n");
	char cad1[10]="", cad2[10]="";
	
	printf("Escribe una palabra: ");
	scanf("%[^\n]", cad1);
	fflush(stdin);
	printf("Escribe otra palabra: ");
	scanf("%[^\n]", cad2);
	fflush(stdin);
	strcpy(cad2,cad1);
	
	printf("\nAmbas palabras con strcpy: %s\t%s", cad1, cad2);
	
	return 0;
}*/
