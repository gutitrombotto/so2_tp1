#include <unistd.h>
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

typedef struct Client_info {
	char * usuario;
	char * ip_conexion;
	char * puerto;
} Client_info;
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

void listado_comandos(int sockfd)
{
	int n;
	char tmp;
	char * buffer;
	int buflen;

	while(1){
		buflen=0;
		n = read(sockfd, &tmp, 1);
		if (n < 0) perror("ERROR reading from socket");

		if (tmp != '\x2')
			continue;
		buflen = 0;

		do
		{
			n = read(sockfd, &tmp, 1);
			if (n < 0) perror("ERROR reading from socket");

			if (tmp == '\x3')
				break;

        // TODO: if the buffer's capacity has been reached, either reallocate the buffer with a larger size, or fail the operation...
			buffer[buflen] = tmp;
			++buflen;
		}
		while (1);
		
	}

	printf("%*.*s\n", buflen, buflen, buffer);

	return ;
}
int main( int argc, char *argv[] ) {
	int sockfd, puerto, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	int terminar = 0;
	Client_info *cliente = malloc(sizeof(Client_info));
	char buffer[TAM];
	char *server_msjs;
	int conect_auth = 0;
	char tmp;
	char * comandos;
	char * init_comand = "connect usuario@numero_ip:port";
/*	if ( argc < 3 ) {
		fprintf( stderr, "Uso %s host puerto\n", argv[0]);
		exit( 0 );
	}
*/
	
	printf("\t Escribe el siguiente comando con los valores deseado:\n");
	printf("\t connect usuario@numero_ip:port\n\n");
	
	while(1)
	{

		memset( buffer, '\0', TAM );
		fgets( buffer, TAM-1, stdin );

		char ** line_parsed;
		line_parsed = split_line(buffer); 

		
		if (!strcmp(line_parsed[0], "connect"))
		{
			if (!strcmp(line_parsed[1], "agustin"))
			{
				cliente->usuario = line_parsed[1];
				//printf("%s\n", cliente->usuario);
			} else 
			{
				printf("ERROR: usuario %s no valido\n", line_parsed[1]);
				printf("Escribe nuevamente el comando: %s\n", init_comand);
			}
			if (!strcmp(line_parsed[2], "localhost"))
			{
				cliente->ip_conexion = line_parsed[2];
				//printf("%s\n", cliente->ip_conexion);
			} else 
			{
				printf("ERROR: IP %s no valido\n", line_parsed[2]);
				printf("Escribe nuevamente el comando: %s\n", init_comand);
			}
			if (!strcmp(line_parsed[3], "6025"))
			{
				cliente->puerto = line_parsed[3];
				conect_auth = 1;
				//printf("%s\n", cliente->ip_conexion);
			} else 
			{
				printf("ERROR: Puerto %s no valido\n", line_parsed[3]);
				printf("Escribe nuevamente el comando: %s\n", init_comand);
			}

		} else {
			printf("ERROR: Debes Escribir el comando: connect usuario@numero_ip:port \n");
		}

		if (conect_auth)
		{
			break;	
		}

	}
	// Genero Socket Filedescriptor
	server = gethostbyname(cliente->ip_conexion);
	if (server == NULL) {
		fprintf( stderr,"Error, no existe el host\n" );
		exit( 0 );
	}
	puerto = atoi(cliente->puerto);
	sockfd = socket( AF_INET, SOCK_STREAM, 0 );
	if ( sockfd < 0 ) {
		perror( "ERROR apertura de socket" );
		exit( 1 );
	}
	// fin de generacion de socket descriptor

	// Abro la conexion con el servidor //
	memset( (char *) &serv_addr, '0', sizeof(serv_addr) );
	serv_addr.sin_family = AF_INET;
	bcopy( (char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length );
	serv_addr.sin_port = htons( puerto );
	if ( connect( sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr ) ) < 0 ) {
		perror( "conexion" );
		exit( 1 );
	}

	printf("Conexion con el Servidor exitosa. \n");
	

/* While con la Autenticacion */
while(1) 
{

	/* Envio la contraseña */
	printf("Ingresa tu contraseña\n");
	memset( buffer, '\0', TAM );
	fgets( buffer, TAM-1, stdin );

	n = write( sockfd, buffer, strlen(buffer) );
	if ( n < 0 ) {
		perror( "escritura de socket" );
		exit( 1 );
	}
	/* Fin de envio de Contraseña */

	/* Verificacion de Respuesta a auntenticacion */
	memset( buffer, '\0', TAM );
	n = read( sockfd, buffer, TAM );
	if ( n < 0 ) {
		perror( "lectura de socket" );
		exit( 1 );
	}
	printf( "Respuesta: %s\n", buffer );

	if (!strcmp(buffer, "contraseña incorrecta"))
	{
		printf("Ingresó una contraseña incorrecta \n");
	} else {
		break;
	}
	
}

printf("Ya estas Autenticado\n");
printf("Escriba el comando que desea realizar\n");

while(1) 
{

	listado_comandos(sockfd);

}

printf("ESTOY ACA W8\n");
while (1);

exit(0);
}
/*
	int buflen;
	n = read(sockfd, (char*)&buflen, sizeof(buflen));
	if (n < 0) perror("ERROR reading from socket");
	buflen = ntohl(buflen);
	printf("%d\n", buflen);

	n = read(sockfd, server_msjs, buflen);
	if (n < 0) perror("ERROR reading from socket");
	else printf("%*.*s\n", n, n, server_msjs);
*/



