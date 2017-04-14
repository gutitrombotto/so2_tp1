#include "../includes/server_functions.h"
#include "../includes/parse_functions.h"
#include "../includes/socket_functions.h"


int main(int argc, char **argv)
{

	struct Estacion *estaciones[MAX_ESTACIONES];
	char *inname = "datos_meteorologicos.CSV";
	int  numero_estacion = 30061;
	
	char buffer[TAM];
	char srv_buf [TAM];
	char *lista;
	int sockfd, newsockfd, puerto, pid;
	socklen_t clilen;
	struct sockaddr_in serv_addr, cli_addr;
	load_file(inname, estaciones);
	int n;
	int c;
	
	if ( argc < 2 ) {
		fprintf( stderr, "Uso: %s <puerto>\n", argv[0] );
		exit( 1 );
	}

	sockfd = socket( AF_INET, SOCK_STREAM, 0);
	if ( sockfd < 0 ) { 
		perror( " apertura de socket ");
		exit( 1 );
	}

	memset( (char *) &serv_addr, 0, sizeof(serv_addr) );
	puerto = atoi( argv[1] );
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons( puerto );

	if ( bind(sockfd, ( struct sockaddr *) &serv_addr, sizeof( serv_addr ) ) < 0 ) {
		perror( "ligadura" );
		exit( 1 );
	}

	printf( "Proceso: %d - socket disponible: %d\n", getpid(), ntohs(serv_addr.sin_port) );

	listen( sockfd, 5 );
	clilen = sizeof( cli_addr );

	while( 1 ) {


		newsockfd = accept( sockfd, (struct sockaddr *) &cli_addr, &clilen );

		if ( newsockfd < 0 ) {
			perror( "accept" );
			exit( 1 );
		}

		pid = fork(); 
		if ( pid < 0 ) {
			perror( "fork" );
			exit( 1 );
		}

		if ( pid == 0 ) 
		{  // Proceso hijo
			close( sockfd );

			while ( 1 ) 
			{	

				/*Lectura de contraseña y testeo de contraseña*/
				leer_socket(newsockfd,buffer);
				printf( "PROCESO %d. ", getpid() );
				printf( "Recibí: %s", buffer );

				buffer[strlen(buffer)-1] = '\0';
				printf("%s\n", buffer);
				if(!strcmp(buffer,"contra")){
					char * contra_ok = "Contraseña correcta. Estas autenticado\n";
					escribir_socket(newsockfd,contra_ok);
					
					break;
				} else {
					char * contra_mal = "contraseña incorrecta";
					escribir_socket(newsockfd,contra_mal);

				}
				/* FIN Lectura de contraseña y testeo de contraseña*/

				// Verificación de si hay que terminar
				buffer[strlen(buffer)-1] = '\0';
				if( !strcmp( "fin", buffer ) ) {
					printf( "PROCESO %d. Como recibí 'fin', termino la ejecución.\n\n", getpid() );
					exit(0);
				}
			}


			while(1)
			{
				/* Envio de la lista de comandos*/
				lista = "\nlistar \n descargar no_estación \n diario_precipitacion no_estación \n mensual_precipitacion no_estación \n mensual_precipitacion no_estación \n promedio variable \n desconectar \n";
				//printf("%s\n", lista);
				escribir_socket(newsockfd,lista);

				/*Leo que comando mandó el cliente*/
				leer_socket(newsockfd,buffer);
				printf(" Recibí : %s\n", buffer);
				//buffer[strlen(buffer)-1] = '\0';
				char ** line_parsed;
				line_parsed = split_line(buffer);

				printf("%s\n", line_parsed[0]);
				
				c = test_commando(line_parsed[0]);

				printf("%d\n", c);

				execute_task(c, line_parsed);
				escribir_socket(newsockfd, (char *)&c);
				
				/*Fin de lectura del comando del cliente*/	
						
			}
		}
		/*Funcion del Padre*/
		else {
			printf( "SERVIDOR: Nuevo cliente, que atiende el proceso hijo: %d\n", pid );
			close( newsockfd );
		}
	}
	return 0; 
} 


	//int err = descargar(estaciones, numero_estacion,path);
	//int err = listar_estaciones(estaciones);
	//int err = mensual_precipitacion(estaciones, numero_estacion);
	//int err = listar_estaciones(estaciones);

	



