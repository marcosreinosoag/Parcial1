/*
 * cliente.h
 *
 *  Created on: 10 oct. 2020
 *      Author: marcos
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define LONG_NOMBRE 50
#define TRUE 1
#define FALSE 0
typedef struct{
	char nombre [LONG_NOMBRE];
	char apellido[LONG_NOMBRE];
	char cuit[LONG_NOMBRE];
	int isEmpty;
	int id;
}Cliente;

int cliente_init(Cliente * pArrays, int limite);
int cliente_alta(Cliente *arrayClientes,int limite);
int cliente_modificar (Cliente * pArrays, int limite);
int cliente_baja (Cliente * pArrays, int limite);
int cliente_imprimir (Cliente * pArrays , int limite);
int cliente_buscarIndicePorId (Cliente * pArrays, int limite,int idBuscar);
int cliente_buscarIndicePorIdRef (Cliente * pArrays, int limite,int idBuscar,int * pIndice);
int cliente_buscarLibreRef(Cliente pArrayCliente[],int limit, int *pindex);

#endif /* CLIENTE_H_ */
