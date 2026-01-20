#include <stdio.h>
#include <windows.h>

int main(){   
    int c;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (c=0; c<256; c++){
		SetConsoleTextAttribute(hConsole, c);
		printf ("Color numero %i\n",c); 
    }
	SetConsoleTextAttribute(hConsole, 7);
    system("pause");
    
    return 0;
}
