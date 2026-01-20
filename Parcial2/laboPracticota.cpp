#include <stdio.h>
#include <conio.h> //libreria para getch();
#include <stdlib.h> //libreria para rand
#include <time.h> //libreria para rand



int main(){//Función principal
    bool bandera=false; //booleana que nos ayudara para ver si una condision de cumple o no, y realizar cierta accion segun corresponda
    int array[20], n=0,num=0, i=0, j=0, par=0, impar=0; //declaracion de variable y el arreglo unidimensional
    char fig[20][20]={' '};
	//Mis datos aqui abajo
    printf("Palau Andrade Arturo, 178561, Lab. Programacion 1\n26 Septiembre 2022, Grupo A, Lunes 14-16hrs\n\n");
    srand(time(NULL)); //para que el rand genere valores aleatorios cada corrida
    
    for(int i=0; i<20; i++){//con ciclo for llenaremos el arreglo unidimensional con datos random
        array[i]=3+rand()%(40-3)+1;//random entre el 3 y el 40
    }
    for(int i=0; i<20; i++){//Para imprimir el arreglo Unidimensonal
        printf("\n[%d]: %d",i,array[i]);
    }
    
    do{ //hacer hasta que la condicion se rompa
        n=0;//inicializamos siempre en 0 para que en cada corrida no cambie el valor en los ciclos
        bandera=false; //inizializamos la bandera con false para que no afecte a n corridas futuras
        do{//ciclo para aceptar el valor entre 3 y 40
            printf("\n\nIntroduce un numero entre 3 a 40: ");//dato a evaluar
            fflush(stdin);//para limpiar el buffer del teclado
            scanf("%d", &n);//dato a evaluar
        }while((n!=0) && ((n<3) || (n>40)));
        if(n==0){
            printf("\n\nAdios!!!");
            break;//break para terminar programa
        }
        for(i=0; i<20; i++){//ciclo for para avanzar en cada posicion del arreglo
            impar=0;    //damos valor de 0 para que nos sirva en cada corrida nueva
            par=0; //damos valor de 0 para que nos sirva en cada corrida nueva
            if((n==array[i])){//para comparar en cada posicion del arreglo unidimensional
                bandera=true;
                printf("\nValor encontrado en la posicion [%d]", i);
                for(int k=1; k<=n; k++){
                    if(k%2==0){
                        printf("\n\t%d", k);
                        par++;//contador para almacenar la cantidad de numeros pares
                    }else {
                        impar++;//contador para almacenar la cantidad de numeros impares
                    }
                }
                printf("\n\nNumeros pares desde 1 hasta el %d: %d\nNumeros impares desde 1 hasta el %d: %d\n\n", n, par, n, impar);
                for(int m=0; m<i; m++){
                    if(m%2!=0){
                        printf("\nPosicion impar [%d]: %d", m, array[m]);//para imprimir del arreglo en posición impar
                    }
                }
                break;
            }
            if(n<20){
            	for(int f=n; f>=0; f--){
            		for()
				}
			}
        }
        if(bandera==false){//bandera false, osea no se encontro el numero en el arreglo
            printf("\nValor no encontrado..."); //si i recorrio todo el arreglo y no regreso
            for(int l=0; l<n; l++){
                num=3+rand()%(40-3)+1;//numeros random
                printf("\n%d", num);//imprime los numeros random
            }
        }
    }while((n!=0)); //condicion para que no salga del ciclo
    
    getch(); //para que el programa no finalize de golpe
    return 0;//retorna 0 a la funcion principal entera, finalizando el programa
