#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void rellenar(float[][5]);
void verifica(float[][5], int, int);
bool bandera=false;

void rellenar(float tab[][5]){
	srand(time(NULL));
	int f=0, c=0, cont=0;
	
	do{
		do{
			f=0+rand()%(5);
			c=0+rand()%(5);
			//printf("\n\nFila: %d\nColu: %d", f, c);
			verifica(tab,f,c);
		}while(bandera!=true);
		printf("\nNo: %d", cont+1);
		cont++;
	}while(cont<10);
}
void verifica(float tab[][5], int f, int c){
	int num=0, dec=0;
	
	if((tab[f][c] == 0)){
		num=5+rand()%(250-5);
		dec=0+rand()%(10);
		tab[f][c]=dec;
		tab[f][c]/=10;
		tab[f][c]+=num;
			
		bandera = true;
	}
	else bandera = false;
}
int main(){
	
	float tab[5][5]={0};
	
	srand(time(NULL));
	rellenar(tab);
	printf("\nArreglo\n\n");
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			printf(" %.2f ", tab[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
