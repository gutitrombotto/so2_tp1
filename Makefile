FUENTES=./src/doc_parse.c

CFLAGS=-I../includes -Wall -pedantic

INCLUDES=-I../includes 

#OBJETOS=$(SRCS:.c=.o)

MAIN=exe/doc_parse

all: bin cppcheck

normal:
	gcc $(FUENTES) $(CFLAGS) -o $(MAIN)

bin: $(OBJETOS) 
	gcc $(FUENTES) $(CFLAGS) -o $(MAIN) $(OBJETOS)

cppcheck:
	cppcheck --enable=all --inconclusive --std=posix ../SO2_TP1_2017  

clean:
	$(RM) $(OBJETOS) $(MAIN)
