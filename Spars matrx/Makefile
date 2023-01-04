CC=gcc

all: compile run

compile: *.o
	$(CC) -g main.c spars.c -o matrix
run:
	./matrix matrix.txt

clean: *.o
	rm -r *.o matrix

