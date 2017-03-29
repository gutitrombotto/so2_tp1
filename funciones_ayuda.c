int cant_estaciones = sizeof(estaciones) / sizeof(estaciones[0]);
	for (int i = 0; i < cant_estaciones; i++)
	{
	printf("Numero:  %d\n", estaciones[i].numero);
	printf("estacion:  %s\n", estaciones[i].estacion);
	printf("id_localidad:  %d\n", estaciones[i].id_localidad);
	printf("fecha:  %s\n", estaciones[i].fecha);
	printf("temperatura:  %f\n", estaciones[i].temperatura);
	printf("humedad:  %f\n", estaciones[i].humedad);
	printf("punto_rocio:  %f\n", estaciones[i].punto_rocio);
	printf("precipitacion:  %f\n", estaciones[i].precipitacion);
	printf("velocidad_viento:  %f\n", estaciones[i].velocidad_viento);
	printf("direccion_viento:  %s\n", estaciones[i].direccion_viento);
	printf("rafaga_max:  %f\n", estaciones[i].rafaga_max);
	printf("presion:  %f\n", estaciones[i].presion);
	printf("radiacion_solar:  %f\n", estaciones[i].radiacion_solar);
	printf("temperatura_suelo1:  %f\n", estaciones[i].temperatura_suelo1);
	printf("temperatura_suelo2:  %s\n", estaciones[i].temperatura_suelo2);
	printf("temperatura_suelo3:  %s\n", estaciones[i].temperatura_suelo3);
	printf("humedad_suelo1:  %s\n", estaciones[i].humedad_suelo1);
	printf("humedad_suelo2:  %s\n", estaciones[i].humedad_suelo2);
	printf("humedad_suelo3:  %s\n", estaciones[i].humedad_suelo3);
	printf("humedad_hoja:  %s\n", estaciones[i].humedad_hoja);	

	}