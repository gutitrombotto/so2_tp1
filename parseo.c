#define _XOPEN_SOURCE
#define _GNU_SOURCE 


#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


#define MAX_BUFFER 2048
#define MAX_ESTACIONES 8
#define NUM_CAMPOS 19
/**
 *
 * Struct Estacion
 *
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

char * test_dato(char * token){
	if(!strcmp(token, "--")) return "-1";
	else return token;
}

struct tm char_to_fecha (const char *input)
{
	struct tm tm;
	char buf[255];

	memset(&tm, 0, sizeof(struct tm));
	strptime(input, "%d/%m/%Y %H:%M", &tm);
	strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M", &tm);

	return tm;
}


void set_datos_estaciones(char * token,int contador, struct Estacion * est)
{
	switch(contador){
		case 0:
		est->numero = atoi(token);
		break;
		case 1:
		est->estacion = strdup(token); 
		break;
		case 2:
		est->id_localidad = atoi(token); 
		break;
		case 3:
		est->fecha = char_to_fecha(token); 
		break;
		case 4:
		est->temperatura = atof(token); 	
		break;
		case 5:
		est->humedad = atof(token); 
		break;
		case 6:
		est-> punto_rocio =	atof(token);
		break;
		case 7:
		est->precipitacion = atof(token);
		break;
		case 8: 
		est-> velocidad_viento = atof(token);
		break;
		case 9:
		est-> direccion_viento = strdup(token); 
		break;
		case 10:
		est-> rafaga_max = atof(token);
		break;
		case 11: 
		est-> presion =	atof(token);
		break;
		case 12: 
		est->radiacion_solar = atof(token);
		break;
		case 13:
		est->temperatura_suelo1 = atof(token);
		break;
		case 14:
		token = test_dato(token);
		est->temperatura_suelo2 = atof(token); 
		break;
		case 15:
		token = test_dato(token); 
		est->temperatura_suelo3= atof(token); 
		break;
		case 16:
		token = test_dato(token);
		est-> humedad_suelo1 =	atof(token); 
		break;
		case 17:
		token = test_dato(token);
		est-> humedad_suelo2 = atof(token); 
		break;
		case 18:
		token = test_dato(token);
		est->humedad_suelo3 = atof(token); 
		break;
		case 19: 
		token = test_dato(token);
		est->humedad_hoja =atof(token); 
		break;
		default : 
		return;
	}

	return;
}
struct Estacion *parse_data(char * line_buffer, const char *s){
	char *token;
	token = strtok(line_buffer, s);
	int contador = 0;
	struct Estacion *est= malloc(sizeof(struct Estacion));
	

	memset(est, 0, sizeof(struct Estacion));
	//memset(est->fecha, '\0', sizeof(token
	while( token != NULL ) 
	{
				//printf( " %s\n", token );
				//printf("%d\n", contador);
		set_datos_estaciones(token,contador,est);
		contador ++;
		token = strtok(NULL, s);
	}

	return est;
}

int test_datos(struct Estacion *estacion){
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

int main(int argc, char **argv)
{
	struct Estacion *estaciones[MAX_ESTACIONES];
	const char s[2] = ",";
	char *inname = "datos_meteorologicos_modif.csv";
	FILE *infile; 
  	char line_buffer[BUFSIZ]; /* BUFSIZ is defined if you include stdio->h */
	char line_number;
	//	struct tm tm;
	//char * path;
	//int error;
	//struct Estacion *est;
	//path = "datos->txt";
	//char buf_fecha[255];
	int arr_cont;
	arr_cont = 0;

	
	infile = fopen(inname, "r"); 
	if (!infile) { 
		printf("Couldn't open file %s for reading\n", inname); 
		perror("Error while opening the file");
		exit(EXIT_FAILURE);
		
	}
	printf("Opened file %s for reading\n", inname); 
	line_number = 0; 
	while (fgets(line_buffer, sizeof(line_buffer), infile)!=NULL) 
	{
		
		if(line_number > 2){
			printf("%s\n", line_buffer);
			
			estaciones[arr_cont] = parse_data(line_buffer,s);
			arr_cont ++;
		}


	    ++line_number; /* note that the newline is in the buffer */
	}

	printf("%.2f\n", estaciones[3]->temperatura);

	int err = listar_estaciones(estaciones);

	exit(0);
	

}
