
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <stddef.h> /* offsetof */


#define MAX_BUFFER 2048
#define MAX_ESTACIONES 7
#define NUM_CAMPOS 19
struct Estacion {
	int  numero;
	char  *estacion;
	int  id_localidad;
	char  *fecha;
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


char * test_dato(char * token){
	if(!strcmp(token, "--")) return "-1";
	else return token;
}	

int main(int argc, char **argv)
{
	//struct Estacion estaciones[MAX_ESTACIONES];
	struct Estacion *est;
	const char s[2] = ",";
	char *inname = "datos_meteorologicos_modif.csv";
	FILE *infile; 
  	char line_buffer[BUFSIZ]; /* BUFSIZ is defined if you include stdio.h */
	char line_number;
	char *token;
	int contador;
	contador=0;
	
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
			//estaciones[line_number] = set_datos(line_buffer, s);
			/* get the first token */
			token = strtok(line_buffer, s);

   /* walk through other tokens */
			while( token != NULL ) 
			{
				printf( " %s\n", token );
				printf("%d\n", contador);

				contador ++;
				token = strtok(NULL, s);
			}		
		}

	    ++line_number; /* note that the newline is in the buffer */
	}
	exit(0);

}