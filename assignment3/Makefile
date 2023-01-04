CC=gcc  #compiler
TARGET=tree#target file name
 
all:	main.o expre.o itop.o stack.o stack2.o
	$(CC) main.c expre.c itop.c stack.c stack2.c -o $(TARGET)
 
clean:
	rm -r *.o $(TARGET)
