#include <stdio.h>
struct info_dir{
	char direccion[35];
	char ciudad[25];
	char municipio[25];
	long int CP;
};
typedef struct{
	char Nom_Emp[35];
	struct info_dir Dir_Emp;
	double salario;
}empleado;

typedef struct{
	char Nom_Cli[35];
	struct info_dir Dir_Clien;
	double saldo;
}cliente;

int main(){
	printf("Palau Andrade Arturo, 178561\n");
	
	
	
	return 0;
}
