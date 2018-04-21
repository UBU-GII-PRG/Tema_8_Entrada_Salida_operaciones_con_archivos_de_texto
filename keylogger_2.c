/*
Programa:	vals_2.c
Sinopsis:	Metáfora que nos ayuda a entender la gestión de archivos
		secuenciales de texto. Tres movimientos (como en el vals): 
		1) Apertura
		2) Lectura o escritura 
		3) Cierre

@author:	Paco González Moya
@version:	2.0
		Apertura en modo "append"
@date:		Apr 2018	
*/
#include <stdio.h>
#define	FILENAME "keylogger.txt"

int main() {
	FILE *pf;	//Puntero a fichero
	char c;		//variable de lectura
	int ok;		//variable para estado

	printf("Escribe lo que quieras y pulsa '0' para terminar\n");
	printf("-------------------------------------------------\n");

	//1. Apertura
	pf=fopen(FILENAME, "a");
	if (pf==NULL){
		printf("Error en la apertura del fichero\n");
	} else {
		//Bucle de lectura desde teclado y escritura
		c=getchar();
		while (c!='0') {
			ok=fputc(c, pf);	//Escritura en fichero
			c=getchar();		//Lectura desde teclado
		}

		//Tercer movimiento: cierre. VITAL en modo "w" o "a"
		ok=fclose(pf);
		if (ok==0) {
			printf("3.Cierre correcto del fichero\n");
		} else  {
			printf("Problemas en el cierre del fichero\n");
		}

		
	}

	


}
