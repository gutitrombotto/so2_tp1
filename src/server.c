#include "../includes/server_functions.h"
#include "../includes/parse_functions.h"




int main(int argc, char **argv)
{
	struct Estacion *estaciones[MAX_ESTACIONES];
    char buffer[26];
    //estaciones = malloc(MAX_ESTACIONES * sizeof(struct Estacion ));
	const char s[2] = ",";
	char *inname = "datos_meteorologicos.CSV";
	FILE *infile; 
  	char line_buffer[BUFSIZ]; /* BUFSIZ is defined if you include stdio->h */
	int line_number;
	int  numero_estacion = 30061;
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
			//	printf("%s\n", line_buffer);
			estaciones[arr_cont] = parse_data(line_buffer,s);
			arr_cont ++;
		}


	    ++line_number; /* note that the newline is in the buffer */

	}
	
	int err = listar_estaciones(estaciones);
	//int err = mensual_precipitacion(estaciones, numero_estacion);
	//int err = listar_estaciones(estaciones);

	exit(0);
	

}

