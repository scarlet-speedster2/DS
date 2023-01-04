CC=gcc  #compiler
TARGET=tree#target file name
 
all:	tree.o stack.o bst.o
	$(CC) tree.c stack.c bst.c -o $(TARGET)
 
clean:
	rm -r *.o $(TARGET)
