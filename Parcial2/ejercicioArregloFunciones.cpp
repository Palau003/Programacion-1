#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void imprime(char[][20], float[]);
void llenado(char[][20], float[]);
void busqueda(char[][20], float[]);
void modifica(char[][20]);
void modCalif();

int main(){
    printf("Palau Andrade Arturo, 178561\n");
    char alumnos[5][20]={""};
    float calif[5]={0};
    
    llenado(alumnos, calif);
    imprime(alumnos, calif);
    busqueda(alumnos, calif);
    //modifica(alumnos);
    //modCalif();
    
    return 0;
}
void busqueda(char nombres[][20], float califs[5]){
    char alumno[5]="";
    int opc=0, resul=0;
    do{
        printf("\n\nNombre del alumno a mostrar: ");
        scanf("%[^\n]", alumno);
        fflush(stdin);
        for(int i=0; i<5; i++){
        	resul=strcmp(nombres[i],alumno);
            if(resul==0){
                printf("\nAlumno %s\tCalif. : %.2f", nombres[i], califs[i]);
                break;
            }else if(i==4){
                printf("\nAlumno no encontrado, vuelva a intentar.... ");
                break;
            }
        }
        getch();
        printf("\nPresione 2 para salir, otro para volver a buscar... ");
        scanf("%d", &opc);
    }while(opc!=2);
    
}
void modifica(char nombres[][20]){
    int opc=0, resul=0;
    char alumno[5]="";
    
    do{
        printf("\nNombre del alumno a modificar: ");
        scanf("%[^\n]", alumno);
        fflush(stdin);
        for(int i=0; i<5; i++){
            resul=strcmp(alumno, nombres[i]);
			if(resul==0){
                printf("\nAlumno: %s", nombres[i]);
                nombres[i]="UNO";
                printf("Nuevo nombre: %s", nombres[i]);
                break;
            }else if(i==4){
                printf("\nAlumno no encontrado, vuelva a intentar.... ");
                break;
            }
        }
        getch();
        printf("\nPresione 2 para salir, otro para volver a buscar... ");
        scanf("%d", &opc);
    }while(opc!=2);
    
}
void llenado(char nombres[][20], float califs[5]){
    for(int i=0; i<5; i++){
        printf("\nNombre alumno %d: ", i+1);
        scanf("%[^\n]", nombres[i]);
        fflush(stdin);
        printf("Calificacion final: ");
        scanf("%f", &califs[i]);
        fflush(stdin);
    }
}
void imprime(char nombres[][20], float califs[5]){
    printf("\nNombre\t| Calificacion Final ");
    for(int i=0; i<5; i++){
        printf("\n%s\t| %.2f", nombres[i], califs[i]);
    }
}
