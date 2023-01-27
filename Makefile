all: main.c analisador.h analisador.c hashtable.h hashtable.c
	gcc -o prog main.c analisador.c hashtable.c
