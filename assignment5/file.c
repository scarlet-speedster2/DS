#include<stdio.h>
#include<stdlib.h>
//#include"file.h"

//FILE* randomIntegers(){
int main(){
	int i =0;
	FILE *fptr;
	fptr = fopen("integers","w");
	if(!fptr){

		printf("File opening failed\n");
		return 0;
	}
	for(i = 0;i<200000;i++){
		putw(rand(),fptr);
	}
	fclose(fptr);

	//return fptr;
}
	
