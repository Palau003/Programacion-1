#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
bool bandera=true;
void verificaCodigo(char codigo[5], char aux){ //verificamos que no se repita ningún caracter en el arreglo
	for(int i=0; i<5; i++){
		if(codigo[i]==aux){
			bandera=false;
			break;
		}else if(i==4){
			bandera=true;
			break;
		}
	}
}
void Codigo(char codigo[5]){
	char aux;
	for(int i=0; i<5; i++){
		do{
			aux=65+rand()%(91-65);
			verificaCodigo(codigo,aux);
		}while(bandera!=true);
		codigo[i]=aux;
	}
}
int main(){
	char cod[5];
	Codigo(cod);
	printf("Codigo asignado: %s", cod);
	
	return 0;
}
