void menu(int,int,int,int,int &); //Esta es la que permite movernos de arriba hacia abajo
void menuProyecto(); //los volvemos a poner aquí para que reconozca la función aunque no esten en orden
void crear_archivo();
void crear_archivo2();
void agregarRegistro();
void modifCostos(float &, float &, float &);
void menu5();
void leer_archivo2();

void boletosVendidos(){ //menu 2
	setlocale(LC_CTYPE, "Spanish"); //para que muestre la info en español
	Registro participantes;
	int i=5;
	
	if(!(arch=fopen("participantes.xls","r"))){
		printf("\nError al intentar leer el archivo :(\nSe requiere haber participado almenos 1 vez...");
		Sleep(1500);
		menuProyecto();
	}
	gotoxy(1,3);
	printf(" Nombre");
	gotoxy(27,3);
	printf("Domicilio");
	gotoxy(47,3);
	printf("Código");
	gotoxy(61,3);
	printf("Básico");
	gotoxy(73,3);
	printf("Oro");
	gotoxy(82,3);
	printf("Premium");
	while(!(feof(arch))){
		fscanf(arch,"%[^\t]\t", participantes.nombre);
		fscanf(arch,"%[^\t]\t", participantes.domicilio);
		fscanf(arch,"%s\t", participantes.codigo);
		fscanf(arch,"%d\t", &participantes.comprados.basico);
		fscanf(arch,"%d\t", &participantes.comprados.oro);
		fscanf(arch,"%d\t", &participantes.comprados.premium);
		fscanf(arch,"%f\t", &participantes.saldo);
		fscanf(arch,"%f\t", &participantes.hechos.inversion);
		fscanf(arch,"%f\t", &participantes.hechos.ganancias);
		fscanf(arch,"%f\n", &participantes.hechos.total);
		/*--------------------------------------------------*/
		gotoxy(1,i);
		printf("%s", participantes.nombre);
		gotoxy(25,i);
		printf("%s", participantes.domicilio);
		gotoxy(47,i);
		printf("  %s", participantes.codigo);
		gotoxy(61,i);
		printf("  %d", participantes.comprados.basico);
		gotoxy(73,i);
		printf("  %d", participantes.comprados.oro);
		gotoxy(82,i);
		printf("  %d", participantes.comprados.premium);
		i++;
	}
	fclose(arch);
	gotoxy(1,i+2);
	printf("\n\t\tPrecione para continuar......");
}
void Fondos(){ //Menu 4
	setlocale(LC_CTYPE, "Spanish"); //para que muestre la info en español
	Registro participantes;
	if(!(arch=fopen("participantes.xls","r"))){
		printf("\nError al intentar leer el archivo :(\nSe requiere haber participado almenos 1 vez...");
		Sleep(1500);
		menuProyecto();
	}
	float ganancia=0, gananciaTotal=0;
	int i=5;
	gotoxy(1,3);
	printf("Nombre");
	gotoxy(16,3);
	printf("Código");
	gotoxy(24,3);
	printf("Básico");
	gotoxy(36,3);
	printf("Premium");
	gotoxy(48,3);
	printf("Oro");
	gotoxy(55,3);
	printf("Inversión");
	gotoxy(68,3);
	printf("Premio");
	gotoxy(83,3);
	printf("Ganancia");
	while(!feof(arch)){
		fscanf(arch,"%[^\t]\t", participantes.nombre);
		fscanf(arch,"%[^\t]", participantes.domicilio);
		fscanf(arch,"%s\t", participantes.codigo);
		fscanf(arch,"%d\t", &participantes.comprados.basico);
		fscanf(arch,"%d\t", &participantes.comprados.oro);
		fscanf(arch,"%d\t", &participantes.comprados.premium);
		fscanf(arch,"%f\t", &participantes.saldo);
		fscanf(arch,"%f\t", &participantes.hechos.inversion);
		fscanf(arch,"%f\t", &participantes.hechos.ganancias);
		fscanf(arch,"%f\n", &participantes.hechos.total);
		
		gotoxy(1,i);
		printf(" %s", participantes.nombre);
		gotoxy(16,i);
		printf("%s", participantes.codigo);
		gotoxy(24,i);
		printf("%d", participantes.comprados.basico);
		gotoxy(36,i);
		printf("%d", participantes.comprados.oro);
		gotoxy(48,i);
		printf("%d", participantes.comprados.premium);
		gotoxy(55,i);
		printf("$%.2f", participantes.hechos.inversion);
		gotoxy(68,i);
		printf("$%.2f", participantes.hechos.ganancias);
		gotoxy(83,i);
		printf("$%.2f", participantes.hechos.total);
		
		gananciaTotal+=participantes.hechos.total;//esta es la ganancia total (ganancia o perdida)
		i++;
	}
	gotoxy(70,i+2);
	printf("Ganancia Total: $%.2f", gananciaTotal);
	
	fclose(arch); //cerramos el archivo
	gotoxy(1,i+2);
	printf("\nPresione para continuar......");
}
void modificarParticipantes(){ //Menu 5
	setlocale(LC_CTYPE, "Spanish"); //para que muestre la info en español
	int opc=0;
	leer_archivo2();
	
	do{
		system("cls");
		
		gotoxy(0,3);
		printf("----------------Modificar Disponibilidad de boletos-------------");
		gotoxy(5,7);
		printf(" 1) Disponible/participante: %d unidades - Boleto Básico ", *pNbas);
		gotoxy(5,9);
		printf(" 2) Disponible/participante: %d unidades - Boleto Premium ", *pNpre);
		gotoxy(5,11);
		printf(" 3) Disponible/participante: %d unidades - Boleto Oro ", *pNoro);
		gotoxy(5,13);
		printf(" 4) Regresar al menu");
		gotoxy(5,15);
		do{
			opc=entero("Opción a realizar: ");
		}while((opc<0) || (opc>5));
		if(opc==1) *pNbas=validaNumero("Nueva cantidad: ",*pNbas);
		if(opc==2) *pNpre=validaNumero("Nueva cantidad: ",*pNpre);
		if(opc==3) *pNoro=validaNumero("Nueva cantidad: ",*pNoro);
		
	
	}while(opc!=4);
	if(!(arch2=fopen("precios.txt","w"))){
		printf("\nError al crear el archivo...");
		exit(1);	
	}
	//registramos todo en el archivo de nuevo ya que se esta sobre escribiendo
	fprintf(arch2,"%f\n", *pBas);
	fprintf(arch2,"%f\n", *pPre);
	fprintf(arch2,"%f\n", *pO);
	
	fprintf(arch2,"%d\n", *pNbas);
	fprintf(arch2,"%d\n", *pNpre);
	fprintf(arch2,"%d\n", *pNoro);
	
	fclose(arch2);
	if(opc==4){
		system("cls");
		gotoxy(10,5);
		printf("Regresando.");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		menu5();   
	}
}
void modificarCostos(){ //Menu 5
	setlocale(LC_CTYPE, "Spanish"); //para que muestre la info en español
	int opc=0;
	leer_archivo2();
	
	do{
		system("cls");
		
		gotoxy(0,3);
		printf("----------------Modificar precio de boletos-------------");
		gotoxy(5,7);
		printf(" 1) Precio actual/boleto: $%.2f Boleto Básico ", *pBas);
		gotoxy(5,9);
		printf(" 2) Precio actual/boleto: $%.2f Boleto Premium ", *pPre);
		gotoxy(5,11);
		printf(" 3) Precio actual/boleto: $%.2f Boleto Oro ", *pO);
		gotoxy(5,13);
		printf(" 4) Regresar al menu");
		gotoxy(5,15);
		do{
			opc=entero("Opción a realizar: ");
		}while((opc<0) || (opc>5));
		if(opc==1) *pBas=validaPrecio("Nuevo precio: ",*pBas);
		if(opc==2) *pPre=validaPrecio("Nuevo precio: ",*pPre);
		if(opc==3) *pO=validaPrecio("Nuevo precio: ",*pO);
		
	
	}while(opc!=4);
	if(!(arch2=fopen("precios.txt","w"))){
		printf("\nError al crear el archivo...");
		exit(1);	
	}
	//registramos todo en el archivo de nuevo ya que se esta sobre escribiendo
	fprintf(arch2,"%f\n", *pBas);
	fprintf(arch2,"%f\n", *pPre);
	fprintf(arch2,"%f\n", *pO);
	
	fprintf(arch2,"%d\n", *pNbas);
	fprintf(arch2,"%d\n", *pNpre);
	fprintf(arch2,"%d\n", *pNoro);
	
	fclose(arch2);
	if(opc==4){
		system("cls");
		gotoxy(10,5);
		printf("Regresando.");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		menu5();
	}
}
void PremiosEntregados(){ //Menu 3
	setlocale(LC_CTYPE, "Spanish"); //para que muestre la info en español
	Registro participantes;
	
	int i=4;
	
	if(!(arch=fopen("participantes.xls","r")) ){
		printf("\nError al intentar leer el archivo :(\nSe requiere haber participado almenos 1 vez...");
		Sleep(1500);
		menuProyecto();
	}
	gotoxy(3,2);
	printf("Nombre");
	gotoxy(18,2);
	printf("Código");
	gotoxy(27,2);
	printf("Premios");
	while(!feof(arch)){
		fscanf(arch,"%[^\t]\t", participantes.nombre);
		fscanf(arch,"%[^\t]\t", participantes.domicilio);
		fscanf(arch,"%s\t", participantes.codigo);
		fscanf(arch,"%d\t", &participantes.comprados.basico);
		fscanf(arch,"%d\t", &participantes.comprados.oro);
		fscanf(arch,"%d\t", &participantes.comprados.premium);
		fscanf(arch,"%f\t", &participantes.saldo);
		fscanf(arch,"%f\t", &participantes.hechos.inversion);
		fscanf(arch,"%f\t", &participantes.hechos.ganancias);
		fscanf(arch,"%f\n", &participantes.hechos.total);
		/*-------------------------------------------------*/
		gotoxy(3,i);
		printf("%s\t", participantes.nombre);
		gotoxy(18,i);
		printf("%s\t", participantes.codigo);
		gotoxy(27,i);
		printf("$%.2f\n", participantes.hechos.ganancias);
		i++;
	}
	
	fclose(arch);
	printf("\nPresione para continuar......");
}
void verificaCodigo(char codigo[5], char aux){ //verificamos que no se repita ningún caracter en el arreglo
	for(int i=0; i<5; i++){
		if(codigo[i]==aux){
			bandera=false;
			break;
		}else if(i==4){
			bandera=true;
			break;
		}
	}
}
void destapar(float tab1[][5], float tab2[][5], int casilla[][5], int &intentos, float &saldo, float &premios){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int fil=0, col=0;
	
	system("cls");
	gotoxy(6,2);
	printf("Intendos restantes: %d\tSaldo acumulado: $%.2f\n", intentos, saldo);
	
	printf("\n  ---------------Tablero de las sorpresas---------------\n\n\tCol[0]\tCol[1]\tCol[2]\tCol[3]\tCol[4]");
	for(int i=0; i<5; i++){
		printf("\n\nFila %d\t", i);
		for(int j=0; j<5; j++){
			printf(" %.2f\t",tab2[i][j]);
		}
		printf("\n");
	}
	printf("\n\n  Seleccione las coordenadas de la casilla a destapar....\n\n");
	fil=fila();
	col=columna();
	
	if((tab2[fil][col]==0) && (tab1[fil][col]!=0)){
		tab2[fil][col]=tab1[fil][col];
		casilla[fil][col]=1;
		printf("\nFelicidades!! Saldo ganado: $%.2f\n\nPresione para continuar....", tab1[fil][col]);
		saldo+=tab1[fil][col]; //el saldo se incrementa a tu premio ganado
		premios=saldo;
		getch();
	}else if(casilla[fil][col]==1){ //si la casilla ya fue seleccionada con anterioridad
		printf("\nCelda ya descubierta! \n\nPresione para continuar....");
		intentos++; //se te suma un intento ya que esa casilla ya la habias seleccionado con anterioridad
		getch();
	}else{
		casilla[fil][col]=1; //aunque no se gane nada la casilla ya se destapo
		printf("\nMala suerte :(\n\nPresione para continuar....");
		getch();
	}
}
void verifica(float tab[5][5], int fil, int col){ //en esta funcion verificamos que en los tableros haya algo o no y lo rellenamos
	int num=0, dec=0;
	
	if((tab[fil][col] == 0)){
		num=5+rand()%(250-5);
		dec=0+rand()%(10);
		tab[fil][col]=dec;
		tab[fil][col]/=10;
		tab[fil][col]+=num;
			
		bandera = true;
	}
	else bandera = false;
}
void rellenar(float tab[][5]){ //manda randoms a una validación para ver si el tablero esta lleno o no
	srand(time(NULL));
	int fil=0, col=0, cont=0;
	do{
		do{
			fil=0+rand()%(5);
			col=0+rand()%(5);
			printf("\n\nFila: %d\nColu: %d", fil, col);
			verifica(tab,fil,col);
		}while(bandera!=true);
		//printf("\nNo: %d", cont+1);
		cont++;
	}while(cont<10);
}
float juega(int intentos, float &premios){
	Registro participantes;
	float tab[5][5]={0}, tapado[5][5]={0}, aux=0; //un arreglo para llenar con valores y el otro en 0 para mostrar al usuario
	int casilla[5][5]={0}; //este verifica cuando una casilla ya fue seleccionada
	premios=0; //inicializamos en 0 para futuras corridas
	rellenar(tab); //funcion para rellenar el tablero
	do{
		destapar(tab,tapado,casilla,intentos, participantes.saldo, premios);
		intentos--;
	}while(intentos!=0);
	system("cls");
	printf("\n\n\tJuego acabado!!\n\n\tGanaste en total: $%.2f", premios);
	Sleep(2000);
	system("cls");
	return participantes.saldo;
}
void compra(char usuario[30], float &saldo, float &inversion, float &premios, float &total){
	setlocale(LC_CTYPE, "Spanish"); //para que muestre la info en español
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	Registro participantes;
	participantes.comprados.basico=0;
	participantes.comprados.oro=0;
	participantes.comprados.premium=0;
	
	leer_archivo2();
	float premioAcumulado=0;
	setlocale(LC_CTYPE, "Spanish");
	int opc=0;
	int x=0;
	int y=0;
	
	
	while (opc != 6){
		system("color 02");
		x=25;
		y=5;
		system("cls");
		
		gotoxy(2,2);
		printf("Usuario: %s\n  Saldo: $%.2f",usuario, saldo);
		
		gotoxy(x,y);
		printf("1) $%.2f - Categoría Básica\n", *pBas);
		gotoxy(x,++y);
		printf("2) $%.2f - Categoría Premium\n", *pPre);
		gotoxy(x,++y);
		printf("3) $%.2f - Categoría Oro\n", *pO);
		gotoxy(x,++y);
		printf("4) Regresar al menu\n");
	
		menu(22,5,1,4,opc);
		
		system("cls");

		gotoxy(10,4);
		switch(opc){
			
			case OPC1: if(saldo<(*pBas)){
							SetConsoleTextAttribute(hConsole,4);  //<--Color Rojo
							printf("Saldo insuficiente!!\tPresione para continuar.....");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
							getche();
							break;
						}
						if(participantes.comprados.basico==(*pNbas)){
							SetConsoleTextAttribute(hConsole,4);  //<--Color Rojo
							printf("Limite de boletos comprados tipo Básico alcanzado!!\tPresione para continuar.....");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
							getche();
							break;
						}
						saldo-=(*pBas); //Se le resta el precio al saldo
						inversion+=(*pBas); //multiplicamos por -1 porque las inversiones son lo que ganamos
						saldo+=juega(1, premios);
						premioAcumulado+=premios;
						premios=0;
						participantes.comprados.basico++; //Aumenta el tipo de boleto
						break;
						
			case OPC2: if(saldo<(*pPre)){
							SetConsoleTextAttribute(hConsole,4); //Color rojo
							printf("Saldo insuficiente!!\tPresione para continuar.....");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
							getche();
							break;
						}
						if(participantes.comprados.premium==(*pNpre)){
							SetConsoleTextAttribute(hConsole,4);  //<--Color Rojo
							printf("Limite de boletos comprados tipo Premium alcanzado!!\tPresione para continuar.....");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
							getche();
							break;
						}
						saldo-=(*pPre); //Se le resta el precio al saldo
						inversion+=(*pPre); //multiplicamos por -1 porque las inversiones son lo que ganamos
						saldo+=juega(3, premios);
						premioAcumulado+=premios;
						premios=0;
						participantes.comprados.oro++; //Aumenta el tipo de boleto
						break;
						
			case OPC3: if(saldo<(*pO)){
							SetConsoleTextAttribute(hConsole,4); //<--Color rojo
							printf("Saldo insuficiente!!\tPresione para continuar.....");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
							getche();
							break;
						}
						if(participantes.comprados.oro==(*pNoro)){
							SetConsoleTextAttribute(hConsole,4);  //<--Color Rojo
							printf("Limite de boletos comprados tipo Oro alcanzado!!\tPresione para continuar.....");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //Color verde
							getche();
							break;
						}
						saldo-=(*pO); //Se le resta el precio al saldo
						inversion+=(*pO); //multiplicamos por -1 porque las inversiones son lo que ganamos
						saldo+=juega(5, premios);
						premioAcumulado+=premios;
						premios=0;
						participantes.comprados.premium++; //Aumenta el tipo de boleto
						break;
						
			case OPC4:	total=(inversion-premioAcumulado);
						fprintf(arch, "%d\t", participantes.comprados.basico);
						fprintf(arch, "%d\t", participantes.comprados.oro);
						fprintf(arch, "%d\t", participantes.comprados.premium);
						fprintf(arch, "%f\t", saldo); //Registramos en el archivo todos los movimientos y saldo final
						fprintf(arch, "%f\t", inversion);
						fprintf(arch, "%f\t", premioAcumulado);
						fprintf(arch, "%f\n", total);
						
						fclose(arch);
						
						system("cls");
						printf("\n\n\t\tRegresando.");
						Sleep(500);
						printf(".");
						Sleep(500);
						printf(".");
						Sleep(500);
						printf(".");
						menuProyecto(); //Regresamos al menu Principal tras finalizar nuestros juegos
						break;
		}
	}
}
void Codigo(char codigo[5]){//funcion para asignar codigo al usuario
	char aux;
	for(int i=0; i<5; i++){
		do{
			aux=65+rand()%(91-65);
			verificaCodigo(codigo,aux);
		}while(bandera!=true);
		codigo[i]=aux;
	}
}
void registrarse(){ //Menu 1
	srand(time(NULL));
	Registro participantes;
	participantes.hechos.inversion=0; //inicializamos con valores 0 para evitar errores con datos basura
	participantes.hechos.ganancias=0;
	participantes.hechos.total=0;
	
	Codigo(participantes.codigo);
	Nombre("Introduzca su nombre: ", participantes.nombre);
	Domicilio("Introduzca su domicilio: ", participantes.domicilio);
	gotoxy(10,8);
	printf("Codigo asignado: %s", participantes.codigo);
	/*.......Registramos el nombre, dimicilio y codigo de jugador........*/
	fprintf(arch,"%s\t", participantes.nombre);
	fprintf(arch,"%s\t", participantes.domicilio);
	fprintf(arch,"%s\t", participantes.codigo);
	
	
	participantes.saldo=500; //Asignamos el saldo inicial
	gotoxy(10,10);
	printf("Registro completo!!");
	Sleep(1500);
	compra(participantes.nombre, participantes.saldo, participantes.hechos.inversion, participantes.hechos.ganancias, participantes.hechos.total);
}
void crear_archivo(){ //<--Creamos el archivo
	if(!(arch=fopen("participantes.xls", "w"))){ //mensaje de error en caso de no crearse el archivo 
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	fclose(arch); //Siempre tenemos que cerrar el archivo para evitar errores
}
void agregarRegistro(){
	Registro participantes;
	leer_archivo2();
	
	if(!(arch=fopen("participantes.xls", "a"))){ //mensaje de error en caso de no abrirse el archivo 
		printf("\nError al intentar crear el archivo...");
		exit(1);
	}
	registrarse(); //una vez creado el archivo procedemos a registrar información dentro de el
	fclose(arch);//cerramos el archivo al finalizar el registro
}
void crear_archivo2(){ //aquí guardamos los precios de los boletos
	if(!(arch2=fopen("precios.txt", "w"))){ //mensaje de error en caso de no crearse el archivo 
		printf("Error al intentar crear el archivo");
		exit(1);
	}
	//aquí asignamos el valor inicial de los boletos
	*pBas=115.0;
	*pPre=275.0;
	*pO=495.0;
	//aquí asignamos la cantidad inicial de boletos a vender
	*pNbas = 5;
	*pNpre = 3;
	*pNoro = 2;
	
	fprintf(arch2,"%f\n",*pBas);
	fprintf(arch2,"%f\n",*pPre);
	fprintf(arch2,"%f\n",*pO);
	/*----------------------------*/
	fprintf(arch2,"%d\n", *pNbas);
	fprintf(arch2,"%d\n", *pNpre);
	fprintf(arch2,"%d\n", *pNoro);

	fclose(arch2); //Siempre tenemos que cerrar el archivo para evitar errores
}
void leer_archivo2(){ //leemos el archivo de los precios
	arch2=fopen("precios.txt","r");
	
	if(arch2==NULL){
		crear_archivo2();
		printf("\nArchivo creado");
		Sleep(1000);
	}
	fscanf(arch2,"%f",&P_boletos.pBasico); //asignamos el valor a la estructura de precios
	fscanf(arch2,"%f",&P_boletos.pPremium);
	fscanf(arch2,"%f",&P_boletos.pOro);
	
	fscanf(arch2,"%d",&P_boletos.mBas); //asignamos el numero a la estructura de vender N boletos
	fscanf(arch2,"%d",&P_boletos.mPrem);
	fscanf(arch2,"%d",&P_boletos.mOro);
	
	fclose(arch2);
}
