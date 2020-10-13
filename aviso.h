/*
 * aviso.h
 *
 *  Created on: 10 oct. 2020
 *      Author: marcos
 */

#ifndef AVISO_H_
#define AVISO_H_
#define CARACTERES_AVISO 60
#include"cliente.h"

#define LONG_NOMBRE 50
#define TRUE 1
#define FALSE 0
#define QTY_CARACTERES 60
#define QTY_CLIENTES 100
#define QTY_AVISOS 1000

typedef struct{
	int idAviso;
	int numeroRubro;
	int estadoPublicacion;
	int idcliente;
	char textoAviso [CARACTERES_AVISO];
	int isEmpty;
}Aviso;

int aviso_init(Aviso * pArrays, int limite);
int cliente_baja (Cliente * pArrays, int limite,Aviso *arrayAviso,int limit);
int aviso_imprimirAvisoPorID (Aviso * pArrays, int limite, Cliente * pArrayCliente , int limit,int id);
int aviso_bajaIdCliente(Aviso * pArrays, int limite,int idCliente);
int cliente_imprimirAvisos(Aviso * pArrays, int limite, Cliente * pArrayCliente , int limit);
int aviso_pausarpublicacion (Cliente * pArrays, int limite,Aviso *arrayAviso,int limit);
int menu_Consultas(Aviso * pArrays, int limite, Cliente * pArrayCliente , int limit);
int cliente_contadorAvisos(Aviso *arrayAviso,int limit,int idCliente,int *avisosdelcliente);
int aviso_alta(Aviso *arrayAviso,int limite, Cliente *pArrayClientes,int limit);
int aviso_buscarLibreRef(Aviso pArrayCliente[],int limit, int *pindex);

#endif /* AVISO_H_ */
