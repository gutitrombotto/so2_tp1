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
	//float acumulado_precipitacion = 0.0;
	//int est_index[4031];
	int est_index[4031];
	int j = 0;
	float * ac_pr;
	ac_pr = (float *) malloc(31);

	for (int i = 0; i < MAX_ESTACIONES; ++i) //recorro estaciones
	{
		if (estaciones[i] == NULL)
		{
			break;

		}
		if (estaciones[i]->numero == numero_estacion)
		{
			est_index[j] = i;
			j++;
		}
		
	}
	est_index[j]=-1;
	//est_index[j] = 99999;
	//int cant_est_index = sizeof(est_index) / sizeof(int);
	//printf("%d\n", est_index[90]);
	printf("%d\n", est_index[j-1]);
	//printf("%s\n", estaciones[]->estacion);
	for (int i = 0; i < j; ++i)
	{	
		//printf("%.2f\n", estaciones[est_index[i]]->precipitacion);
		struct tm fecha_estacion = estaciones[i]->fecha;

		if (fecha_estacion.tm_mday == 1)
		{
			ac_pr[0] = ac_pr[0] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 2)
		{
			ac_pr[1] = ac_pr[1] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 3)
		{
			ac_pr[2] = ac_pr[2] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 4)
		{
			ac_pr[3] = ac_pr[3] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 5)
		{
			ac_pr[4] = ac_pr[4] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 6)
		{
			ac_pr[5] = ac_pr[5] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 7)
		{
			ac_pr[6] = ac_pr[6] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 8)
		{
			ac_pr[7] = ac_pr[7] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 9)
		{
			ac_pr[8] = ac_pr[8] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 10)
		{
			ac_pr[9] = ac_pr[9] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 11)
		{
			ac_pr[10] = ac_pr[10] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 12)
		{
			ac_pr[11] = ac_pr[11] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 13)
		{
			ac_pr[12] = ac_pr[12] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 14)
		{
			ac_pr[13] = ac_pr[13] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 15)
		{
			ac_pr[14] = ac_pr[14] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 16)
		{
			ac_pr[15] = ac_pr[15] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 17)
		{
			ac_pr[16] = ac_pr[16] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 18)
		{
			ac_pr[17] = ac_pr[17] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 19)
		{
			ac_pr[18] = ac_pr[18] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 20)
		{
			ac_pr[19] = ac_pr[19] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 21)
		{
			ac_pr[20] = ac_pr[20] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 22)
		{
			ac_pr[21] = ac_pr[21] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 23)
		{
			ac_pr[22] = ac_pr[22] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 24)
		{
			ac_pr[23] = ac_pr[23] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mday == 25)
		{
			ac_pr[24] = ac_pr[24] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 26)
		{
			ac_pr[25] = ac_pr[25] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 27)
		{
			ac_pr[26] = ac_pr[26] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 28)
		{
			ac_pr[27] = ac_pr[27] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 29)
		{
			ac_pr[28] = ac_pr[28] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 30)
		{
			ac_pr[29] = ac_pr[29] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mday == 31)
		{
			ac_pr[30] = ac_pr[30] + estaciones[est_index[i]]->precipitacion;
		} else {
			printf("ESTOY MAL\n");
			return 1;
		} 
		
	}
	printf("\t Acumulado diario de la estacion %s\n", estaciones[est_index[j-1]]->estacion);
	for (int i = 0; i < 31; ++i)
	{
		printf("Dia %d: ", i+1);
		printf("%.2f\n", ac_pr[i]);
		
	}
	return 0;
}

int mensual_precipitacion(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion)
{
	int est_index[4031];
	int j = 0;
	float * ac_pr;
	ac_pr = (float *) malloc(31);

	for (int i = 0; i < MAX_ESTACIONES; ++i) //recorro estaciones
	{
		if (estaciones[i] == NULL)
		{
			break;

		}
		if (estaciones[i]->numero == numero_estacion)
		{
			est_index[j] = i;
			j++;
		}
		
	}

	for (int i = 0; i < j; ++i)
	{	
		//printf("%.2f\n", estaciones[est_index[i]]->precipitacion);
		struct tm fecha_estacion = estaciones[i]->fecha;

		if (fecha_estacion.tm_mon == 0)
		{
			ac_pr[0] = ac_pr[0] + estaciones[est_index[i]]->precipitacion;
		} else 
		if (fecha_estacion.tm_mon == 1)
		{
			ac_pr[1] = ac_pr[1] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 2)
		{
			ac_pr[2] = ac_pr[2] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 3)
		{
			ac_pr[3] = ac_pr[3] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 4)
		{
			ac_pr[4] = ac_pr[4] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 5)
		{
			ac_pr[5] = ac_pr[5] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 6)
		{
			ac_pr[6] = ac_pr[6] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 7)
		{
			ac_pr[7] = ac_pr[7] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 8)
		{
			ac_pr[8] = ac_pr[8] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 9)
		{
			ac_pr[9] = ac_pr[9] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 10)
		{
			ac_pr[10] = ac_pr[10] + estaciones[est_index[i]]->precipitacion;
		}else 
		if (fecha_estacion.tm_mon == 11)
		{
			ac_pr[11] = ac_pr[11] + estaciones[est_index[i]]->precipitacion;
		}
		 else {
			printf("ESTOY MAL\n");
			return 1;
		} 
		
	}
	printf("\t Acumulado mensual de la estacion %s\n", estaciones[est_index[j-1]]->estacion);
	for (int i = 0; i < 12; ++i)
	{
		printf("Mes %d: ", i+1);
		printf("%.2f\n", ac_pr[i]);
		
	}
	return 0;

}

int valor_variable (struct Variables *variables, struct Estacion * estacion)
{
	float uno = -1.000000;
	variables->temperatura = variables->temperatura + estacion->temperatura;
	variables->humedad = variables->humedad + estacion->humedad;
	variables->punto_rocio = variables->punto_rocio + estacion->punto_rocio;
	variables->precipitacion = variables->precipitacion + estacion->precipitacion;
	variables->velocidad_viento = variables->velocidad_viento + estacion->velocidad_viento;
	variables->rafaga_max = variables->rafaga_max + estacion->rafaga_max;
	variables->radiacion_solar = variables->radiacion_solar + estacion->radiacion_solar;
	variables->temperatura_suelo1 = variables->temperatura_suelo1 + estacion->temperatura_suelo1;
	if (estacion->temperatura_suelo2 != uno)
	{
		variables->temperatura_suelo2 = variables->temperatura_suelo2 + estacion->temperatura_suelo2;
	} else {
		variables->temperatura_suelo2 = variables->temperatura_suelo2 + 0;
	}
	if (estacion->temperatura_suelo3 != uno)
	{
		variables->temperatura_suelo3 = variables->temperatura_suelo3 + estacion->temperatura_suelo3;
	} else {
		variables->temperatura_suelo3 = variables->temperatura_suelo3 + 0;
	}
	if (estacion->humedad_suelo1 != uno)
	{
		variables->humedad_suelo1 = variables->humedad_suelo1 + estacion->humedad_suelo1;
	
	} else{
		variables->humedad_suelo1 = variables->humedad_suelo1 + 0;
	}
	if (estacion->humedad_suelo2 != uno)
	{
		variables->humedad_suelo2 = variables->humedad_suelo2 + estacion->humedad_suelo2;
	} else {
		variables->humedad_suelo2 = variables->humedad_suelo2 + 0;
	}
	if (estacion->humedad_suelo3 != uno)
	{
		variables->humedad_suelo3 = variables->humedad_suelo3 + estacion->humedad_suelo3;
	} else {
		variables->humedad_suelo3 = variables->humedad_suelo3 + 0;
	}
	if (estacion->humedad_hoja != uno)
	{
		variables->humedad_hoja = variables->humedad_hoja + estacion->humedad_hoja;	
	} else {
		variables->humedad_hoja = variables->humedad_hoja + 0;
	}
	


	return 0;
}
void mostrar_variables (struct Variables *variables)
{
	printf("%.2f\n", variables->temperatura);
	printf("%.2f\n", variables->humedad);

	printf("%.2f\n", variables->punto_rocio);

	printf("%.2f\n", variables->precipitacion);

	printf("%.2f\n", variables->velocidad_viento);

	printf("%.2f\n", variables->rafaga_max);

	printf("%.2f\n", variables->radiacion_solar);

	printf("%.2f\n", variables->temperatura_suelo1);

	printf("%.2f\n", variables->temperatura_suelo2);

	printf("%.2f\n", variables->temperatura_suelo3);
	printf("%.2f\n", variables->humedad_suelo1);

	printf("%.2f\n", variables->humedad_suelo2);

	printf("%.2f\n", variables->humedad_suelo3);

	printf("%.2f\n", variables->humedad_hoja);

	return;
}

void set_promedio (struct Variables *variables, int contador_estaciones)
{
	variables->temperatura = variables->temperatura / contador_estaciones;
	variables->humedad = variables->humedad / contador_estaciones;;
	variables->punto_rocio = variables->punto_rocio / contador_estaciones;
	variables->precipitacion = variables->precipitacion / contador_estaciones;
	variables->velocidad_viento = variables->velocidad_viento / contador_estaciones;
	variables->rafaga_max = variables->rafaga_max / contador_estaciones;
	variables->radiacion_solar = variables->radiacion_solar / contador_estaciones;
	variables->temperatura_suelo1 = variables->temperatura_suelo1 / contador_estaciones;
	if (variables->temperatura_suelo2 != 0)
	{
		variables->temperatura_suelo2 = variables->temperatura_suelo2 / contador_estaciones;
	} else {
		variables->temperatura_suelo2 = 0;
	}
	if (variables->temperatura_suelo3 != 0)
	{
		variables->temperatura_suelo3 = variables->temperatura_suelo3 / contador_estaciones;
	}
	if (variables->humedad_suelo1 != 0)
	{
		variables->humedad_suelo1 = variables->humedad_suelo1 / contador_estaciones;
	
	} else{
		variables->humedad_suelo1 = 0;
	}
	if (variables->humedad_suelo2 != 0)
	{
		variables->humedad_suelo2 = variables->humedad_suelo2 / contador_estaciones;
	} else {
		variables->humedad_suelo2 = 0;
	}
	if (variables->humedad_suelo3 != 0)
	{
		variables->humedad_suelo3 = variables->humedad_suelo3 / contador_estaciones;
	} else {
		variables->humedad_suelo3 = 0;
	}
	if (variables->humedad_hoja != 0)
	{
		variables->humedad_hoja = variables->humedad_hoja / contador_estaciones;
	} else {
		variables->humedad_hoja = 0;
	}

	return;
	
}
int promedio_variables(struct Estacion *estaciones[MAX_ESTACIONES])
{
	int num_estaciones[] = {30135, 30057,30061, 30099, 30069};
	int cont_estaciones[NUM_ESTACIONES];
	//struct Variables *var_estaciones[NUM_ESTACIONES];
	
	struct Variables *estacion_1 = malloc(sizeof(struct Variables));
	struct Variables *estacion_2 = malloc(sizeof(struct Variables));
	struct Variables *estacion_3 = malloc(sizeof(struct Variables));
	struct Variables *estacion_4 = malloc(sizeof(struct Variables));
	struct Variables *estacion_5 = malloc(sizeof(struct Variables));
	
	int var_set = 0;

	for (int i = 0; i < MAX_ESTACIONES; ++i) //recorro estaciones
	{
		if (estaciones[i] == NULL)
		{
			break;

		}
		if (estaciones[i]->numero == num_estaciones[0])
		{
			var_set = valor_variable(estacion_1, estaciones[i]);
			cont_estaciones[0]++;
		} else if (estaciones[i]->numero == num_estaciones[1])
		{
			var_set = valor_variable(estacion_2, estaciones[i]);
			cont_estaciones[1]++;

		}else if (estaciones[i]->numero == num_estaciones[2])
		{
			var_set = valor_variable(estacion_3, estaciones[i]);
			cont_estaciones[2]++;

		} else if (estaciones[i]->numero == num_estaciones[3])
		{
			var_set = valor_variable(estacion_4, estaciones[i]);
			cont_estaciones[3]++;

		} else if (estaciones[i]->numero == num_estaciones[4])
		{
			var_set = valor_variable(estacion_5, estaciones[i]);
			cont_estaciones[4]++;

		} else{
			return 1;
		}

		if (var_set == -1)
		{
			return 1;
		}

	}
/*

	printf("%.2f\n", var_estaciones[0]->temperatura);

	for (int i = 0; i < NUM_ESTACIONES; ++i)
	{
		mostrar_variables(var_estaciones[i]);
	}
	*/
	set_promedio(estacion_1, cont_estaciones[0]);
	set_promedio(estacion_2, cont_estaciones[1]);
	set_promedio(estacion_3, cont_estaciones[2]);
	set_promedio(estacion_4, cont_estaciones[3]);
	set_promedio(estacion_5, cont_estaciones[4]);

	printf("Variables de la estacion Yacanto Norte - E01\n");
	mostrar_variables(estacion_1);
		printf("Variables de la estacion MagyaCba 60 cuadras\n");

	mostrar_variables(estacion_2);
	printf("Variables de la estacion MagyaCba La Cumbrecita\n");

	mostrar_variables(estacion_3);
	printf("Variables de la estacion Cerro Obero - Capilla del Monte\n");

	mostrar_variables(estacion_4);
	printf("Variables de la estacion Magyacba Oliva\n");

	mostrar_variables(estacion_5);


	return 0;
}

void validar_datos(struct Estacion *estacion)
{
	float uno = -1.000000;
	if (estacion->temperatura_suelo1 == uno)
	{
		estacion->temperatura_suelo1 = 0;
	}
	if (estacion->temperatura_suelo2 == uno)
	{
		estacion->temperatura_suelo2 = 0;
	}
	if (estacion->temperatura_suelo3 == uno)
	{
		estacion->temperatura_suelo3 = 0;
	}
	if (estacion->humedad_suelo1 == uno)
	{
		estacion->humedad_suelo1 = 0;
	}
	if (estacion->humedad_suelo2 == uno)
	{
		estacion->humedad_suelo2 = 0;
	}
	if (estacion->humedad_suelo3 == uno)
	{
		estacion->humedad_suelo3 = 0;
	}
	if (estacion->humedad_hoja == uno)
	{
		estacion->humedad_hoja = 0;
	}
	
	return;
}
int descargar(struct Estacion *estaciones[MAX_ESTACIONES], int numero_estacion)
{
	char * path = "datos.txt";
	FILE *infile; 
	int est_index[4031];
	infile = fopen(path, "w+");
	int j = 0; 
		for (int i = 0; i < MAX_ESTACIONES; ++i) //recorro estaciones
		{
			if (estaciones[i] == NULL)
			{
				break;

			}
			if (estaciones[i]->numero == numero_estacion)
			{
				est_index[j] = i;
				j++;
			}

		}


	if (!infile) { 
		printf("Couldn't open file %s for writing\n", path); 
		perror("Error while opening the file");
		exit(EXIT_FAILURE);
		
	} else {
		fprintf(infile, "\tVariable de la estacion %s \n \n", estaciones[est_index[j-1]]->estacion);
		fprintf(infile, "Temp\tHume\tPto.Ro\tPrecipt\tVel.Vie\tRaf.Vie\t  Pres\tRad.Sol\tTemp_S1\tTemp_S2\tTemp_S3\tHum_S1\tHum_S2\tHum_S3\tHum_Hoja\n");
		for (int i = 0; i < j; ++i)
		{
			validar_datos(estaciones[est_index[i]]);
			fprintf(infile, "%.2f \t %.2f \t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\n",
			estaciones[est_index[i]]->temperatura,
			estaciones[est_index[i]]->humedad,
			estaciones[est_index[i]]->punto_rocio,
			estaciones[est_index[i]]->precipitacion,
			estaciones[est_index[i]]->velocidad_viento,
			estaciones[est_index[i]]->rafaga_max,
			estaciones[est_index[i]]->presion,
			estaciones[est_index[i]]->radiacion_solar,
			estaciones[est_index[i]]->temperatura_suelo1,
			estaciones[est_index[i]]->temperatura_suelo2,
			estaciones[est_index[i]]->temperatura_suelo2,
			estaciones[est_index[i]]->humedad_suelo1,
			estaciones[est_index[i]]->humedad_suelo2,
			estaciones[est_index[i]]->humedad_suelo3,
			estaciones[est_index[i]]->humedad_hoja);

		}
	}
	return 0;
}

int test_commando(char * buffer)
{
	int ret;
	if(!strcmp(buffer, "listar"))
	{
		ret = 1;
	} else if(!strcmp(buffer, "descargar"))
	{
		ret = 2;

	} else if(!strcmp(buffer, "diario_precipitacion"))
	{
		ret = 3;

	} else if(!strcmp(buffer, "mensual_precipitacion"))
	{
		ret = 4;

	} else if(!strcmp(buffer, "promedio"))
	{
		ret = 5;

	} else if(!strcmp(buffer, "desconectar"))
	{
		ret = 6;

	} else {
		ret = -1;

	}

	return ret;

}

void execute_task(int c, char ** line_parsed, struct Estacion *estaciones[MAX_ESTACIONES])
{
	if (c == 1)
	{
	listar_estaciones(estaciones) 
	/*EJECUTAR Listar*/
		
	} else if (c == 2)
	{
	descargar(estaciones, line_parsed[1])
	/*EJECUTAR descargar*/

	}else if (c == 3) 
	{
	/*EJECUTAR diario_precipitacion*/
		precipitacion_diario(estaciones, line_parsed[1])

	}else if (c == 2)
	{ 
	/*EJECUTAR mensual_precipitacion*/
		mensual_precipitacion(estaciones, line_parsed[1])
	}
	else if (c == 2)
	{
	/*EJECUTAR promedio*/
		promedio_variables(estaciones)

	}
	else if (c == 2)
	{
	/*EJECUTAR desconectar*/

	}
}