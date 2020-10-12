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

typedef struct{
	int idAviso;
	int numeroRubro;
	int estadoPublicacion;
	int idcliente;
	char textoAviso [CARACTERES_AVISO];
	int isEmpty;
}Aviso;



int aviso_init(Aviso * pArrays, int limite);
int aviso_alta(Aviso *arrayAviso,int limite, Cliente *pArrayClientes,int limit);
int aviso_imprimir (Aviso * pArrays , int limite);
int aviso_buscarIndicePorIdRef (Aviso * pArrays, int limite,int idBuscar,int * pIndice);
int aviso_buscarLibreRef(Aviso pArrayCliente[],int limit, int *pindex);



#endif /* AVISO_H_ */
