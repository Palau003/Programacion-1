#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	printf("Palau Andrade Arturo, 178561\n\n");
	int tabla[2][3]={0};
	srand(time(NULL));
	
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			tabla[i][j]=8+rand()%(20-8)+1;
		}
		printf("\n");
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			printf("%d\t", tabla[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
