#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int distancia=0;
	printf("Palau Andrade Arturo, 178561\n\n");
	srand(time(NULL));
	
	for(int i=0; i<5; i++){
		distancia=1+rand()%(15-1)+1;
		printf("Caballo %d: ",i+1);
		for(int j=0; j<distancia; j++){
			printf("%c", 219);
		}
		printf(" km\n\n");
	}
	
	return 0;
}
