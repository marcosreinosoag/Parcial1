/*
 * utn.h
 *
 *  Created on: 10 oct. 2020
 *      Author: marco
 */

#ifndef UTN_H_
#define UTN_H_
#define LIMITE_BUFFER_STRING 4096
#define LIMITE_CONFIRMACION 3
#define TRUE 1
#define FALSE 0

int utn_getEntero(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int esUnNombreValido(char* cadena,int limite);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int esUnCuitValido(char* cadena,int limite);
int utn_getCuit(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int validarConfirmacion(char* cadena,int limite);
int utn_getConfirmacion(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);



#endif /* UTN_H_ */
