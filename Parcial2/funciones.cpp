#include <stdio.h>

int num=5;
void funcion(void);
int suma(int, int);

int main(){
	printf("Palau Andrade Arturo, 178561\n\n");
	
	int num=10, a=10, b=25, t=0;
	printf("Valor de num en main: %d\n", num);
	funcion();
	printf("Valor de num en main: %d\n", num);
	t=suma(a,b);
	printf("\nSuma de %d + %d : %d",a,b, t);
	
	return 0;
}
void funcion(){
	printf("Valor de num en funcion: %d\n", num);
}
int suma(int valor1, int valor2){ //las variables recibidas aquí pueden tener otro nombre
	//int sum;
	//sum=a+b;
	//return(sum);
	return(valor1+valor2);
}
