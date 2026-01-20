void menuProyecto();
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu(int,int,int,int,int &);
void mostrarRegistros();
void Fondos();
void modificarParticipantes();
void modificarCostos();
void PremiosEntregados();
void Fondos();
void boletosVendidos();

void menu(int x, int y, int inicial, int final, int &opc){
	char tecla='\0'; //' '
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); //color verde
	
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			//printf("%d", tecla);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			
			gotoxy(x,y);
			printf("%c",16);
			if(opc>inicial&&tecla==72){
				y--;
				opc--;
			}
			if(opc<final &&tecla==80){
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13); //13--> enter
}
void menuProyecto(){
	setlocale(LC_CTYPE, "Spanish");
	int opc=0;
	int x=0;
	int y=0;
	
	while (opc != 6){
		system("color 02");
		x=25;
		y=5;
		system("cls");
		
		gotoxy(x,y);
		printf("1) Venta de boletos\n");
		gotoxy(x,++y);
		printf("2) Consulta de boletos\n");
		gotoxy(x,++y);
		printf("3) Consulta de premios ganados\n");
		gotoxy(x,++y);
		printf("4) Fondos recaudados\n");
		gotoxy(x,++y);
		printf("5) Configuración\n");
		gotoxy(x,++y);
		printf("6) Salir del Sistema\n");
		gotoxy(x,++y);
		/*printf("\nDame la opción: ");
		scanf("%d", &opc);*/
		menu(22,5,1,6,opc);
		
		system("cls");

		gotoxy(10,4);
		switch(opc){
			case OPC1:
				menu1();
				getch();
				break;
			case OPC2:
				menu2();
				getch();
				break;
			case OPC3:
				menu3();
				getch();
				break;
			case OPC4:
				menu4();
				getch();
				break;
			case OPC5:
				menu5();
				getch();
				break;
			case OPC6:
				system("color 60");
				printf("Adiós y tenga un lindo día :)");
				exit(0);
		}
	}
}
void menu1(){
	setlocale(LC_CTYPE, "Spanish");
	int opc=0;
	int x=0;
	int y=0;
	
		while (opc != 2){
			system("color 02");
			x=30;
			y=5;
			system("cls");
			gotoxy(x,y);
			printf(">> Registrarse\n");
			gotoxy(x,++y);
			printf(">> Regresar al menu principal\n");
			menu(27,5,1,2,opc);
			system("cls");
			
			gotoxy(10,4);
			switch(opc){
				case OPC1:
					agregarRegistro();
					getch();
					menu1();
					break;
				case OPC2:
					printf("Regresando.");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					menuProyecto();
					break;
		}
	}
}
void menu2(){
	setlocale(LC_CTYPE, "Spanish");
	int opc=0;
	int x=0;
	int y=0;
	
		while (opc != 2){
			system("color 02");
			x=30;
			y=5;
			system("cls");
			gotoxy(x,y);
			printf(">> Ver boletos vendidos\n");
			gotoxy(x,++y);
			printf(">> Regresar al menu principal\n");
			menu(27,5,1,2,opc);
			system("cls");
			
			gotoxy(10,4);
			switch(opc){
				case OPC1:
					boletosVendidos();
					getch();
					menu2();
					break;
				case OPC2:
					printf("Regresando.");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					menuProyecto();
					break;
		}
	}
}
void menu3(){
	setlocale(LC_CTYPE, "Spanish");
	int opc=0;
	int x=0;
	int y=0;
		while (opc != 2){
			system("color 02");
			x=30;
			y=5;
			system("cls");
			gotoxy(x,y);
			printf(">> Consultar premios entregados\n");
			gotoxy(x,++y);
			printf(">> Regresar al menu principal\n");
			menu(27,5,1,2,opc);
			system("cls");
			
			gotoxy(10,4);
			switch(opc){
				case OPC1:
					PremiosEntregados();
					getch();
					menu3();
					break;
				case OPC2:
					printf("Regresando.");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					menuProyecto();
					break;
		}
	}
}
void menu4(){
	setlocale(LC_CTYPE, "Spanish");
	int opc=0;
	int x=0;
	int y=0;
	
		while (opc != 2){
			system("color 02");
			x=30;
			y=5;
			system("cls");
			gotoxy(x,y);
			printf(">> Mostrar fondos recaudados\n");
			gotoxy(x,++y);
			printf(">> Regresar al menu principal\n");
			menu(27,5,1,2,opc);
			system("cls");
			
			gotoxy(10,4);
			switch(opc){
				case OPC1:
					Fondos();
					getch();
					menu4();
					break;
				case OPC2:
					printf("Regresando.");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					menuProyecto();
					break;
		}
	}
}
void menu5(){
	setlocale(LC_CTYPE, "Spanish");
	int opc=0;
	int x=0;
	int y=0;
	
		while (opc != 3){
			system("color 02");
			x=30;
			y=5;
			system("cls");
			gotoxy(x,y);
			printf(">> Modificar cantidad de boletos para comprar\n");
			gotoxy(x,++y);
			printf(">> Modificar costos de boletos\n");
			gotoxy(x,++y);
			printf(">> Regresar al menu principal\n");
			menu(27,5,1,3,opc);
			system("cls");
			
			gotoxy(10,4);
			switch(opc){
				case OPC1:
					modificarParticipantes();
					getche();
					menu5();
					break;
					
				case OPC2:
					modificarCostos();
					getche();
					menu5();
					break;
					
				case OPC3:
					printf("Regresando.");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					Sleep(500);
					printf(".");
					menuProyecto();
					break;
		}
	}
}
