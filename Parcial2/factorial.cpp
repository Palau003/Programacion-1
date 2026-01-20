#include <stdio.h>
#include <math.h>

void factorial(int, int);

int main(){
	printf("Palau Andrade Arturo, 178561\n");
	int x=0, n=0;
	
	printf("\nDame el valor de x: ");
	scanf("%d", &x);
	fflush(stdin);
	printf("Cuantas veces lo quieres?: ");
	scanf("%d", &n);
	fflush(stdin);
	factorial(x,n);
	
	return 0;
}

void factorial(int x, int n){
	
	
}
