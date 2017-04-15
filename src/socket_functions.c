#include "../includes/socket_functions.h"
void socket_w(int newsockfd, char * buffer){
	//printf("%s\n",buffer );
	int n;
	int datalen = strlen(buffer); // # of bytes in data
	int tmp = htonl(datalen);
	n = write(newsockfd, (char*)&tmp, sizeof(tmp));
	if (n < 0) perror("ERROR writing to socket");
	n = write(newsockfd, buffer, datalen);
	if (n < 0) perror("ERROR writing to socket");
}

void socket_r(int sockfd, char * buffer){
	memset( buffer, '\0', TAM );
	int buflen;
	int n;
	n = read(sockfd, (char*)&buflen, sizeof(buflen));
	if (n < 0) perror("ERROR reading from socket");
	buflen = ntohl(buflen);
	n = read(sockfd, buffer, buflen);
	if (n < 0) perror("ERROR reading from socket");
	else printf("Recibi %*.*s", n, n, buffer);
}

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
