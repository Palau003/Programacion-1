float validaNumero(const char mensaje[], int cantidad){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int continuar=0;
	int Ncantidad=0;
	
	do{
		do{
			system("cls");
			printf("\nCantidad actual: %d\n%s ",cantidad, mensaje);
			continuar = scanf("%d", &Ncantidad);
			//printf("%d --> ", continuar);
			fflush(stdin);
		}while (continuar != 1);
		if(Ncantidad==cantidad){ //mensaje en caso de escribir la cantidad actual...
			SetConsoleTextAttribute(hConsole,4);  //<--Color Rojo
			printf("\nError, la cantidad es la misma, introduzca otra...");
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
		}
		if(Ncantidad<0){ //mensaje en caso de introducir numeros negativos
			SetConsoleTextAttribute(hConsole,4);  //<--Color Rojo
			printf("\nError, no puede introducir números negativos, introduzca otra vez...");
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
		}
	}while ((Ncantidad==cantidad)||(Ncantidad<0)); //hasta que sea un nuevo valor o que no sean numeros negativos
	
	fclose(arch2); //Siempre tenemos que cerrar el archivo para evitar errores
	printf("\n\n\tModificación exitosa!!\tRegresando....");
	Sleep(1000);
	
	return Ncantidad;
}
float validaPrecio(const char mensaje[], float precio){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	
	
	int continuar=0;
	float Nprecio=0.0;
	
	do{
		do{
			system("cls");
			printf("\nPrecio actual: $%.2f\n%s $",precio, mensaje);
			continuar = scanf("%f", &Nprecio);
			//printf("%d --> ", continuar);
			fflush(stdin);
		}while (continuar != 1);
		if(Nprecio==precio){ //mensaje en caso de escribir el actuál precio...
			SetConsoleTextAttribute(hConsole,4);  //<--Color Rojo
			printf("\nError, el costo es el mismo, introduzca otro...");
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
		}
		if(Nprecio<0){ //mensaje en caso de introducir numeros negativos
			SetConsoleTextAttribute(hConsole,4);  //<--Color Rojo
			printf("\nError, el costo no puede ser negativo, introduzca otro...");
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
		}
	}while ((Nprecio==precio)||(Nprecio<0)); //hasta que sea un nuevo precio o que no sean numeros negativos
	
	fclose(arch2); //Siempre tenemos que cerrar el archivo para evitar errores
	
	
	printf("\n\n\tModificación exitosa!!\tRegresando....");
	Sleep(1000);
	
	return Nprecio;
}
int entero(const char mensaje[]){
	
	int continuar=0;
	int entero=0;
	do{
		printf("\n%s",mensaje);
		fflush(stdin);
		continuar = scanf("%d", &entero);
	}while (continuar != 1);
	
	return entero;
}
void Nombre(const char mensaje[], char nombre[30]){
	bandera=true;
	
	while(bandera){ //mientras la bandera sea verdadera
		int numero=0;
		do{
			system("cls");
			
			gotoxy(10,4);
			printf("%s", mensaje);
			fflush(stdin);
			scanf(" %[^\n]", nombre);
		}while(strlen(nombre)<=0);
		
		for(int i=0; i<strlen(nombre); i++){
			if(isdigit(nombre[i])) numero++;
		}
		if((nombre[strlen(nombre)-1]==' ') || (numero!=0)){ //verifica que no haya un espacio al final de la cadena y que no hayan numeros
			gotoxy(10,6);
			printf("\nError, vuelva a escribir su nombre\tPresione para continuar......");
			getche();
		}else{
			gotoxy(10,6);
			printf("Nombre registrado correctamente!! ");
			bandera=false;
			Sleep(1000);
		}
	}
	
}
void Domicilio(const char mensaje[], char domicilio[20]){
	bandera=true;
	
	while(bandera){
		do{	
			system("cls");
			
			gotoxy(10,4);
			printf("%s", mensaje);
			fflush(stdin);
			scanf(" %[^\n]", domicilio);
		}while(strlen(domicilio)<=0);
		
		if((domicilio[strlen(domicilio)-1]==' ')){ //verifica que no haya un espacio al final de la cadena y que no hayan numeros
			gotoxy(10,6);
			printf("\nError, vuelva a escribir su nombre\tPresione para continuar......");
			getche();
		}else{
			gotoxy(10,6);
			printf("Domicilio registrado correctamente!! ");
			bandera=false;
			Sleep(1000);
		}
	}
}
int fila(){ //verificamos que el rango numerico sea correcto (de 0 a 4)
	int fil=0;
	do{
		fil=entero("\nFila: ");
	}while((fil<0) || (fil>4) || (isalpha(fil)) );
	return fil;
}
int columna(){ //verificamos que el rango numerico sea correcto (de 0 a 4)
	int col=0;
	do{
		col=entero("\nColumna: ");
	}while((col<0) || (col>4) || (isalpha(col)) );
	return col;
}
/*------------------------------------------------------------------------------*/
/*float flotante(const char mensaje[]){
	int continuar=0;
	//float flotante=0;
	float num = 0;
	
	do{
		printf("\n%s", mensaje);
		//continuar = scanf("f", &flotante);
		continuar = scanf("%f", &num);
		fflush(stdin);
	}while (continuar != 1);
	
	//return flotante;
	return num;
}
int entero(const char mensaje[]){
	
	int continuar=0;
	int entero=0;
	do{
		//system("cls");
		//system("color 03");
		printf("\n%s",mensaje);
		continuar = scanf("%d", &entero);
		fflush(stdin);
	}while (continuar != 1);
	
	return entero;
}
void cadena(const char mensaje[], char cadena[]){
	//setlocale(LC_CTYPE, "Spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	bool bandera=true;
	
	while(bandera){
		//system("cls");
		printf("\n%s", mensaje);
		scanf("%[^\n]", cadena);
		//scanf("%s", cadena);
		//gets(cadena);
		fflush(stdin);
		if(strlen(cadena)>19){
			//printf("Tamaño cadena -> %d \n", strlen(cadena));
			continue;
			//break;
		}else{
			for (int i =0; i<strlen(cadena); i++){
				if(isalpha(cadena[i]) || cadena[i]==' '){
					if(i== (strlen(cadena)-1)){
						bandera= false;
					}
				}else{
					break;
				}
			}
		}
	}
}

/*
#include <stdlib.h> //atoi -> convierte a entero una cadena
#include <ctype.h> //isdigit -> retorna cero si no es dígito
#include <string.h> //strlen -> tamaño de cadena
#include <stdio.h> 
#include <locale.h>
#include <windows.h>
#include <math.h> // pow, sqrt
#include <conio.h>

/*
int main(){
	int continuar = 0;
	float flotante = 0;
	
	/*printf("Dame el flotante: ");
	scanf("%f",&flotante);
	printf("El flotante es: %.2f", flotante); */
/*	
	do{
		//system("cls");
		system("color 0C");
		printf("Dame el flotante: ");
		continuar = scanf("%f", &flotante);
		printf("%d --> ", continuar);
		fflush(stdin);
	}while (continuar != 1);
	printf("El flotante es: %.2f", flotante);
	
	return 0;
}
*/
/*
int main(){
	int continuar = 0;
	int entero = 0;
	
	do{
		system("cls");
		system("color 03");
		printf("Dame el entero: ");
		continuar = scanf("%d", &entero);
		fflush(stdin);
	}while(continuar!=1);
	printf("El entero es: %d", entero);
	
	return 0;
}
*/

//VALIDACION POCO FUNCIONAL
/*
int main(){
	int continuar = 0;
	char cadena[10]="";
	printf("Palau Andrade Arturo \n");
	
	do{
		//system("cls");
		system("color 03");
		printf("Dame la cadena: ");
		continuar=scanf("%[^\n]",cadena);
		fflush(stdin);
	}while (continuar!=1);
	printf("La cadena es: %s", cadena);
	return 0;
}
*/

//ESTA TAMPOCO ME GUSTA :(
/*
int main (){
	bool bandera = true;
	char cadena[20]="";
	printf("Palau Andrade Arturo\n");
	
	while(bandera){
		system("cls");
		printf("Dame la cadena: ");
		fgets(cadena, 10, stdin); //se deben introducir exactamente 9 caracteres
		fflush(stdin);
		
		for (int i = 0; i<strlen(cadena); i++){
			if(isalpha(cadena[i]) || cadena[i]==' '){
				if(i==(strlen(cadena)-1)){
					printf("i = %d cadena-1 = %d", i, (strlen(cadena)-1));
					bandera=false;
				}
			}else break;
		}
	}
	printf("La cadena es: %s",cadena);
	
	return 0;
}
*/


/*int main(){
	//setlocale(CL_CTYPE, "Spanish");
	SetConsoleCP(1252); //STDIN codificación de windows 1252
	SetConsoleOutputCP(1252); //STDOUT
	bool bandera = true;
	
	char cadena[10]="";
	printf("Palau Andrade Arturo\n");
	
	while(bandera){
		//system("cls");
		printf("Dame la cadena: ");
		scanf("%[^\n]",cadena);
		//scanf("%s",cadena);
		//gets(cadena);
		fflush(stdin);
		if(strlen(cadena)>6){
			printf("Tamaño cadena -> %d \n",strlen(cadena));
			continue;
			//break;
		}else{
			for(int i = 0; i<strlen(cadena); i++){
				if(isalpha(cadena[i]) || cadena[i]==' '){
					if (i== (strlen(cadena)-1)){
						printf("i = %d cadena-1 = %d ", i, (strlen(cadena)-1));
						bandera=false;
					}
				}else{
					break;
				}
			}
		}
	}
	printf("La cadena es %s ", cadena);
	
	return 0;
}


/*
int main(){
	char cadena[6]="";
	bool bandera = true;
	float flotante=0;
	int cont=0;
	
	while(bandera){
		printf("Flotante: ");
		scanf("%[^\n]",cadena);
		fflush(stdin);
		if(strlen(cadena)>5){
			continue;
		}else{
			for(int i=0; i<strlen(cadena); i++){
				if( !(isdigit(cadena[i])) ){
					if(cadena[i]=='.' && cont==0){
						cont++;
					}else{
						cont=0;
						break;
					}
				}
				if(i == (strlen(cadena)-1)){
					flotante = atof(cadena);
					printf("El flotante es: %.2f \n", flotante);
					getch();
					bandera=false;
				}
			}
		}
	}
	return 0;
}
*/

/*
int main(){
	char cadena[6]="";
	bool bandera=true;
	int entero=0;
	
	while(bandera){
		printf("N%cmero: ", 163);
		scanf("%[^\n]",cadena);
		fflush(stdin);
		if(strlen(cadena)>5){
			continue;
		}else{
			for(int i = 0; i<strlen(cadena); i++){
				if(isdigit(cadena[i])){
					if(i== (strlen(cadena)-1)){
						entero = atoi(cadena);
						printf("pow: %.2lf \n", pow(entero,3));
						printf("sqrt: %.2lf \n", sqrt(entero));
						bandera=false;
					}
				}else{
					break;
				}
			}
		}
	}
	return 0;
} 
*/
