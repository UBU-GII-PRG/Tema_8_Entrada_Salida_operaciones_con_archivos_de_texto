/*
Programa:	vals_2.c
Sinopsis:	Metáfora que nos ayuda a entender la gestión de archivos
		secuenciales de texto. Tres movimientos (como en el vals): 
		1) Apertura
		2) Lectura o escritura 
		3) Cierre

@author:	Paco González Moya
@version:	2.0
		Incorpora el bicle de lectura y escribimos el texto de forma 
		contínua
@date:		Apr 2018	
*/
#include <stdio.h>
#define	FILENAME "datos.txt"

int main() {
	FILE *pf;	//Puntero a fichero
	char c;		//Variable de lectura
	int ok;		//variable para obtener el estado de cierre


	//Primer movimiento: apertura del fichero
	pf=fopen(FILENAME, "r");
	if (pf==NULL){
		printf("Error en la apertura del fichero\n");
	} else {
		//Apertura correcta:
		printf("1.Apertura ok del fichero\n");

		//Segundo movimiento: lectura. Mediante bucle
		c=fgetc(pf);	//técnica de lectura adelantada

		while (!feof(pf)) { 	//Comprobamos que no se ha llegado a EOF
					//(precipicio)

			//Hemos podido leer un caracter: lo mostramos
			//No damos más mensajes, para ver contenido del fichero
			printf("%c", c);

			//Seguimos leyendo
			c=fgetc(pf);	
		}

	

		//Tercer movimiento: cierre
		ok=fclose(pf);
		if (ok==0) {
			printf("3.Cierre correcto del fichero\n");
		} else  {
			printf("Problemas en el cierre del fichero\n");
		}

	}
	return 0;
}	

