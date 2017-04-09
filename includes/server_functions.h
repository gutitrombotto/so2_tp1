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

#endif