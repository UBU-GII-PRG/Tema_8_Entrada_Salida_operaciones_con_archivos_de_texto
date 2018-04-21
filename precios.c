/*
Programa:	precios.c
Sinopsis:	Creamos un fichero escribiendo repcios de artículos.
		Los precios se escriben sólo con dos decimales

@author:	Paco González Moya
@version:	1.0
@date:		Apr 2018	
*/
#include <stdio.h>
#define	FILENAME "precios.txt"

//Prototipos de funciones 
void abrirFichero(FILE **pf);
void escribeFichero (FILE *pf, float precio);
void cierraFichero (FILE *pf);

int main() {
	FILE *pf;	//Puntero a fichero
	int ok;		//variable para estado
	float precio;	//variable para ller los precios

	//Recordamos: vals 1-2-3

	printf("Escribe precios de artículos pulsa '0' para terminar\n");
	printf("-------------------------------------------------\n");

	//1. Apertura
	abrirFichero(&pf);
	if (pf==NULL) {
		printf("\nImposible abrir el fichero\n");
	} else {
		
		//Bucle de lectura desde teclado y escritura (l. adelantada)
		printf("\nTeclea precio: ");
		ok=scanf("%f", &precio);
		while (precio!=0.0 && ok==1) {
			//2. Escribe en el fichero
			escribeFichero(pf, precio); //Escritura en fichero
			//Lectura desde teclado
			printf("\nTeclea precio: ");
			ok=scanf("%f", &precio);
		}
		//3. Cierre del fichero
		cierraFichero(pf);
	}
	return 0;
}

/**
Abrimos el fichero	
*/
void abrirFichero (FILE **pf) {
	*pf=fopen(FILENAME, "w");
	return;
}

/**
Escritura en el fichero
*/
void escribeFichero (FILE *pf, float precio) {
	fprintf(pf, "%5.2f\n", precio);
	return;
}

/**
Cierre del fichero
*/
void cierraFichero (FILE *pf) {
	fclose (pf);
	return;
}
