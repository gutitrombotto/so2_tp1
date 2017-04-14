#ifndef	ESTACIONES_H
#define	ESTACIONES_H

#define _XOPEN_SOURCE
#define _GNU_SOURCE 

#include <time.h>

/*! \def NUM_ESTACIONES
    \brief Cantidad de estaciones
*/
#define NUM_ESTACIONES 5
/*! \def MAX_ESTACIONES
    \brief Cantidad de datos de estaciones en el documento
*/
#define MAX_ESTACIONES 18303
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
	\param  precipitacion;
	\param  velocidad_viento;
	\param direccion_viento;
	\param  rafaga_max;
	\param  presion;
	\param  radiacion_solar;
	\param  temperatura_suelo1;
	\param  temperatura_suelo2; // No tiene datos
	\param temperatura_suelo3; // No tiene datos
	\param  humedad_suelo1; // No tienen datos de aca hasta abajos
	\param  humedad_suelo2;
	\param  humedad_suelo3;
	\param  humedad_hoja;
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

/*! \struct Variables
	\brief Guarda los valores de la variables de una estacion
	\param temperatura 
	\param humedad 
	\param punto_rocio 
	\param  temperatura
	\param  humedad
	\param  punto_rocio
	\param  precipitacion
	\param  velocidad_viento
	\param  rafaga_max
	\param  presion
	\param  radiacion_solar
	\param  temperatura_suelo1
	\param  temperatura_suelo2 
	\param temperatura_suelo3 
	\param  humedad_suelo1 
	\param  humedad_suelo2
	\param  humedad_suelo3
	float  humedad_hoja
*/
struct Variables {
	float  temperatura;
	float  humedad;
	float  punto_rocio;
	float  precipitacion;
	float  velocidad_viento;
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