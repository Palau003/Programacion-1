#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Palau Andrade Arturo, 178561\n\n");
	
	for(int i=1; i<=20; i++ ){
		printf("%d\n", i);
		if(i>15){
			//break;//continue;//exit(0);
			printf("\nCoca Cola");
		}
	}
	
	return 0;
}
