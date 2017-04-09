#include "../includes/estaciones.h"
#include "../includes/server_functions.h"

int test_datos(struct Estacion *estacion)
{
	float uno = -1.000000;

	if(estacion->temperatura!=uno){
		printf("Temperatura : SI \n");
	} else {
		printf("Temperatura : NO\n");
	}
	if(estacion->humedad!=uno){
		printf("humedad: SI\n");
	} else {
		printf("humedad: NO\n");
	}
	if(estacion->punto_rocio!=uno){
		printf("punto_rocio: SI\n");
	} else {
		printf("punto_rocio: NO\n");
	}
	if(estacion->precipitacion!=uno){
		printf("precipitacion: SI\n");
	} else {
		printf("precipitacion: NO\n");
	}
	if(estacion->velocidad_viento!=uno){
		printf("velocidad_viento: SI\n");
	} else {
		printf("velocidad_viento: NO\n");
	}
	if(estacion->rafaga_max!=uno){
		printf("rafaga_max: SI\n");
	} else {
		printf("rafaga_max: NO\n");
	}
	if(estacion->presion!=uno){
		printf("presion: SI\n");
	} else {
		printf("presion: NO\n");
	}
	if(estacion->radiacion_solar!=uno){
		printf("radiacion_solar: SI\n");
	} else {
		printf("radiacion_solar: NO\n");
	}
	if(estacion->temperatura_suelo3!=uno || estacion->temperatura_suelo1 != uno || estacion->temperatura_suelo2 != uno){
		printf("Temperatura suelo: SI\n");
	} else {
		printf("Temperatura suelo: NO\n");
	}
	if(estacion->humedad_suelo1!=uno || estacion->humedad_suelo2!=uno || estacion->humedad_suelo3!=uno){
		printf("humedad_suelo: SI\n");
	} else {
		printf("humedad_suelo: NO\n");
	}
	if(estacion->humedad_hoja!=uno){
		printf("humedad_hoja: SI\n");
	} else {
		printf("humedad_hoja: NO\n");
	}

	return 0;
}

int listar_estaciones(struct Estacion *estaciones[MAX_ESTACIONES])
{
	for (int i = 0; i < MAX_ESTACIONES; ++i)
	{
		int numero_estacion = estaciones[i]->numero;

		if (i==MAX_ESTACIONES-1)
		{
			printf("\t Variables de la estacion %s\n", estaciones[i]->estacion);
			int test_error = test_datos(estaciones[i]);

			if(test_error){
				printf("No se pudo examinar estaciones\n");
			}
			break;
		}

		if(numero_estacion!=estaciones[i+1]->numero){

			printf("\t Variables de la estacion %s\n", estaciones[i]->estacion);
			int test_error = test_datos(estaciones[i]);

			if(test_error){
				printf("No se pudo examinar estaciones\n");
			}
			
		}
	}
	return 0;
}

int precipitacion_diario(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion)
{
	float acumulado_precipitacion = 0.0;
	for (int i = 0; i < MAX_ESTACIONES; ++i) //recorro estaciones
	{
		if (estaciones[i]->numero != numero_estacion)
		{
			
		}
		else{
			for (int j = 0; j < 31; ++j) // recorro dia a dia
			{
				printf("\t Acumulado_precipitacion de la estacion %s \n", estaciones[i]->estacion);
				struct tm fecha_estacion = estaciones[i]->fecha;
				if (fecha_estacion.tm_mday == j)
				{
					acumulado_precipitacion = acumulado_precipitacion + estaciones[i]->precipitacion;
				} else {
					printf("%.2f\n", acumulado_precipitacion);
					acumulado_precipitacion = 0.0;
					acumulado_precipitacion = acumulado_precipitacion + estaciones[i]->precipitacion;

				}
			}
		}
	}
	return 0;
}
