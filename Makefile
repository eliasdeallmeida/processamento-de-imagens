all: prog.e

prog.e: main.o util.o pgm.o img-process.o
	gcc -o prog.e main.o util.o pgm.o img-process.o

main.o: main.c
	gcc -o main.o -c main.c

util.o: util.c
	gcc -o util.o -c util.c

pgm.o: pgm.c
	gcc -o pgm.o -c pgm.c

img-process.o: img-process.c
	gcc -o img-process.o -c img-process.c

clean:
	rm -f *.o prog.e