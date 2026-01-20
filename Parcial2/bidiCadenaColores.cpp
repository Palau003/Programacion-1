#include <stdio.h>
#include <string.h>
#include <windows.h>


int main(){
	int c;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    printf("Palau Andrade Arturo, 178561\n\n");
    
    char palabra[5][15]={""}, vocal=0, consonante=0;
    
    for(int i=0; i<5; i++){
        printf("Escribe una palabra: ");
        scanf(" %[^\n]", palabra[i]);
        
        fflush(stdin);
    }
    for(int i=0; i<5; i++){
        vocal=0;
        consonante=0;
        printf("\nPalabra %d : %s",i+1, palabra[i]);
        for(int k=0; k<strlen(palabra[i]); k++){
            if((palabra[i][k]=='A') || (palabra[i][k]=='E') || (palabra[i][k]=='I') || (palabra[i][k]=='O') || (palabra[i][k]=='U')
             ||(palabra[i][k]=='a') || (palabra[i][k]=='e') || (palabra[i][k]=='i') || (palabra[i][k]=='o') || (palabra[i][k]=='u')){
                vocal++;
            }else if(palabra[i][k]==' '){
                
            }else{
            	consonante++;
			} 
        }
        printf("\t\tVocales: %d\tConsonantes: %d", vocal, consonante);
    }
    printf("\n\n");
    for(int i=0; i<5; i++){
    	SetConsoleTextAttribute(hConsole, 15);
        printf("\nPalabra %d : ",i+1);
        for(int j=0; j<strlen(palabra[i]); j++){
            if((palabra[i][j]=='A') || (palabra[i][j]=='E') || (palabra[i][j]=='I') || (palabra[i][j]=='O') || (palabra[i][j]=='U')
             ||(palabra[i][j]=='a') || (palabra[i][j]=='e') || (palabra[i][j]=='i') || (palabra[i][j]=='o') || (palabra[i][j]=='u')){
                SetConsoleTextAttribute(hConsole, 6);
				printf("%c",palabra[i][j]);
            }else{
            	SetConsoleTextAttribute(hConsole, 5);
            	printf("%c",palabra[i][j]);
			}
        }
        printf("\n");
    }
    
    return 0;
}
