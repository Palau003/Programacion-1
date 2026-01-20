#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int main(){
	int num=0, opc=0, i=0;
	float suma=0, n=0;
	srand(time(NULL));
	num=3+rand()%(8-3);
	do{
		printf("Palau Andrade Arturo, 178561\n");
		printf("Numeros a sumar: %d", num);
		suma=0;
		i=0;
		/*---------------------------------*/
		printf("\n\n----------------Metodos disponibles-----------------\n\n\t1)While\n\t2)For\n\t3)Salir\n\nSeleccione una opcion-------> ");
		fflush(stdin);
		scanf("%d", &opc);
		switch(opc){
			case 1: while(i<num){
						fflush(stdin);
						printf("\nNum %d: ",i+1);
						scanf("%f", &n);
						suma+=n;
						i++;
					}
					printf("\n\nLa sumatoria total es: %.2f\n\n", suma);
					printf("Presione para continuar...");
					getch();
					system("cls");
					break;
			case 2: for(i=0; i<num; i++){
						fflush(stdin);
						printf("\nNum %d: ",i+1);
						scanf("%f", &n);
						suma+=n;
					}
					printf("\n\nLa sumatoria total es: %.2f\n\n", suma);
					printf("Presione para continuar...");
					getch();
					system("cls");
					break;
			case 3: printf("\n\nNos vemos!!!");
					return 0;
			default: printf("\nOpcion no valida, presione para continuar ");
					 getch();
					 system("cls");
					 break;
		}
	}while(opc!=3);
	return 0;
}
