#include <stdio.h>

int main(){
	int opc=0;
	float metros=0.0, resul=0.0;
	
	printf("Palau Andrade Arturo, 178561");
	printf("\nIngrese los Metros: ");
	scanf("%f", &metros);
	fflush(stdin);
	printf("\n*--------------------------* Convertir metros a *-----------------------------*");
	printf("\n\n\t1)Millas\n\t2)Centimetros\n\t3)Pies\n\t4)Pulgadas\n\nSeleccione la opcion deseada: ");
	scanf("%d", &opc);
	switch(opc){
				case 1:	resul= ((metros)*0.000621);
						printf("\n\n%.2fm ---> %.2fmi", metros, resul);
						break;
				case 2:	resul= ((metros)*100);
						printf("\n\n%.2fm ---> %.2fcm", metros, resul);
						break;
				case 3:	resul= ((metros)*3.28084);
						printf("\n\n%.2fm ---> %.2fft", metros, resul);
						break;
				case 4:	resul= ((metros)*39.37);
						printf("\n\n%.2fm ---> %.2fin", metros, resul);
						break;
				default:printf("Opción no encontrada, vuelva a intentarlo :(");
						break;
	}
	
	return 0;
}
