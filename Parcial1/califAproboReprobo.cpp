#include <stdio.h>

int main(){
	char nombre[25]="";
	float cal1=0.0, cal2=0.0, cal3=0.0, cal4=0.0, promed=0.0;
	printf("Palau Andrade Arturo, 178561 \n\n");
	
	printf("Introduce tu nombre completo: ");
	scanf("%[^\n]", nombre);
	
	do{
		fflush(stdin);
		printf("\nCalificación Parcial 1: ");
		scanf("%f", &cal1);
	}while(!(cal1<=10) && (cal1>=0));	//para asegurarse de que sea entre 0 y 10
	do{
		fflush(stdin);
		printf("\nCalificación Parcial 2: ");
		scanf("%f", &cal2);
	}while(!(cal2<=10) && (cal2>=0));
	do{
		fflush(stdin);
		printf("\nCalificación Parcial 3: ");
		scanf("%f", &cal3);
	}while(!(cal3<=10) && (cal3>=0));
	do{
		fflush(stdin);
		printf("\nCalificación Parcial 4: ");
		scanf("%f", &cal4);
	}while(!(cal4<=10) && (cal4>=0));
	
	promed=((cal1*0.2)+(cal2*0.2)+(cal3*0.2)+(cal4*0.4));
	
	if(promed >=7){
		printf("\nParcial 1 (20%%) : %.2f\nParcial 2 (20%%) : %.2f\nParcial 3 (20%%) : %.2f\nParcial 4 (40%%) : %.2f\nPromedio Final : %.2f", cal1, cal2, cal3, cal4, promed);
		printf("\n\nEl alumno %s aprobo con promedio de: %.2f", nombre, promed);
	}else{
		printf("\nParcial 1 (20%%) : %.2f\nParcial 2 (20%%) : %.2f\nParcial 3 (20%%) : %.2f\nParcial 4 (40%%) : %.2f\nPromedio Final : %.2f", cal1, cal2, cal3, cal4, promed);
		printf("\n\nEl alumno %s no aprobo, con promedio final de: %.2f", nombre, promed);
	}
	return 0;
}
