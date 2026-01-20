#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
	int continuar = 0;
	float flotante = 0;
	
	/*printf("Dame el flotante: ");
	scanf("%f",&flotante);
	printf("El flotante es: %.2f", flotante); */

	do{
		//system("cls");
		system("color 0C");
		printf("Dame el flotante: ");
		continuar = scanf("%f", &flotante);
		printf("%d --> ", continuar);
		fflush(stdin);
	}while (continuar != 1);
	printf("El flotante es: %.2f", flotante);
	
	return 0;
}
