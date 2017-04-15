/*! \file parse_functions.h
    \brief Funciones para el parseo de datos
*/
#ifndef	PARSE_FUNCTIONS_H
#define	PARSE_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*! \def BUFSIZE
    \brief Tamaño de la linea de lectura de un archivo
*/
#define BUFSIZE 256

/*! \def MAX_BUFFER
    \brief Cantidad de estaciones en el documento
*/
#define MAX_BUFFER 2048

/*!	\fn char * test_dato(char * token)
	\brief Valida si existe dado util
	\param token dato a validar
*/
char * test_dato(char * token);

/*!	\fn struct tm char_to_fecha (const char *input)
	\brief Convierte char del documento a formato fecha
	\param input dato a convertir
	\return tm estructura Fecha
*/ 
struct tm char_to_fecha (const char *input);


/*!	\fn void set_datos_estaciones(char * token,int contador, struct Estacion * est)
	\brief Setea la variable de la estacion según el numero de campo en que se encuentra
	\param token dato a validar y setear
	\param contador numero de campo
	\param est Estructura de estacion a la cual insertar dato
*/   
void set_datos_estaciones(char * token,int contador, struct Estacion * est);

/*!	\fn struct Estacion *parse_data(char * line_buffer, const char *s)
	\brief Parsea cada linea del documento y guarda los valores en una estructura Estacion
	\param line_buffer linea del documento
	\param s delimitador por el cual parsear
	\return Estacion puntero a estacion con los datos del archivo
*/   
struct Estacion *parse_data(char * line_buffer, const char *s);

/*!	\fn void load_file(char *inname, struct Estacion *estaciones[MAX_ESTACIONES])
	\brief Cargar en un arreglo los datos del documento
	\param inname nombre del docuemnto
	\param estaciones arreglo de punteros a estaciones
*/ 
void load_file(char *inname, struct Estacion *estaciones[MAX_ESTACIONES]);
#endif