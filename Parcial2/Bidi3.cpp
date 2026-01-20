#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int n=0;
	printf("Palau Andrade Arturo, 178561\n\n");
	srand(time(NULL));
	n=3+rand()%(8-3)+1;
	
	printf("Num random: %d\n\n", n);
	int bidi[n][n]={0}, resul=0, resul2=0, resul3=0, resul4=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			bidi[i][j]=0+rand()%(10-0)+1;
		}
	}
	for(int i=0; i<n; i++){
		for( int j=0; j<n; j++){
			printf(" %d\t",bidi[i][j]);
		}
		printf("\n");
	}
	for(int i=0, j=0; i<n, j<n; i++, j++){
		resul+=bidi[0][j];
		resul2+=bidi[n-1][j];
		resul3+=bidi[i][0];
		resul4+=bidi[i][n-1];
	}
	printf("\n\nSuma pared superior: ");
	for(int j=0; j<n; j++){
		printf(" %d ", bidi[0][j]);
	}printf(" = %d", resul);
	
	printf("\n\nSuma pared inferior: ");
	for(int j=0; j<n; j++){
		printf(" %d ", bidi[n-1][j]);
	}printf(" = %d", resul2);
	
	printf("\n\nSuma pared izquierda: ");
	for(int i=0; i<n; i++){
		printf(" %d ", bidi[i][0]);
	}printf(" = %d", resul3);
	
	printf("\n\nSuma pared derecha: ");
	for(int i=0; i<n; i++){
		printf(" %d ", bidi[i][n-1]);
	}printf(" = %d", resul4);
	
	return 0;
}
