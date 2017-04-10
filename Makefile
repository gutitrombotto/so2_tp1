FUENTES=./src/doc_parse.c
FUENTES2=./src/main.c
SRV_FUENTES=./src/server.c \
			./src/parse_functions.c \
			./src/server_functions.c

CFLAGS=-I../includes -Wall -pedantic

INCLUDES=-I../includes 

OBJETOS=$(SRCS:.c=.o)

MAIN=exe/doc_parse
MAIN2=exe/main
SRV_MAIN=exe/server

all: prueba cppcheck

server: $(OBJETOS) 
	gcc $(SRV_FUENTES) $(CFLAGS) -o $(SRV_MAIN) $(OBJETOS)

normal:
	gcc $(FUENTES) $(CFLAGS) -o $(MAIN)

main:
	gcc $(FUENTES2) $(CFLAGS) -o $(MAIN2)

bin: $(OBJETOS) 
	gcc $(FUENTES) $(CFLAGS) -o $(MAIN) $(OBJETOS)

cppcheck:
	cppcheck --enable=all --inconclusive --std=posix ../SO2_TP1_2017  

clean:
	$(RM) $(OBJETOS) $(MAIN)

