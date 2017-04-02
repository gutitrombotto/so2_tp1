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
/**
 *
 * Struct Estacion
 *
 */

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
} estacion; 

char * test_dato(char * token){
	if(!strcmp(token, "--")) return "-1";
	else return token;
}	
struct tm parse_date (const char *input)
{
	printf("Estoy parseando data\n");
 struct tm tm;

 memset(&tm, 0, sizeof(struct tm));
 if (strptime(input, "%d/%m/%Y %H:%M", &tm) == NULL){
 	printf("ERROR DE PARSEo \n");
 }
 
 return tm;
}

int print_fecha(struct tm tm){
  char buf[255];
  strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M", &tm);
  printf("%s\n", buf);
  return 1;
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
		printf("%d\n", contador);
		//printf("%d\n", contador);
		//printf("%s\n", token);
		//printf( " %s\n", token );
		if (contador==0)
		{
						printf("%s\n", token);

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
			printf("%s\n", token);
			//est.fecha=strdup(token);
			est.fecha=parse_date(token);

			printf("%d\n", est.fecha.tm_mon);
			
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

int write_datos_to_file(int numero_estacion, int cant_estaciones, struct Estacion estaciones[MAX_ESTACIONES], char * path)
{
	char str_fecha[255];
	FILE *fptr;
	//fptr = fopen("datos.txt", "w");
	fptr = fopen(path, "w");
	if(fptr == NULL)
	{
		printf("Error!");
		return 0;
	}
	
//fprintf(fptr, "Este Archivo contiene los datos de la estacion numero: %d\n", numero_estacion);
	 fprintf(fptr, "Numero \t Estacion \t \t Id Localidad \t Fecha \t Temperatura(°C) \t Humedad() \t  Punto Rocio \t Precipitacion \t Velocidad del Viento \t Direccion del Viento \t Presion \t Radicion Solar \t Temperaturas Suelo \t  Humedades Suelo \t Humedad Hoja\n");
//fprintf(fptr, "Numero        Estacion         Id Localidad       Fecha         Temperatura         Humedad        Punto de Rocio       Precipitacion         Velocidad del Viento      Direccion del Viento       Direccion del Viento       Presion      Radicion Solar         Temperaturas del Suelo                Humedades del Suelo       Humedad Hoja        \n" );
	for (int i = 0; i < cant_estaciones; i++){
		if (estaciones[i].numero == numero_estacion){
			strftime(str_fecha, sizeof(str_fecha), "%d/%m/%Y %H:%M", &estaciones[i].fecha);
			//fprintf(fptr, "%d \t %s\n", estaciones[i].numero, estaciones[i].estacion);
			fprintf(fptr, "%d \t %s \t %d \t %s \t %.2f \t %.2f \t %.2f \t %.2f\t %.2f\t %s \t %.2f \t %.2f \t %.2f \t %.2f , %s, %s\t \t  %s, %s, %s \t \t %s\n", estaciones[i].numero, estaciones[i].estacion, estaciones[i].id_localidad, str_fecha, estaciones[i].temperatura, estaciones[i].humedad, estaciones[i].punto_rocio, estaciones[i].precipitacion, estaciones[i].velocidad_viento, estaciones[i].direccion_viento, estaciones[i].rafaga_max, estaciones[i].presion, estaciones[i].radiacion_solar, estaciones[i].temperatura_suelo1, estaciones[i].temperatura_suelo2, estaciones[i].temperatura_suelo3, estaciones[i].humedad_suelo1, estaciones[i].humedad_suelo2, estaciones[i].humedad_suelo3, estaciones[i].humedad_hoja);
		}
	}
	fclose(fptr);

	return 0;
}

int main(int argc, char **argv)
{
	struct Estacion estaciones[MAX_ESTACIONES];
	const char s[2] = ",";
	char *inname = "datos_meteorologicos_modif.csv";
	FILE *infile; 
  	char line_buffer[BUFSIZ]; /* BUFSIZ is defined if you include stdio.h */
	char line_number;
	char * path;
	char * buffer;
	int error;
	char buf[255];
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
		//printf("%d\n", line_number);
	    ++line_number; /* note that the newline is in the buffer */
	}

	for (int i = 0; i < 8; ++i)
	{
		//printf("Numero estacion %d\n", estaciones[i].fecha.tm_min);
		//print_fecha(estaciones[i].fecha);
		strftime(str_fecha, sizeof(str_fecha), "%d/%m/%Y %H:%M", &estaciones[i].fecha);
		//str_fecha = buffer_fecha(estaciones[i].fecha, str_fecha);
		printf("%s\n", str_fecha);
	}

	//exit(0);
	int numero_estacion = 30057;
	int cant_estaciones = sizeof(estaciones) / sizeof(estaciones[0]);

	error = write_datos_to_file(numero_estacion,cant_estaciones,estaciones,path);
	if (!error)
	{
		printf("Su archivo llamado %s se ha escrito correctamente con datos de la estacion %d \n", path, numero_estacion);
	}

}
