/*! \file socket_functions.h
    \brief Funciones para el uso de sockets
*/
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

/*!	\fn void socket_r(int newsockfd, char * buffer)
	\brief Lectura del socket
	\param newsockfd Filedescriptor del socket
	\param buffer cadena de caracterres donde se guarda lo leido
*/   
void socket_r(int newsockfd, char * buffer);

/*!	\fn void socket_w(int sockfd, char * buffer)
	\brief Escribe en el socket
	\param newsockfd Filedescriptor del socket
	\param buffer cadena de caracterres a enviar
*/   
void socket_w(int sockfd, char * buffer);

/*!	\fn char** split_line(char * line)
	\brief Separa la linea pasada como parametro
	\param  line linea de comando
	\return arreglo de punteros con todos los valores de la linea de comando
*/
char ** split_line(char * line);

#endif 
