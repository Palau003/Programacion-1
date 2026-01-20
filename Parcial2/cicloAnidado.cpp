#include <stdio.h>

int main(){
	printf("Palau Andrade Arturo, 178561\n\n");
	/*int i=0, j=0;
	printf("INICIO\n");
	for(i=1;i<3;i++){
		for(j=10;j<=12;j++){
			printf(" i=%d \t j=%d \n",i,j);
		}
	}*/
	/*int k=0;
	for (int i=1; i<=5; i++){
		k++;
		for (int j=1; j<=k; j++){
			printf("%d ",j);
		}
		
		printf("\n");
	}*/
	for (int i=1; i<=5; i++){
		for (int j=0; j<i; j++){
			printf("%d ",j+1);
		}
		printf("\n");
	}
	
	return 0;
}
