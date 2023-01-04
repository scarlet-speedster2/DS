CC = gcc

all: compile run


compile: *.c
	$(CC) -g main.c graph.c stack.c queue.c -o g

run:
	./g graph.txt

clean: *.o
	rm *.o g

