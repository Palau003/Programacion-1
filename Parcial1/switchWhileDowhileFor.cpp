#include <stdio.h>
#include <time.h>//libreria para srand
#include <stdlib.h>//tambien para srand
#include <conio.h>

int main(){
	int num=0, sumatoria=0, opc=0, par=0, i=0;
	printf("Palau Andrade Arturo, 178561\n");
	srand(time(NULL));//semilla para srand
	
	printf("\n\t1)while\n\t2)do-while\n\t3)for\n\nSeleccione el metodo deseado-----> ");
	scanf("%d", &opc);
	
	switch(opc){
		case 1: while(i<10){
					num=5+rand()%(130-5);
					sumatoria+=num;
					printf("\nNum %d: %d", i+1, num);
					if(num%2==0) par+=num;
					i++;
				}
				printf("\n\nSumatoria total: %d\nSumatoria numeros pares: %d", sumatoria, par);
				break;
				
		case 2: do{
					num=5+rand()%(130-5);
					sumatoria+=num;
					printf("\nNum %d: %d", i+1, num);
					if(num%2==0) par+=num;
					i++;
				}while(i<10);
				printf("\n\nSumatoria total: %d\nSumatoria numeros pares: %d", sumatoria, par);
				break;
				
		case 3: for(i=0;i<10;i++){
					num=5+rand()%(130-5);
					sumatoria+=num;
					printf("\nNum %d: %d", i+1, num);
					if(num%2==0) par+=num;
				}
				printf("\n\nSumatoria total: %d\nSumatoria numeros pares: %d", sumatoria, par);
				break;
				
		default: printf("\nOpcion no valida, vuelva a intentar...."); break;
	}
	return 0;
}
