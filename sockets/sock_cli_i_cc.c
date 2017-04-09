#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#define TAM 256

/*! \def TOKEN_BUFSIZE
    \brief Tamaño maximo del buffer para palabras de consola
*/
#define TOKEN_BUFSIZE 64
/*! \def TOKEN_DELIM
    \brief Delimitadores de la linea de comandos
*/
#define TOKEN_DELIM " \t\r\n\a@:"

/*!	\fn char** split_line(char * line)
	\brief Separa la linea leida de la consola
	\param  line linea de comando
	\return arreglo de punteros con todos los valores de la linea de comando
*/
char ** split_line(char * line){
	int bufsize = TOKEN_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_backup;
	char * rest;

	//strcpy(rest,line);

	token = strtok_r(line,TOKEN_DELIM,&rest);

	while (token != NULL) {      //Mientras haya tokens
		tokens[position] = token;     //Los guardo en un arreglo
		position++;

		if (position >= bufsize) { //Si el arreglo excede al tamaño prestablecido, agrando el buffer y sigo guardando
			bufsize += TOKEN_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				free(tokens_backup);
				fprintf(stderr, "Baash: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok_r(NULL, TOKEN_DELIM,&rest);
	}
	//free(rest);
	tokens[position] = NULL;
	return tokens;
}

int main( int argc, char *argv[] ) {
	int sockfd, puerto, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	int terminar = 0;

	char buffer[TAM];
/*	if ( argc < 3 ) {
		fprintf( stderr, "Uso %s host puerto\n", argv[0]);
		exit( 0 );
	}
*/
	

	
	
	while(1){
		printf("Escribe el siguiente comando con los valores deseado:\n");
		printf("connect usuario@numero_ip:port\n");

		memset( buffer, '\0', TAM );
		fgets( buffer, TAM-1, stdin );

		char ** line_parsed;
		line_parsed = split_line(buffer); 

		
		if (!strcmp(line_parsed[0], "connect"))
		{
			printf("escribiste connect\n");
		} else {
			printf("Debes Escribir el comando: connect usuario@numero_ip:port \n");
		}
		if (!strcmp(line_parsed[1], "agustin"))
		{
			printf("Escribiste agustin de usuario\n");
		} else {
			printf("Nombre de usuario incorrecto\n");
		}
		if (!strcmp(line_parsed[2], "localhost"))
		{
			
			server = gethostbyname(line_parsed[2]); //gethostbyname( argv[1] );
			if (server == NULL) {
				fprintf( stderr,"Error, no existe el host\n" );
				exit( 0 );
			}
		
			printf("Escribiste localhost de numero_ip\n");
		} else {
			printf("ip del servidor incorrecto\n");
		}
		if (!strcmp(line_parsed[3], "6020"))
		{
			puerto = atoi( line_parsed[3] );
			sockfd = socket( AF_INET, SOCK_STREAM, 0 );
			if ( sockfd < 0 ) {
				perror( "ERROR apertura de socket" );
				exit( 1 );
			}
		} else {
			printf("puerto %d no esta abierto\n", atoi(line_parsed[3]));
		}

		memset( (char *) &serv_addr, '0', sizeof(serv_addr) );
		serv_addr.sin_family = AF_INET;
		bcopy( (char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length );
		serv_addr.sin_port = htons( puerto );
		if ( connect( sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr ) ) < 0 ) {
			perror( "conexion" );
			exit( 1 );
		} else {
			break;
		}

	}
	while(1) {
		
		n = write( sockfd, buffer, strlen(buffer) );
		if ( n < 0 ) {
			perror( "escritura de socket" );
			exit( 1 );
		}

		// Verificando si se escribió: fin
		buffer[strlen(buffer)-1] = '\0';
		if( !strcmp( "fin", buffer ) ) {
			terminar = 1;
		}

		memset( buffer, '\0', TAM );
		n = read( sockfd, buffer, TAM );
		if ( n < 0 ) {
			perror( "lectura de socket" );
			exit( 1 );
		}
		printf( "Respuesta: %s\n", buffer );
		if( terminar ) {
			printf( "Finalizando ejecución\n" );
			exit(0);
		}
	}
	return 0;
}
