#include <stdio.h>

typedef struct{
	char nombre[20];
	int matricula;
	float calif;
}estudiante;

int main(){
	printf("Palau Andrade Arturo, 178561\n\n");
	estudiante mejor={"Null", 0, 0.0}, *ptr_est;
	ptr_est=&mejor;
	
	printf("Ingresa tu nombre: ");
	scanf("[^\n]", ptr_est->nombre);
	fflush(stdin);
	
	printf("Ingresa tu matricula: ");
	scanf("%d", ptr_est->matricula);
	fflush(stdin);
	
	printf("Calificacion: ");
	scanf("%f", ptr_est->calif);
	
	printf("\nNombre: %s", ptr_est->nombre);
	printf("\nMatricula: %d", ptr_est->matricula);
	printf("\nCalif: %.2f", ptr_est->calif);
	
	return 0;
}
