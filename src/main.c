#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <stddef.h> /* offsetof */
#include <time.h>



#define MAX_BUFFER 2048
#define MAX_ESTACIONES 8
#define NUM_CAMPOS 19

struct Estacion {
	int  numero;
	char  *estacion;
	int  id_localidad;
	struct tm  fecha;
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
	char *  temperatura_suelo2; // No tiene datos
	char *  temperatura_suelo3; // No tiene datos
	char *  humedad_suelo1; // No tienen datos de aca hasta abajos
	char *  humedad_suelo2;
	char *  humedad_suelo3;
	char *  humedad_hoja;
};
struct tm parse_date (const char *input)
{
	struct tm tm;

	memset(&tm, 0, sizeof(struct tm));
	if (strptime(input, "%d/%m/%Y %H:%M", &tm) == NULL){
		printf("ERROR DE PARSEo \n");
	}

	return tm;
}

char * test_dato(char * token){
	if(!strcmp(token, "--")) return "-1";
	else return token;
}	

struct Estacion *set_datos(char * buffer, const char *s)
{
	char *saveptr;
	int contador=0;
	struct Estacion *est;
	//memset(est,0,sizeof(struct Estacion));
	char * token;
	token = strtok_r(buffer, s,&saveptr);
   /* walk through other tokens */
	while( token != NULL ) 
	{
		printf("%d\n", contador);
				printf("%s\n", token);
		switch(contador){
			case 0:
			est->numero = atoi(token);
			break;
			case 1:
			est->estacion=strdup(token);
			break;
			case 2:
			est->id_localidad = atoi(token);
			break;
			case 3:
			est->fecha=parse_date(token);
			printf("%s\n", token);
			break;
			case 4:
			est->temperatura = atof(token);
			printf("%f\n", est->temperatura);
			break;
			case 5:
			est->humedad = atof(token);
			break;
			case 6:
			est->punto_rocio = atof(token);
			break;
			case 7:
			est->precipitacion = atof(token);
			break;
			case 8:
			est->velocidad_viento = atof(token);
			break;
			case 9:
			est->direccion_viento=strdup(token);
			break;
			case 10:
			est->rafaga_max = atof(token);
			break;
			case 11:
			est->presion = atof(token);
			break;
			case 12:
			token = test_dato(token);
			est->radiacion_solar = atof(token);
			break;
			case 13:
			token = test_dato(token);
			est->temperatura_suelo1 = atof(token);
			break;
			case 14:
			est->temperatura_suelo2 = "No hay datos";
			break;
			case 15:
			est->temperatura_suelo3 = "No hay datos";
			break;
			case 16:
			est->humedad_suelo1 = "No hay datos";
			break;
			case 17:
			est->humedad_suelo2 = "No hay datos";
			break;
			case 18:
			est->humedad_suelo3 = "No hay datos";
			break;
			case 19:
			est->humedad_hoja = "No hay datos";
			break;
			default:
			break;
		}

		contador++;
		token = strtok_r(NULL, s, &saveptr);
	}

	return est;
	
}
int main(int argc, char **argv)
{
	struct Estacion *estaciones[MAX_ESTACIONES];
	const char s[2] = ",";
	char *inname = "datos_meteorologicos_modif.csv";
	FILE *infile; 
  	char line_buffer[BUFSIZ]; /* BUFSIZ is defined if you include stdio.h */
	char line_number;
	char * path;
	int error;
	int arry_index;
	char str_fecha[255];
	arry_index = 0;
	path = "datos.txt"; 
	
	infile = fopen(inname, "r"); 
	if (!infile) { 
		printf("Couldn't open file %s for reading.\n", inname); 
		perror("Error while opening the file.");
		exit(EXIT_FAILURE);
		
	}
	printf("Opened file %s for reading.\n", inname); 
	line_number = 0; 
	while (fgets(line_buffer, sizeof(line_buffer), infile)!=NULL) 
	{
		
		if(line_number > 2){
			printf("%s\n", line_buffer);
			estaciones[arry_index] = set_datos(line_buffer, s);
			arry_index++;
		}
		
		++line_number; 
	}
	for (int i = 0; i < MAX_ESTACIONES; ++i)
	{
		strftime(str_fecha, sizeof(str_fecha), "%d/%m/%Y %H:%M", &estaciones[i]->fecha);
		printf("Numero:  %d\n", estaciones[i]->numero);
		printf("estacion:  %s\n", estaciones[i]->estacion);
		printf("id_localidad:  %d\n", estaciones[i]->id_localidad);
		printf("fecha:  %s\n", str_fecha);
		printf("temperatura:  %f\n", estaciones[i]->temperatura);
		printf("humedad:  %f\n", estaciones[i]->humedad);
		printf("punto_rocio:  %f\n", estaciones[i]->punto_rocio);
		printf("precipitacion:  %f\n", estaciones[i]->precipitacion);
		printf("velocidad_viento:  %f\n", estaciones[i]->velocidad_viento);
		printf("direccion_viento:  %s\n", estaciones[i]->direccion_viento);
		printf("rafaga_max:  %f\n", estaciones[i]->rafaga_max);
		printf("presion:  %f\n", estaciones[i]->presion);
		printf("radiacion_solar:  %f\n", estaciones[i]->radiacion_solar);
		printf("temperatura_suelo1:  %f\n", estaciones[i]->temperatura_suelo1);
		printf("temperatura_suelo2:  %s\n", estaciones[i]->temperatura_suelo2);
		printf("temperatura_suelo3:  %s\n", estaciones[i]->temperatura_suelo3);
		printf("humedad_suelo1:  %s\n", estaciones[i]->humedad_suelo1);
		printf("humedad_suelo2:  %s\n", estaciones[i]->humedad_suelo2);
		printf("humedad_suelo3:  %s\n", estaciones[i]->humedad_suelo3);
		printf("humedad_hoja:  %s\n", estaciones[i]->humedad_hoja);	
		//str_fecha = buffer_fecha(estaciones[i]->fecha, str_fecha);
		
	}

	exit(0);
	
}
