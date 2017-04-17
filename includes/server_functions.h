/*! \file server_functions.h
    \brief Funciones del servidor
*/
#ifndef	SERVER_FUNCTIONS_H
#define	SERVER_FUNCTIONS_H

#include "../includes/estaciones.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*!	\fn int test_datos(struct Estacion *estacion)
	\brief Verifica si hay datos en cada variable de la estacion
	\param *estacion estacion a la cual se validan los datos
*/ 
int test_datos(struct Estacion *estacion);


/*!	\fn int listar_estaciones(struct Estacion *estaciones[MAX_ESTACIONES])
	\brief Muestra en pantalla las estaciones y si poseen datos en sus variables
	\param *estaciones arreglo que contiene los datos de las estaciones
*/   
int listar_estaciones(struct Estacion *estaciones[MAX_ESTACIONES]);


/*!	\fn int precipitacion_diario(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion)
	\brief Muestra el acumulado por dia de la estacion pasada como parametro
	\param *estaciones arreglo que contiene los datos de las estaciones
	\param numero_estacion
*/  
int precipitacion_diario(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion);
/*!	\fn int mensual_precipitacion(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion)

	\brief Muestra el acumulado por mes de la estacion pasada como parametro
	\param *estaciones arreglo que contiene los datos de las estaciones
	\param numero_estacion
*/ 
int mensual_precipitacion(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion);
/*!	\fn int valor_variable (struct Variables *variables, struct Estacion * estacion)

	\brief Acumula el valor des las variables de la estacion
	\param *estacion datos de una estacion
	\param variables variables de la estacion pasada como paramtro.
*/ 
int valor_variable (struct Variables *variables, struct Estacion * estacion);
/*!	\fn void mostrar_variables (struct Variables *variables)

	\brief Muestra los valores de la estructura variables de una estacion
	\param variables variables de una estacion
*/ 
void mostrar_variables (struct Variables *variables);
/*!	\fn void validar_datos(struct Estacion *estacion)

	\brief Verifica si las variables de la estacion tienen datos
	\param *estacion datos de la estacion a verificar
*/
void validar_datos(struct Estacion *estacion);

/*!	\fn int promedio_variables(struct Estacion *estaciones[MAX_ESTACIONES])

	\brief Acumula el valor des las variables de la estacion
	\param *estacion datos de una estacion
	\param variables variables de la estacion pasada como paramtro.
*/
int promedio_variables(struct Estacion *estaciones[MAX_ESTACIONES]);

/*!	\fn void set_promedio (struct Variables *variables, int contador_estaciones)
	\brief Establece el promedio de cada variables segun el contador de estaciones
	\param *variables estructura con las variables de una estacion
	\param contador_estaciones indice de la estacion a la cual pertenece las varia
*/ 
void set_promedio (struct Variables *variables, int contador_estaciones);

/*!	\fn int descargar(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion)
	\brief Crea un archivo con la estacio y sus valores
	\param *estaciones estructura con las variables de una estacion
	\param numero_estacion indice de la estacion de la cual sus datos se guardaran en archivo
*/ 
int descargar(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion);
/*!	\fn int test_commando(char * buffer)
	\brief Verifica el valor pasado como parametro y devuelve un entero segun la accion a realizar
	\param *buffer linea a validar
*/ 
int test_commando(char * buffer);
/*!	\fn execute_task(int c, char ** line_parsed, struct Estacion *estaciones[MAX_ESTACIONES])
	\brief Ejecuta una funcion del servidor según el numero de tarea
	\param c numero de tarea a realizar
	\param **line_parsed parametros para las tareas a realizar
	\param *estaciones datos de las estaciones
*/ 
int execute_task(int c, char ** line_parsed, struct Estacion *estaciones[MAX_ESTACIONES]);
#endif