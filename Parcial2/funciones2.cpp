#include <stdio.h>
#include <stdlib.h>//Para srand
#include <time.h>//Para srand
#include <math.h>//Para la función pow
#include <conio.h>//Para getch
#include <windows.h>//Para system("cls"); <--- limpiar pantalla
/*	Parametros	*/
float sumatoria();
float producto(float, float);
float elevar(float, float);
float maymen(float, float, float);

int main(){
	int opc=0;
	float n1=0, n2=0, n3=0, mayor=0, r=0;
	
	do{
		printf("Palau Andrade Arturo, 178561\n");
		printf("\n\n------------Seleccione una opcion--------------\n\n\t1)Suma de los numeros del 1 al 10\n\t2)Producto de 2 numeros\n\t3)Un numero elevado a la n potencia\n\t4)Determinar mayor de 3 numeros\n\t5)Salir\n\n-------->");
		scanf("%d", &opc);
		fflush(stdin);
		switch(opc){
			case 1:	r=sumatoria();
					printf("\nSumatoria: %.2f", r);
					getch();
					system("cls");
					break;
					
			case 2:	r=0;
					r=producto(n1,n2);
					printf("\nResultado: %.2f", r);
					getch();
					system("cls");
					break;
					
			case 3:	r=0;
					printf("\nDame el valor base: ");
					scanf("%f", &n1);
					fflush(stdin);
					printf("Dame la potencia: ");
					scanf("%f", &n2);
					fflush(stdin);
					r=elevar(n1,n2);
					printf("\nResultado: %.2f", r);
					getch();
					system("cls");
					break;
					
			case 4: mayor=0;
					printf("Dame el numero 1: ");
					scanf("%f", &n1);
					fflush(stdin);
					printf("Dame el numero 2: ");
					scanf("%f", &n2);
					fflush(stdin);
					printf("Dame el numero 3: ");
					scanf("%f", &n3);
					fflush(stdin);
					mayor=maymen(n1,n2,n3);
					printf("\nEl numero mayor es: %.4f", mayor);
					getch();
					system("cls");
					break;
					
			case 5:	printf("\nAdios!!!");
					getch();
					exit(0);
					break;
					
			default: printf("\nOpcion no valida, vuelva a intentarlo...");
					getch();
					system("cls");
					break;						
		}
		
	}while(opc!=5);
	printf("\nAdiosss!!!");
	
	return 0;
}
/*Funciones*/
float sumatoria(){
	float resul=0;
	for(int i=1; i<=10; i++){
		resul+=i;
	}
	return resul;
}
float producto(float n1, float n2){
	int resul=0;
	n1=0;
	n2=0;
	srand(time(NULL));
	n1=1+rand()%(10);
	n2=1+rand()%(10);
	printf("\nNum 1 (%.2f), Num 2 (%.2f)", n1, n2);
	resul=(n1*n2);
	
	return resul;
}
float elevar(float base, float potencia){
	float resul=0;
	resul=(pow(base, potencia));
	
	return resul;
}
float maymen(float n1, float n2, float n3){
	float mayor=0;
	if( (n1>n2) && (n1>n3) ){
		mayor=n1;
	}else if( (n2>n1) && (n2>n3) ){
		mayor=n2;
	}else mayor=n3;
	
	return mayor;
}
