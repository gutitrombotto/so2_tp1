for (int i = 0; i < MAX_ESTACIONES; i++)
	{
	strftime(str_fecha, sizeof(str_fecha), "%d/%m/%Y %H:%M", &estaciones[i].fecha);
	printf("Numero:  %d\n", estaciones[i].numero);
	printf("estacion:  %s\n", estaciones[i].estacion);
	printf("id_localidad:  %d\n", estaciones[i].id_localidad);
	printf("fecha:  %s\n", str_fecha);
	printf("temperatura:  %f\n", estaciones[i].temperatura);
	printf("humedad:  %f\n", estaciones[i].humedad);
	printf("punto_rocio:  %f\n", estaciones[i].punto_rocio);
	printf("precipitacion:  %.2f\n", estaciones[i].precipitacion);
	printf("velocidad_viento:  %f\n", estaciones[i].velocidad_viento);
	printf("direccion_viento:  %s\n", estaciones[i].direccion_viento);
	printf("rafaga_max:  %.2f\n", estaciones[i].rafaga_max);
	printf("presion:  %f\n", estaciones[i].presion);
	printf("radiacion_solar:  %.2f\n", estaciones[i].radiacion_solar);
	printf("temperatura_suelo1:  %.2f\n", estaciones[i].temperatura_suelo1);
	printf("temperatura_suelo2:  %.2f\n", estaciones[i].temperatura_suelo2);
	printf("temperatura_suelo3:  %.2f\n", estaciones[i].temperatura_suelo3);
	printf("humedad_suelo1:  %.2f\n", estaciones[i].humedad_suelo1);
	printf("humedad_suelo2:  %.2f\n", estaciones[i].humedad_suelo2);
	printf("humedad_suelo3:  %.2f\n", estaciones[i].humedad_suelo3);
	printf("humedad_hoja:  %.2f\n", estaciones[i].humedad_hoja);	

	}
