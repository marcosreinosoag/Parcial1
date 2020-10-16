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
	int idCliente;
}Cliente;

int cliente_init(Cliente * pArrays, int limite);
int cliente_alta(Cliente *arrayClientes,int limite);
int cliente_modificar (Cliente * pArrays, int limite);
int cliente_imprimir (Cliente * pArrays , int limite);
int cliente_buscarIndicePorId (Cliente * pArrays, int limite,int idBuscar);
int cliente_buscarIndicePorIdRef (Cliente * pArrays, int limite,int idBuscar,int * pIndice);
int cliente_buscarLibreRef(Cliente pArrayCliente[],int limit, int *pindex);
int cliente_altaForzada(Cliente * pArrayCliente,int limiteCliente,char * nombre,char * apellido,char * cuit);
int cliente_imprimirClientePorID (Cliente * pArrayCliente , int limitCliente, int id,char*mensaje);

#endif /* CLIENTE_H_ */
