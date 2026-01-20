#include <stdio.h>
void intercambio(int, int);

int main(){
	printf("Palau Andrade Arturo, 178561\n");
	int a=1, b=2;
	printf("\nEn main a: %d\tb: %d", a, b); //a: 1	b: 2
	intercambio(a,b);
	printf("\nDespues de funcion a: %d\tb: %d", a, b); //a: 1	b: 2
	
	return 0;
}

void intercambio(int x, int y){
	int aux=x;
	x=y;
	y=aux;
	printf("\nEn la funcion x: %d\ty: %d", x, y); //a: 2	b: 1
}
