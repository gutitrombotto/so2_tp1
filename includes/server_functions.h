#ifndef	SERVER_FUNCTIONS_H
#define	SERVER_FUNCTIONS_H

#include "../includes/estaciones.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int test_datos(struct Estacion *estacion);



int listar_estaciones(struct Estacion *estaciones[MAX_ESTACIONES]);





int precipitacion_diario(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion);

int valor_variable (struct Variables *variables, struct Estacion * estacion);

int promedio_variables(struct Estacion *estaciones[MAX_ESTACIONES]);

int mensual_precipitacion(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion);

int descargar(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion, char * path);

void validar_datos(struct Estacion *estacion);

int test_commando(char * buffer);
#endif