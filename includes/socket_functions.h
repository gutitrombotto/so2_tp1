#ifndef	SOCKET_FUNCTIONS_H
#define	SOCKET_FUNCTIONS_H

#define TAM 256

/*! \def TOKEN_DELIM
    \brief Delimitadores de la linea de comandos
*/
#define TOKEN_DELIM " \t\r\n\a@:"


/*! \def TOKEN_BUFSIZE
    \brief Tamaño maximo del buffer para palabras de consola
*/
#define TOKEN_BUFSIZE 64

#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void escribir_socket(int newsockfd, char * buffer);

void leer_socket(int sockfd, char * buffer);

/*!	\fn char** split_line(char * line)
	\brief Separa la linea leida de la consola
	\param  line linea de comando
	\return arreglo de punteros con todos los valores de la linea de comando
*/
char ** split_line(char * line);

#endif 
