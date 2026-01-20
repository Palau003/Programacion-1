#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	char al1[10]="",al2[10]="",al3[10]="";
	float cal1[5],cal2[5],cal3[5],prom1=0,prom2=0,prom3=0,p=0,pg=0;
	printf("Palau Andrade Arturo, 178561\n\n");
	srand(time(NULL));
	
	for(int i=0; i<10; i++){
		al1[i]=97+rand()%(122-97)+1;
	}
	for(int i=0; i<10; i++){
		al2[i]=97+rand()%(122-97)+1;
	}
	for(int i=0; i<10; i++){
		al3[i]=97+rand()%(122-97)+1;
	}
	
	printf("Nombre\t\tcal1\tcal2\tcal3\tcal4\tcal5\tProm\n");
	for(int i=0; i<10;i++){
		printf("%c",al1[i]);
	}
	for(int i=0; i<5; i++){
		cal1[i]=3+rand()%(10-3)+1;
		prom1+=cal1[i];
		printf("\t%.2f",cal1[i]);
	}
	prom1/=5;
	printf("\t%.2f", prom1);
	
	printf("\n");
	for(int i=0; i<10; i++){
		printf("%c",al2[i]);
	}
	for(int i=0; i<5; i++){
		cal2[i]=3+rand()%(10-3)+1;
		prom2+=cal2[i];
		printf("\t%.2f",cal2[i]);
	}
	prom2/=5;
	printf("\t%.2f", prom2);
	
	printf("\n");
	for(int i=0; i<10; i++){
		printf("%c",al3[i]);
	}
	for(int i=0; i<5; i++){
		cal3[i]=3+rand()%(10-3)+1;
		prom3+=cal3[i];
		printf("\t%.2f",cal3[i]);
	}
	prom3/=5;
	printf("\t%.2f", prom3);
	/*--------------------------------*/
	printf("\n");
	printf("Prom Calif:");
	for(int i=0; i<5; i++){
		p=0;
		p+=((cal1[i])+cal2[i]+cal3[i]);
		p/=3;
		printf("\t%.2f",p);
	}
	pg=((prom1+prom2+prom3)/3);
	printf("\nProm Grupo:\t%.2f", pg);
	
	return 0;
}
