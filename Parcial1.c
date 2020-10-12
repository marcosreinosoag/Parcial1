/*
 ============================================================================
 Name        : Parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#define QTY_CLIENTES 100
#define QTY_PUBLICACIONES 1000

int main(void) {
	setbuf(stdout,NULL);
	int opcionMenu;
	Cliente arrayCliente[QTY_CLIENTES];
	cliente_init(arrayCliente, QTY_CLIENTES);

	do
	{
		if(utn_getEntero("BIENVENIDO!!\n1-Cargar Cliente\n2- Modificar Cliente\n3- Dar de baja un Cliente\n4-Realizar una Publicación"
		 "\n5-Pausar Publicacion\n6-Reanudar Publicacion\n7-Imprimir Clientes\n8-Realizar Consulta\n","Error!!!! reingrese numero!!!", &opcionMenu,3,8,1)==-1)
		{
			break;
		}
		switch(opcionMenu)
		{
		case 1:
			cliente_alta(arrayCliente, QTY_CLIENTES);
			break;
		case 2:
			cliente_modificar (arrayCliente,QTY_CLIENTES);
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		}
	}while(opcionMenu>0 && opcionMenu<9);
}
