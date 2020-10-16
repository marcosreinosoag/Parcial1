/*
 * informes.h
 *
 *  Created on: 14 oct. 2020
 *      Author: marco
 */

#ifndef INFORMES_H_
#define INFORMES_H_


#define LONG_NOMBRE 50
#define TRUE 1
#define FALSE 0
#define QTY_CARACTERES 60
#define QTY_CLIENTES 100
#define QTY_AVISOS 1000

int menu_Consultas(Aviso * pArrays, int limite, Cliente * pArrayCliente , int limit);

int aviso_contarClientesConMasAvisos(Aviso *pArrayAviso,int limiteAviso,Cliente* pArrayCliente,int limiteCliente);
int informes_contadorAvisosClientes(Aviso *pArrayAviso,int limiteAvisos,int id,int *pContador);



int aviso_contarAvisosPausadosRef(Aviso *pArrayAviso,int limiteAviso,int *contadorAvisosPausados);
int aviso_contarRubrosConMasAvisos(Aviso *pArrayAviso,int limiteAviso);
int informes_contadorRubroAvisos(Aviso *pArrayAviso,int limiteAvisos,int rubro,int *pContador);



int informes_contadorClienteAvisosPausados(Aviso *pArrayAviso,int limiteAviso,int id,int *pContador);
int aviso_clienteConMasAvisosPausados(Cliente *pArrayCliente,int limitCliente,Aviso *pArrayAviso,int limiteAviso);

#endif /* INFORMES_H_ */
