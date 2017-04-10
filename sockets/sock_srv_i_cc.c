#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define TAM 256
#define BUF_SIZE 500

int escribir_mensaje(char * msj, int newsockfd)
{
	int n;
	n = write(newsockfd, msj, strlen(msj)+1);
	if ( n < 0 ) {
		perror( "escritura en socket" );
					//exit( 1 );
		return 1;
	}
	else{
		return 0;
	}
}

char * leer_mensaje(int newsockfd)
{
	char * buffer;
	int n;
	memset( buffer, 0, TAM );
	n = read( newsockfd, buffer, TAM-1 );
	if ( n < 0 ) {
		perror( "lectura de socket" );
		//exit(1);
		return "-1";
	} else{
		return buffer;
	}
}
void verificar_erro(int n)
{
	if ( n < 0 ) {
		perror( "escritura en socket" );
		exit( 1 );
	}
	return;
}
char * lista_comandos()
{
	char * lista;
	memset(lista, 0, sizeof(char)*255);
	lista = "listar \n descargar no_estación \n diario_precipitacion no_estación \n mensual_precipitacion no_estación \n mensual_precipitacion no_estación \n promedio variable \n desconectar";
	return lista;
}
int test_commando(char * buffer)
{
	const char s[2] = " ";
	char *token;

	token = strtok(str, s);
	while( token != NULL ) 
	{
		printf( " %s\n", token );

		if(!strcmp(token, "listar"))
		{
			return 1;
		} else if(!strcmp(token, "descargar"))
		{
			return 2;
		} else if(!strcmp(token, "diario_precipitacion"))
		{
			return 3;
		} else if(!strcmp(token, "mensual_precipitacion"))
		{
			return 4;
		} else if(!strcmp(token, "promedio"))
		{
			return 5;
		} else if(!strcmp(token, "desconectar"))
		{
			return 6;
		} else {
			return 7;
		}
		token = strtok(NULL, s);
	}

}
int main( int argc, char *argv[] ) {
	int sockfd, newsockfd, puerto, clilen, pid;
	char buffer[TAM];
	struct sockaddr_in serv_addr, cli_addr;
	struct sockaddr_storage peer_addr;
           socklen_t peer_addr_len;
	int n;
	void * buf;
	int count;
	char * msj_bienvenida;
	msj_bienvenida = "Bienvenido, escriba su usuario y contraseña";

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

		if ( pid == 0 ) {  // Proceso hijo
			close( sockfd );

			/*n = write(newsockfd, msj_bienvenida, strlen(msj_bienvenida)+1);
				if ( n < 0 ) {
					perror( "escritura en socket" );
					exit( 1 );
				}*/	
			while ( 1 ) {
				memset( buffer, 0, TAM );
				n = read( newsockfd, buffer, TAM-1 );
				if ( n < 0 ) {
					perror( "lectura de socket" );
					exit(1);
				}

				printf( "PROCESO %d. ", getpid() );
				printf( "Recibí: %s", buffer );
				buffer[strlen(buffer)-1] = '\0';

					if (!strcmp(buffer, "agustin,contra"))
					{
						printf("CORERCTAS!!\n");
						char * user_pass = "Usuario y contra correctas\n";
						n = write( newsockfd, user_pass, strlen(user_pass) );
						if ( n < 0 ) {
							perror( "escritura en socket" );
							exit( 1 );
						}
						break;
					} else {

						char * user_pass_incorrecta = "Usuario y contraseña incorrecta";
						//char * str_prompt = prompt();
						n = write( newsockfd, user_pass_incorrecta, strlen(user_pass_incorrecta));
						verificar_erro(n);
					}
				
				// Verificación de si hay que terminar
				buffer[strlen(buffer)-1] = '\0';
				if( !strcmp( "fin", buffer ) ) {
					printf( "PROCESO %d. Como recibí 'fin', termino la ejecución.\n\n", getpid() );
					exit(0);
				}
			}
				while(1){
					
					char * command_list = lista_comandos();
					 n= write( newsockfd, command_list, strlen(command_list));
						verificar_erro(n);

					n = read( newsockfd, buffer, TAM-1 );
					if ( n < 0 ) {
						perror( "lectura de socket" );
						exit(1);
					}
					printf("%s\n", buffer);

					buffer[strlen(buffer)-1] = '\0';
					int commando = test_commando(buffer);
					n= write( newsockfd, commando, strlen(commando));
						verificar_erro(n);

				}
			// tiene usuario y contra ok

		}
		else {
			printf( "SERVIDOR: Nuevo cliente, que atiende el proceso hijo: %d\n", pid );
			close( newsockfd );
			close(sockfd);
		}
	}
	return 0; 
} 
