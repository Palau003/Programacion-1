void portada(){
	int aux = 0;
	FILE *archivo = fopen("portadajsjs.txt", "r");
	
	for(int i=0; i<59; i++){
		for(int j=0; j<49; j++){
			fscanf(archivo,"%d\t", &aux);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),aux);
			printf("%c", 177);
		}
		printf("\n");
	}
	
	fclose(archivo);
}

void datos(){
	setlocale(LC_CTYPE, "Spanish");
	gotoxy(65, 35);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Universidad Politécnica de San Luis Potosí");
	gotoxy(65, 37);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Programación I Lenguaje C");
	gotoxy(65, 39);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Alumno: Palau Andrade Arturo - 178561");
	gotoxy(65, 41);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Alumno: Torres García Victor Isaac - 176030");
	gotoxy(65, 43);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Carrera: ITI");
	gotoxy(65, 45);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Proyecto Final - El sorteo -\n");
	gotoxy(65, 47);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Maestra: Araceli Gabriela Aguilar");
	gotoxy(65, 49);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	printf("Tab to begin...");
	getch();
}
