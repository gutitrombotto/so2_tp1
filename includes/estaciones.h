#ifndef	ESTACIONES_H
#define	ESTACIONES_H

#define _XOPEN_SOURCE
#define _GNU_SOURCE 

#include <time.h>

/*! \def MAX_ESTACIONES
    \brief Cantidad de estaciones en el documento
*/
#define MAX_ESTACIONES 8
/*! \def NUM_CAMPOS
    \brief Cantidad de Variables de las estaciones
*/
#define NUM_CAMPOS 19

/*! \struct Estacion
	\brief Guarda los valores de las estaciones
	\param numero directorio actual
	\param estacion directorio a home
	\param id_localidad directorio a root
	\param temperatura el nombre de la maquina
	\param humedad nombre de usuario
	\param punto_rocio sesion
*/
struct Estacion {
	int  numero;
	char  *estacion;
	int  id_localidad;
	struct tm fecha;
	float  temperatura;
	float  humedad;
	float  punto_rocio;
	float  precipitacion;
	float  velocidad_viento;
	char * direccion_viento;
	float  rafaga_max;
	float  presion;
	float  radiacion_solar;
	float  temperatura_suelo1;
	float  temperatura_suelo2; // No tiene datos
	float temperatura_suelo3; // No tiene datos
	float  humedad_suelo1; // No tienen datos de aca hasta abajos
	float  humedad_suelo2;
	float  humedad_suelo3;
	float  humedad_hoja;
};

#endif 