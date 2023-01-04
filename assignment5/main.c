/*
 *    Name = Snehal Shinde
 *    MIS = 142103013 (Div - 2)
 *    Email = shindess21.comp@coep.ac.in
 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"heap.h"

int main(int argc,char* argv[]){

	FILE *fptr;
	char *p = argv[2];
	heap t;
	init(&t);

	int size;
	if(isdigit(*p)){
		size =(int) strtol(p, &p, 10);
	}
	//printf("Size = %d",size);

	fptr = fopen(argv[1],"r");
	if(!fptr){
		printf("Failed to open file\n");
		return 0;
	}
	cpFromFile(&t,fptr,size);
	heapSort(t);
	//buildHeap(t);
	traverse(t);
	return 0;
}



