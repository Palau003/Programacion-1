#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
typedef struct{
	char nombre[30], domicilio[20], codigo[5];
	float saldo;
}Registro; //Nombre de la variable

Registro participantes[]={""};

bool bandera=true;
void juega(int);
void imprimeTablero(float[][5],float[][5], int);
void destapar(int, int, float[][5], float[][5]);
void rellenar(float[][5]);
void verifica(float[][5], int, int);
int fila();
int columna();
int pos=0;

int main(){
	juega(5);
	getch();
	
	return 0;
}

void juega(int intentos){
	float tab1[5][5]={0}, tab2[5][5]={0};
	rellenar(tab1);
	do{
		imprimeTablero(tab1,tab2,intentos);
		intentos--;
	}while(intentos!=0);
	printf("\nJuego acabado!!\n\nSaldo final: %.2f", participantes[pos].saldo);
	Sleep(1500);
	system("cls");
}
void imprimeTablero(float tab1[][5], float tab2[][5], int intentos){
	int f=0, c=0;
	
	system("cls");
	printf("\nIntendos restantes: %d\nSaldo acumulado: %.2f\n\n\tSeleccione la casilla a destapar\n\n", intentos, participantes[pos].saldo);
	
	printf("\n\nArr Tapado\n\n\tCol[0]\tCol[1]\tCol[2]\tCol[3]\tCol[4]");
	for(int i=0; i<5; i++){
		printf("\n\nFila %d\t", i);
		for(int j=0; j<5; j++){
			printf(" %.2f\t",tab2);
		}
		printf("\n");
	}
	printf("\n\nSeleccione las coordenadas de la casilla a destapar....\n\n");
	f=fila();
	c=columna();
		
	destapar(f,c,tab1,tab2);
}
void destapar(int f, int c, float tab1[][5], float tab2[][5]){
	if(tab2[f][c]==0){
		tab2[f][c]=tab1[f][c];
		participantes[pos].saldo+=tab1[f][c];
	}else{
		printf("\nCelda ya descubierta! ");
		getch();
	}
}
int fila(){
	int f=0;
	do{
		printf("\nFila: ");
		scanf("%d", &f);
		fflush(stdin);
	}while((f<0) || (f>4));
	return f;
}
int columna(){
	int c=0;
	do{
		printf("\nColumna: ");
		scanf("%d", &c);
		fflush(stdin);
	}while((c<0) || (c>4));
	return c;
}
void rellenar(float tab[][5]){
	srand(time(NULL));
	int f=0, c=0, cont=0;
	do{
		do{
			f=0+rand()%(5);
			c=0+rand()%(5);
			printf("\n\nFila: %d\nColu: %d", f, c);
			verifica(tab,f,c);
		}while(bandera!=true);
		//printf("\nNo: %d", cont+1);
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
		printf("\nTab[%d][%d]: %.2f", f,c,tab[f][c]);
			
		bandera = true;
	}
	else bandera = false;
}
