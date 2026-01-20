#include <stdio.h>

int main(){
	printf("Palau Andrade Arturo, 178561\n\n");
	//int tabla[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int tabla[3][4]={0};
	
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			//printf("%d\t", tabla[i][j]);
			printf("Dame un numero: ");
			scanf("%d", &tabla[i][j]);
			fflush(stdin);
		}
		printf("\n");
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			printf("%d\t", tabla[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
