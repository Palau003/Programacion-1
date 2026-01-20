#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int n=0;
	printf("Palau Andrade Arturo, 178561\n\n");
	srand(time(NULL));
	n=3+rand()%(8-3)+1;
	
	printf("Num random: %d\n\n", n);
	int bidi[n][n]={0}, resul=0, resul2=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			bidi[i][j]=0+rand()%(10-0)+1;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf(" %d\t",bidi[i][j]);
		}
		printf("\n");
	}
	for(int i=0, j=0; i<n, j<n; i++, j++){
		resul+=bidi[i][j];
		resul2+=bidi[i][j];
	}
	printf("\n\nSuma diagonal 1 : ");
	for(int i=0,j=0; i<n, j<n; i++,j++){
		printf(" %d ", bidi[i][j]);
	}printf(" = %d", resul);
	
	printf("\n\nSuma diagonal 2 : ");
	for(int i=n-1,j=0; i<n, j<n; i--,j++){
		printf(" %d ", bidi[i][j]);
	}printf(" = %d", resul2);
	
	return 0;
}
