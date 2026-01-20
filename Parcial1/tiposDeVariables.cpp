#include <stdio.h>

int main(){
	int a=12;
	float b=15.53;
	char c='c', cadena[20]="";
	bool bandera=true;
	
	printf("Palau Andrade Arturo, 178561 \n");
	
	printf("Dame un numero entero: ");
	scanf("%d", &a);
	printf("Dame un numero flotante: ");
	scanf("%f", &b);
	fflush(stdin);
	printf("Dame un caracter: ");
	scanf("%c", &c);
	fflush(stdin);
	printf("Escribe algo: ");
	scanf("%[^\n]", cadena);
	//imprimir los 4 tipos de variables (booleana se imprime con %d)
	printf("Entero :%d, Flotante:  %.4f, Caracter: %c, Cadena: %s, Booleana: %d", a, b, c, cadena, bandera);
	return 0;
}
