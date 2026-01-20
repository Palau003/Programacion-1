#include <stdio.h>

int main(){
	int array[6], mayor=0;
	printf("Palau Andrade Arturo, 178561\n\n");
	
	for (int i=0; i<6; i++){
		printf("Dame un numero: ");
		scanf("%d", &array[i]);
		fflush(stdin);
		
	}
	
	for(int i=0, l=0; i<6; i++){
		printf("[%d]: %d\n", i, array[i]);
		do{
			mayor=array[i];
			l++;
		}while (l<2);
		if(array[i]>mayor){
			mayor=array[i];
		}
		
	}
	
	
	return 0;
}
