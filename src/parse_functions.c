#include "../includes/estaciones.h"
#include "../includes/parse_functions.h"


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
	

	while( token != NULL ) 
	{
		set_datos_estaciones(token,contador,est);
		contador ++;
		token = strtok(NULL, s);
	}

	return est;
}
void load_file(char *inname, struct Estacion *estaciones[MAX_ESTACIONES])
{
	char line_buffer[BUFSIZ]; /* BUFSIZ is defined if you include stdio->h */
	int line_number;
	FILE *infile;
	int arr_cont;
	arr_cont = 0;
	const char s[2] = ",";

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
			//	printf("%s\n", line_buffer);
			estaciones[arr_cont] = parse_data(line_buffer,s);
			arr_cont ++;
		}


	    ++line_number; /* note that the newline is in the buffer */

	}
	return;
	
}
