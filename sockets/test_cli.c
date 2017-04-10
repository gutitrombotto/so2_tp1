#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define TAM 256
/*! \def TOKEN_BUFSIZE
    \brief Tamaño maximo del buffer para palabras de consola
*/
#define TOKEN_BUFSIZE 64
/*! \def TOKEN_DELIM
    \brief Delimitadores de la linea de comandos
*/
#define TOKEN_DELIM " \t\r\n\a@:"


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
		char buffer[TAM];
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
		}
		if (!strcmp(line_parsed[2], "localhost"))
		{
			printf("Escribiste localhost de numero_ip\n");
		}
		if (!strcmp(line_parsed[3], "6020"))
		{
			printf("Escribiste el puerto 6020\n");
		}
		exit(0);
	}