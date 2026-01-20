#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

bool bandera=true;
void verifica(char[5], char);

void verifica(char codigo[5], char aux){
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

int main(){
	srand(time(NULL));
	
	return 0;
}
