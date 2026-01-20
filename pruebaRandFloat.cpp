#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	float bidi[10][5]={0};
	int num=0, dec=0, n=0;
	
	for(int i=0; i<10; i++){
		for(int j=0; j<5; j++){
			num=5+rand()%(250-5);
			dec=0+rand()%(10);
			bidi[i][j]=dec;
			bidi[i][j]/=10;
			bidi[i][j]+=num;
			printf("N.%d: %.2f \t",i+1, bidi[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0; i<20; i++){
		n=0+rand()%(25);
		printf(" %d ", n);
	}
}
