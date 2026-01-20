#include "libreria.h"

int main(){
	//Función para ajustar el tamaño de la pantalla
	system("mode con: cols=140 lines=100");
	
	portada(); //portada decorada
	datos(); //datos académicos
	//crear_archivo(); //<-creamos el archivo manualmente si hace falta
	menuProyecto(); //proyecto
}
