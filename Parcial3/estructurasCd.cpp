#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct cd{
	char titulo[30];
	char artista[25];
	int nro_canciones;
	float precio;
	char fecha_compra[10];
};

cd mis_cds[3];

void leer();
void mostrar();
void menu();

int main(){
	//struct cd mis_cds[3];
	printf("Palau Andrade Arturo, 178561\n\n");
	Sleep(500);
	leer();
	mostrar();
	menu();
	
	return 0;
}

void leer(){
	for(int i=0; i<3; i++){
		
		printf("\nTitulo del CD %d: ", i+1);
		fflush(stdin);
		scanf(" %[^\n]", mis_cds[i].titulo);
		printf("\nArtirsta: ");
		fflush(stdin);
		scanf(" %[^\n]", mis_cds[i].artista);
		printf("\nNumero de canciones: ");
		fflush(stdin);
		scanf("%d", &mis_cds[i].nro_canciones);
		printf("\nPrecio: $");
		fflush(stdin);
		scanf("%f", &mis_cds[i].precio);
		printf("\nFecha de compra: ");
		fflush(stdin);
		scanf(" %[^\n]", mis_cds[i].titulo);
		system("cls");
	}
}
void mostrar(){
	for(int i=0; i<3; i++){
		printf("\n\n\nTitulo del CD %d: %s", i+1, mis_cds[i].titulo);
		printf("\nArtirsta: %s", mis_cds[i].artista);
		printf("\nNumero de canciones: %d", mis_cds[i].nro_canciones);
		printf("\nPrecio: $%.2f", mis_cds[i].precio);
		printf("\nFecha de compra: %s", mis_cds[i].titulo);
	}
	printf("\nPresione para continuar...");
	getch();
}
void menu(){
	int opc=0;
	
	do{
		system("cls");
		printf("Palau Andrade Arturo, 178561\n\n");
		printf("\n\t1)Volver a registrar\n\t2)Mostrar\n\t3)Terminar\n\n----->");
		fflush(stdin);
		scanf("%d", &opc);
	
		switch(opc){
			case 1: leer();
					getch();
					break;
			case 2: mostrar();
					getch();
					break;
			case 3: system("exit");
					break;
			default: printf("\nOpcion no valida :(");
					 break;
		}
	}while(opc!=3);
}

