#include <stdio.h>
#include <stdlib.h> //idk
#include <conio.h> //para getche()
#include <windows.h> //para funciones como exit 
#include <locale.h> //para locale (cambiar de idioma a español)
#include <string.h> //para trabajar con las funciones de cadena como strcmp o strcpy
#include <ctype.h> //para funciones especiales de caracteres
#include <math.h> //para funciones matemáticas como pow o sqrt
#include <time.h> //para la semilla del rand
#include <stddef.h> //idk

void gotoxy(int x, int y){ //para gotoxy
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X = x;
	dWPos.Y = y;
	SetConsoleCursorPosition(hcon,dWPos);
}
enum MENU { OPC1=1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7 }; //enum para opciones
bool bandera=true; //booleana global
FILE *arch; //puntero para el archivo
FILE *arch2; //puntero al segundo archivo
FILE *arch3; //puntero al tercer archivo

struct boletos{ //estructura para guardar el conteo de boletos comprados de cada tipo
	int basico;
	int premium;
	int oro;
};
struct precios{ //estructura para guardar los precios de cada boleto
	float pBasico;
	float pPremium;
	float pOro;
	int mBas;
	int mPrem;
	int mOro;
}P_boletos;
struct Movimientos{ //estructura para guardar cada movimiento del usuario
	float inversion; //lo que invierte el usuario
	float ganancias; //lo que ganamos o perdemos
	float total; //reporta si hubo perdida o ganancia
};
struct Registro{ //estructura principal
	char nombre[30]; 
	char domicilio[40];
	char codigo[5];
	boletos comprados; //estructura anidada
	Movimientos hechos; 
	float saldo;
};
int *pNbas = &P_boletos.mBas;
int *pNpre = &P_boletos.mPrem;
int *pNoro = &P_boletos.mOro; //punteros para modificar el numero de boletos a vender

float *pBas = &P_boletos.pBasico;
float *pPre = &P_boletos.pPremium;
float *pO   = &P_boletos.pOro; //punteros para modificar el precio de los boletos

//mis propias librerias
#include "decorar.h"
#include "validaciones.h"
#include "estructura.h"
#include "menu.h"
