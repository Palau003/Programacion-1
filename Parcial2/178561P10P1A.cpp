#include <stdio.h>
#include <stdlib.h> //libreria para rand
#include <time.h> //libreria para rand
#include <windows.h> //librería para los colores
#define F 5
#define C 6
//definición de las funciones (prototipos)
void verifica(int, int[][6]);
void posiciones(int, int [][6]);
void sumas(int, int[][6]);
void LlenadoMemorama(int [][5]);//función para el memorama con parametro de un arreglo
void verifica1(int, int[][5]);
void verifica2(int, int[][5]);
void carta(int, int[][5]);
bool bandera=false;
//función gotoxy para la practica 10
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
//realiza la impresion de los elementos de la practica 9
void imprime(int array[F][C], int suma, int pares){
    for(int i=0; i<F ; i++){
        for(int j=0; j<C ;j++){//se posiciona en la fila del arreglo
            printf(" %d ",array[i][j] );//se posiciona en la columna de la fila, es el for que hace todo el recorrido y saca los datos
        }
        printf("\n");
    }
    //se imprime la suma de las esquinas
    sumas(suma, array); //funcion para sumar las esquinas del arreglo
    //se imprime la cantidad de pares que se encontraron en el arreglo
    posiciones(pares, array); //funcion para comparar en el arreglo los valores pares, mandamos
    
}
//realiza el llenado para la practica 9
void Llenado(int array1[F][C]){
    srand(time(NULL)); //semilla para el rand y que cambien los valores en cada corrida
    int n=0;
    
    for(int i=0; i<5 ; i++){ //ciclo for para tomar un valor random del 1 al 50
        for(int j=0; j<6 ;j++){
            do{
                n=1+rand()%(50); //asignamos el valor a una variable
                verifica(n, array1); //funcion que verifica el arreglo para ver si ya existe dicho valor
            }while(bandera==false); //lo hace mientras el numero ya exista
            
            array1[i][j]=n;//tras pasar la validacion, se asigna el valor a la variable
        }
    }
    int suma_esquinas = 0, cant_pares = 0; //enviamos con valores de 0 para trabajar con ellos en cada corrida
    imprime(array1, suma_esquinas, cant_pares); //funcion para imprimir
}
void LlenadoMemorama(int memorama[4][5]){
    int aux=0;
    carta(aux, memorama);
    for(int i=0; i<2; i++){
        for(int j=0; j<5; j++){
            do{
                bandera=false;
                do{
                	aux=100+rand()%(401);
            	}while(aux%10!=0);//hacer hasta que sea un numero multiplo de 10
            	
                verifica1(aux, memorama);
            }while(bandera==false);
            memorama[i][j]=aux;
        }
    }
    for(int i=2; i<4; i++){
        for(int j=0; j<5; j++){
            do{
                bandera=false;
                do{
                	aux=100+rand()%(401);
            	}while(aux%10!=0);//hacer hasta que sea un numero multiplo de 10
            	
                verifica2(aux, memorama);
            }while(bandera==false);
            memorama[i][j]=aux;
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            printf("%d\t", memorama[i][j]);
        }
        printf("\n");
    }
}
void verifica1(int aux,int memorama[][5]){
    
    for(int i=0; i<2; i++){
        for(int j=0; j<5; j++){
            if((aux==memorama[i][j]) &&(memorama[i][j]==0)){
				bandera=false;
				break;
			}
            else bandera=true;
        }
        if (bandera==false) break;
    }
}
void verifica2(int aux,int memorama[][5]){
    
    for(int i=2; i<4; i++){
        for(int j=0; j<5; j++){
            if((aux==memorama[i][j]) &&(memorama[i][j]==0)){
				bandera=false;
				break;
			}
            else bandera=true;
        }
        if (bandera==false) break;
    }
}
void carta(int aux, int memorama[][5]){
	int n1=0, n2=0;
	n1=0+rand()%(4);
	n2=0+rand()%(4);
	memorama[2][n1]=memorama[0][n2];
}
//impresion del menu e invocacion al inicio de las funciones propias de cada opcion
int menuPracticas(int array1[F][C]){
    int opc_menu = 0, memorama[4][5]={0};
    
    
    printf("1. PRACTICA 9\n2. PRACTICA 10\n3. PRACTICA 11\n4. PRACTICA 12\n5. PRACTICA 13\n6. SALIR\n\tOPC: ");
    scanf("%d",&opc_menu);
    
    switch(opc_menu){
        case 1: //PRACTICA 9
            Llenado(array1);
            break;
        case 2: //PRACTICA 10
            LlenadoMemorama(memorama);//invocamos la funcion y mandamos el arreglo
            break;
        case 6:
        break;
    }
    return opc_menu; //para saber si dio la orden de salir
}
int main(){
    printf("Palau Andrade Arturo, 178561, Lab. Programacion 1\n17 Octubre 2022, Grupo A, Lunes 14-16hrs\n\n");
    int c;//entero para poder utilizar los códigos de colores
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//para el uso de los colores
    
    int array1[F][C] = {0}; //arreglo inicializado por completo en cero, para P9
    int volver = 0; //tomar la opcion del menu a la cual se ingreso
    
    do{
        volver = menuPracticas(array1); //invocacion a la funcion menu
    }while(volver != 6); //mientras no se reciba un salir, el menu se sigue imprimiendo
    return 0;
}
void verifica(int n, int array1[5][6]){ //función que verifica en el arreglo si el número ya existe
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            if(n==array1[i][j]){
                bandera=false;//si la bandera es falsa, regresa a la función y lo hace hasta ser true
                break;
            }else bandera=true; //significa que el número no se encontro
        }
        if(bandera==false) break;
    }
}
void sumas(int suma, int array1[][6]){
    suma=0;
    suma+=array1[0][0];
    suma+=array1[F-1][C-1];
    suma+=array1[F-1][0];
    suma+=array1[0][C-1];
    
    printf("\nSuma esquinas: %d \n\n", suma);
}
void posiciones(int n, int array1[5][6]){
    n=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            if(array1[i][j]%2==0){
            n++;
            }
        }
    }
    printf("\nCantidad de numeros pares: %d\n\n", n);
}
