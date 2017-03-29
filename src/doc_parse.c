#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <stddef.h> /* offsetof */


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
} estacion; 

char * test_dato(char * token){
	if(!strcmp(token, "--")) return "-1";
	else return token;
}	

struct Estacion set_datos (char * buffer, const char *s)
{
	char *saveptr;
	int contador=0;
	struct Estacion est;
	char * token;
	token = strtok_r(buffer, s,&saveptr);
   /* walk through other tokens */
	while( token != NULL ) 
	{
		//printf( " %s\n", token );
		if (contador==0)
		{
			est.numero = atoi(token);
		} else if (contador==1)
		{
			est.estacion=strdup(token);
			//memset(est.estacion, '\0', sizeof(token));
			//strcpy(est.estacion, token);
			//est.estacion = token;
			//strcpy(est.estacion, token);
			
		} else if (contador==2)
		{
			est.id_localidad = atoi(token);
			
		} else if (contador==3)
		{
			est.fecha=strdup(token);
			//memset(est.fecha, '\0', sizeof(token));
			//strcpy(est.fecha, token);
			//est.fecha = token;
			//strcpy(est.fecha, token);
			
		} else if (contador==4)
		{
			est.temperatura = atof(token);
			//strcpy(estacion.temperatura, atof(token));
			
		} else if (contador==5)
		{
			est.humedad = atof(token);
			//strcpy(estacion.humedad, atof(token));
			
		} else if (contador==6)
		{

			est.punto_rocio = atof(token);
			//strcpy(estacion.punto_rocio, atof(token));
			
		} else if (contador==7)
		{

			est.precipitacion = atof(token);
			//strcpy(estacion.punto_rocio, atof(token));
			
		} else if (contador==8)
		{

			est.velocidad_viento = atof(token);
			//strcpy(estacion.punto_rocio, atof(token));
			
		}else if (contador==9)
		{
			est.direccion_viento=strdup(token);
			//memset(est.direccion_viento, '\0', sizeof(token));
			//strcpy(est.direccion_viento, token);
			//est.direccion_viento = token;
			//strcpy(estacion.direccion_viento, token);
			
		} else if (contador==10)
		{
			est.rafaga_max = atof(token);
			//strcpy(estacion.punto_rocio, atof(token));
			
		} else if (contador==11)
		{

			est.presion = atof(token);
			//strcpy(estacion.punto_rocio, atof(token));
			
		} else if (contador==12)
		{
			token = test_dato(token);
			est.radiacion_solar = atof(token);
			//strcpy(estacion.punto_rocio, atof(token));
			
		} else if (contador==13)
		{
			token = test_dato(token);
			est.temperatura_suelo1 = atof(token);
			//strcpy(estacion.punto_rocio, atof(token));
			
		}else if (contador==14)
		{
			
			est.temperatura_suelo2 = "No hay datos";
			//strcpy(estacion.punto_rocio, atof(token));
			
		}
		else if (contador==15)
		{
			
			est.temperatura_suelo3 = "No hay datos";
			//strcpy(estacion.punto_rocio, atof(token));
			
		}
		else if (contador==16)
		{
			
			est.humedad_suelo1 = "No hay datos";
			//strcpy(estacion.punto_rocio, atof(token));
			
		}
		else if (contador==17)
		{
			
			est.humedad_suelo2 = "No hay datos";
			//strcpy(estacion.punto_rocio, atof(token));
			
		}
		else if (contador==18)
		{
			
			est.humedad_suelo3 = "No hay datos";
			//strcpy(estacion.punto_rocio, atof(token));
			
		}
		else if (contador==19)
		{
			
			est.humedad_hoja = "No hay datos";
			//strcpy(estacion.punto_rocio, atof(token));
			
		}
		else{
			break;
		}

		contador++;
		//printf("%d\n", contador);
		token = strtok_r(NULL, s, &saveptr);
	}

	return est;
	
}


int main(int argc, char **argv)
{
	struct Estacion estaciones[MAX_ESTACIONES];
	const char s[2] = ",";
	char *inname = "datos_meteorologicos_to_parse _test.csv";
	FILE *infile; 
  	char line_buffer[BUFSIZ]; /* BUFSIZ is defined if you include stdio.h */
	char line_number; 

	infile = fopen(inname, "r"); 
	if (!infile) { 
		printf("Couldn't open file %s for reading.\n", inname); 
		return 0;
	}
	printf("Opened file %s for reading.\n", inname); 
	line_number = 0; 
	while (fgets(line_buffer, sizeof(line_buffer), infile)!=NULL) 
	{
		//estaciones[line_number] = set_datos(line_buffer, s); 
		//Estacion set_datos (char * buffer, const char *s)
		//est = set_datos(line_buffer, s);
		printf("%s\n", line_buffer);
		estaciones[line_number] = set_datos(line_buffer, s);
	
	
	    ++line_number; /* note that the newline is in the buffer */
	}

	char sentence[1000];
   FILE *fptr;

   fptr = fopen("datos.txt", "w");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
int numero_estacion = 30057;
fprintf(fptr, " Este Archivo contiene los datos de la estacion numero: %d\n", numero_estacion);
fprintf(fptr, "Numero        Estacion         Id Localidad       Fecha         Temperatura         Humedad        Punto de Rocio       Precipitacion         Velocidad del Viento      Direccion del Viento       Rafaga Maxima        Presion      Radicion Solar         Temperaturas del Suelo                Humedades del Suelo       Humedad Hoja        \n" );
int cant_estaciones = sizeof(estaciones) / sizeof(estaciones[0]);
	for (int i = 0; i < cant_estaciones; i++){
		if (estaciones[i].numero == numero_estacion){
			fprintf(fptr, "%s \n", estaciones[i].estacion);
		}
	}
   fclose(fptr);

}	