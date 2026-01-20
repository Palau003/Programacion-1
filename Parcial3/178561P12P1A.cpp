#include <stdio.h>
#include <stdlib.h> //libreria para rand
#include <time.h> //libreria para rand
#include <windows.h> //librería para los colores
#include <conio.h> //librería para getch
#include <ctype.h> //para isalpha
#define F 5
#define C 6
typedef struct{
	char name[10];
	int coin;
	int correct;
	int tries;
}Persona; //nombre de la estructura
Persona jugadores[4]= {	{"Null", 500,0,0},
						{"Null", 500,0,0},
						{"Null", 500,0,0},
						{"Null", 500,0,0} };
int pos=0; //variable global para recorrer las posiciones de nuestra estructura de la 0 a la 3
//definición de las funciones (prototipos)
void historial(Persona[4]); //funcion con la estructura
void verifica(int, int[][6]);
void posiciones(int, int [][6]);
void sumas(int, int[][6]);
void LlenadoMemorama(int [][5]);//función para el memorama con parametro de un arreglo
void verifica1(int, int[][5]);
void llenarF2(int [][5]);
void verifica2(int, int[][5]);
void imprimeMemorama(int [][5]);
void jugar(int [][5]);
void voltear(int [][5]);
int carta1(int, int[4][5]);
int carta2(int, int[4][5]);
bool terminar(int[][5]);
void descubrir(int, int, int[][5], int[][5]);
bool bandera=false;
int contador=0, contador2=0; //variable que nos ayudara a verificar si ya se entro almenos una vez en la práctica 10
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
	srand(time(NULL));
	int aux=0;//auxiliar para nuestros datos randoms
    for(int i=0; i<2; i++){
        for(int j=0; j<5; j++){
            do{
                bandera=false;
                do{
                	aux=100+rand()%(401);
            	}while(aux%10!=0);//hacer hasta que sea un numero multiplo de 10
                verifica1(aux, memorama);//verifica que el valor no se repita
            }while(bandera==false);
            memorama[i][j]=aux;
        }
    }
    llenarF2(memorama);
    imprimeMemorama(memorama); //funcion para imprimir el arreglo
}
void imprimeMemorama(int memorama[][5]){ //funcion para que se imprima el memorama
	int c;//variable para mandar el numero del color
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //para que handle cambie de color
	printf("\n\t\tCarta 1\n----------------------------------------------\n");
	
	for(int i=0; i<2; i++){
		SetConsoleTextAttribute(hConsole, 15);//color blanco
		printf("%d |", i);
		for(int j=0; j<5; j++){
			SetConsoleTextAttribute(hConsole, 4);
			printf(" %d\t", memorama[i][j]);
		}
		printf("\n");
	}
	SetConsoleTextAttribute(hConsole, 15);//regresamos el color a blanco para procesos futuros
	//carta 2
	printf("\n\t\tCarta 2\n----------------------------------------------\n");
	
	for(int i=2; i<4; i++){//empezamos i en 2 para imprimir solo las de las otras 2 filas del arreglo
		SetConsoleTextAttribute(hConsole, 15);//color blanco
		printf("%d |", i-2);
		for(int j=0; j<5; j++){
			SetConsoleTextAttribute(hConsole, 5);
			printf(" %d\t", memorama[i][j]);
		}
		printf("\n");//salto de línea
	}
	SetConsoleTextAttribute(hConsole, 15);//regresamos el color a blanco para procesos futuros
}
void verifica1(int aux,int memorama[][5]){// funciones para verificar que no se repitan numeros en cada 2 filas
    for(int i=0; i<2; i++){
        for(int j=0; j<5; j++){
            if((aux==memorama[i][j])){
				bandera=false;
				break;
			}
            else bandera=true;
        }
        if (bandera==false) break;
    }
}
void verifica2(int aux,int memorama[][5]){// funciones para verificar que no se repitan numeros en cada 2 filas
    for(int i=2; i<4; i++){
        for(int j=0; j<5; j++){
            if((aux==memorama[i][j])){
				bandera=false;
				break;
			}
            else bandera=true;
        }
        if (bandera==false) break;
    }
}
void llenarF2(int memorama[][5]){// funciones para llenar las 2 filas restantes
    int f1=0, c2=0, aux=0;//variables para las posiciones random
    
    for(int i=2; i<4; i++){
        for(int j=0; j<5; j++){
            do{
            	f1=0+rand()%(2);
            	c2=0+rand()%(5);
                aux=memorama[f1][c2];
                verifica2(aux, memorama);//verifica que el valor no se repita
            }while(bandera==false);
            memorama[i][j]=aux;
        }
    }
}
void jugar(int memorama[][5]){
	int digito=0;
	/*do{
		printf("\nIngresa tu nombre de usuario: ");
		scanf("%s", jugadores[pos].name);
		for(int i=0; i<strlen(jugadores[pos].name)-1; i++){
			if(jugadores[] == isalpha) 
		}
		fflush(stdin);
	}while();*/
    jugadores[pos].coin=500;
	system("cls");
    LlenadoMemorama(memorama); //llenamos e imprimimos el memorama
	Sleep(10000); //esperamos 10 segundos para continuar para luego limpiar pantalla 
	system("cls");
    
	voltear(memorama);
	pos++;
}
void historial(Persona jugadores[4]){
	printf("JUGADOR\t\tPtos Finales\tPares Acertados\tTiradas\n\n");
	for(int i=0; i<4; i++){
		printf("%s\t%d\t%d\t%d\n", jugadores[i].name, jugadores[i].coin, jugadores[i].correct, jugadores[i].tries );
	}
}
void imprimeM2(int memo2[][5]){
	int c;//variable para mandar el numero del color
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //para que handle cambie de color
    printf("\n\t\tCarta 1\n----------------------------------------------\n");
	
		SetConsoleTextAttribute(hConsole, 4);
			for(int i=0; i<2; i++){
				for(int j=0; j<5; j++){
					printf(" %d \t", memo2[i][j]);
				}
				printf("\n");
			}
			SetConsoleTextAttribute(hConsole, 15);//regresamos el color a blanco para procesos futuros
		printf("\n\t\tCarta 2\n----------------------------------------------\n");
	
		SetConsoleTextAttribute(hConsole, 5);
		for(int i=2; i<4; i++){
			for(int j=0; j<5; j++){
				printf(" %d \t", memo2[i][j]);
			}
			printf("\n");
		}
		SetConsoleTextAttribute(hConsole, 15);//regresamos el color a blanco para procesos futuros
    
}
void voltear(int memorama[][5]){
	
	int memo2[4][5]={{1,2,3,4,5},{6,7,8,9,10},{1,2,3,4,5},{6,7,8,9,10}}; //memorama para mostrar los valores aleatoreos
	int c1=0, c2=0, n1=0, n2=0;
	bool bandera2=false;
	
	do{
		system("cls");
		imprimeM2(memo2);
		
		printf("\nCarta 1: ");
		scanf("%d", &c1);
		fflush(stdin);
		n1=carta1(c1, memorama); //verifica el valor de la carta en esa posición del arreglo
		
		printf("\nCarta 2: ");
		scanf("%d", &c2);
		fflush(stdin);
		n2=carta2(c2, memorama); //verifica el valor de la carta en esa posición del arreglo
		
		if(n1==n2){
			printf("\n\nValor 1: %d\nValor 2: %d\nPresiona para seguir...", n1, n2);
			descubrir(n1,n2,memo2,memorama);
			getch();
		}else{
			printf("\nLas cartas no son iguales, siga intentandolo... ");
			getch();
		}
		bandera2=terminar(memo2);
	}while(bandera2!=true);
}
void descubrir(int n1, int n2, int memo2[][5], int memo1[][5]){
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			if(n1==memo1[i][j]) memo2[i][j]=n2;
			else if(n2==memo1[i][j]) memo2[i][j]=n2;
		}
	}
}
bool terminar(int memo2[][5]){
	bool bandera2=false;
	int cont=0;
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			if(memo2[i][j]<11){//si la casilla no ha sido descubierta, contador aumenta
				cont=1;
			}
		}
		if((cont==0) && (i==3)){//si no hay valores sin descubrir, la bandera sera verdadera
				bandera2=true;	
				printf("\nFelicidades, encontraste todas las cartas!!!\n");
				return bandera2;
		}
	}
	return bandera2;
}
int carta1(int num1, int memorama[4][5]){
	int aux=0, cont=0;
	for(int i=0; i<2; i++){
		for(int j=0; j<5; j++){
			cont++;
			if(num1==cont){
				aux=memorama[i][j];
				i=1;
				j=4;
				break;
			}
		}
	}
	return aux;
}
int carta2(int num2, int memorama[4][5]){
	int aux2=0, cont=0;
	for(int i=2; i<4; i++){
		for(int j=0; j<5; j++){
			cont++;
			if(num2==cont){
				aux2=memorama[i][j];
				i=3;
				j=4;
				break;
			}
		}
	}
	return aux2;
}
//impresion del menu e invocacion al inicio de las funciones propias de cada opcion
int menuPracticas(int array1[F][C]){
    int opc_menu = 0, memorama[4][5]={0};
    
    printf("Palau Andrade Arturo, 178561, Lab. Programacion 1\n31 Octubre 2022, Grupo A, Lunes 14-16hrs\n\n");
    printf("1. PRACTICA 9\n2. PRACTICA 10\n3. PRACTICA 11\n4. PRACTICA 12\n5. PRACTICA 13\n6. SALIR\n\tOPC: ");
    scanf("%d",&opc_menu);
    fflush(stdin);//limpiar el buffer del teclado y evitar errores
    
    switch(opc_menu){
        case 1: //PRACTICA 9
            Llenado(array1);
            printf("\n\nPulsa para continuar...");
			getch();
            system("cls");
            break;
        case 2: //PRACTICA 10
            LlenadoMemorama(memorama);//invocamos la funcion y mandamos el arreglo
            printf("\n\nPulsa para continuar...");
			getch();
			contador=1; //con esto aseguramos que se haya entrado a la práctica 10
            system("cls");
            
            break;
    	case 3: //PRACTICA 11
    		if(contador!=1){//controlamos que rompa el ciclo si no se ha entrado en la practica 10
	    		printf("\n\nDebes entrar primero a la practica 10!!\n\nPresiona para continuar... ");
	    		getch();
	    		system("cls");
				break;
			}
			else{//cuando hayamos entrado a la practica 10, ejecutara la 11
				jugar(memorama);
		    	printf("\n\nPulsa para continuar...");
				getch();
		        system("cls");
		        contador2=1;
				break;
			}
		case 4: //PRACTICA 12
    		if(contador2!=1){//controlamos que rompa el ciclo si no se ha entrado en la practica 10
	    		printf("\n\nDebes entrar primero a la practica 11!!\n\nPresiona para continuar... ");
	    		getch();
	    		system("cls");
				break;
			}
			else{//cuando hayamos entrado a la practica 10, ejecutara la 11
		    	historial(jugadores);
				printf("\n\nPulsa para continuar...");
				getch();
		        system("cls");
				break;
			}
		case 5: //PRACTICA 13
    		printf("\n\nPulsa para continuar...");
			getch();
            system("cls");
			break;
        case 6: //PRACTICA 14
        	printf("\n\nPulsa para continuar...");
			getch();
            system("cls");
			break;
        	
        default: printf("\nOpcion no valida, vuelva a intentarlo... "); //mensaje de error en caso de seleccionar una opción no valida...
        	getch();
        	system("cls");
        	break;
    }
    return opc_menu; //para saber si dio la orden de salir
}
int main(){
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
