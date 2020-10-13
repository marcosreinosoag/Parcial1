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
#include "aviso.h"


int main(void) {
	setbuf(stdout,NULL);
	int opcionMenu;
	Cliente arrayCliente[QTY_CLIENTES];
	Aviso arrayAviso[1000];
	cliente_init(arrayCliente, QTY_CLIENTES);
	aviso_init(arrayAviso,QTY_AVISOS);

	do
	{
		utn_getEntero("\nBIENVENIDO!!!!!!!!!!!!!!!!!!\n1-Cargar Cliente\n2- Modificar Cliente\n3- Dar de baja un Cliente\n4-Realizar una Publicación"
		 "\n5-Pausar Publicacion\n6-Reanudar Publicacion\n7-Imprimir Clientes\n8-Realizar Consulta\n9-Salir\n","\nError!!!! reingrese numero!!!", &opcionMenu,3,8,1);
		switch(opcionMenu)
		{
		case 1:
			cliente_alta(arrayCliente, QTY_CLIENTES);
			break;
		case 2:
			cliente_modificar (arrayCliente,QTY_CLIENTES);
			break;
		case 3:
			cliente_baja(arrayCliente,QTY_CLIENTES,arrayAviso,QTY_AVISOS);
			break;
		case 4:
			aviso_alta(arrayAviso,QTY_AVISOS,arrayCliente,QTY_CLIENTES);
			break;
		case 5:
			aviso_pausarpublicacion (arrayCliente,QTY_CLIENTES,arrayAviso,QTY_AVISOS);
			break;
		case 6:
			aviso_reaunudarpublicacion (arrayCliente,QTY_CLIENTES,arrayAviso,QTY_AVISOS);
			break;
		case 7:
			cliente_imprimirAvisos(arrayAviso,QTY_AVISOS,arrayCliente,QTY_CLIENTES);
			break;
		case 8:
			menu_Consultas(arrayAviso,QTY_AVISOS,arrayCliente,QTY_CLIENTES);
			break;
		}
	}while(opcionMenu !=9);
}
