CC = gcc
CFLAGS = -Wall -g
OBJS = Funciones.o Escritura.o main.o
all: main
main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

Funciones.o: Funciones.c Funciones.h
	$(CC) $(CFLAGS) -c -o Funciones.o Funciones.c
	objdump -d Funciones.o > Funciones.s

Escritura.o: Escritura.c Escritura.h Funciones.h
	$(CC) $(CFLAGS) -c -o Escritura.o Escritura.c
	objdump -d Escritura.o > Escritura.s

main.o: main.c Funciones.h Escritura.h
	$(CC) $(CFLAGS) -c -o main.o main.c
	objdump -d main.o > main.s

clean:
	rm -f main $(OBJS) *.s