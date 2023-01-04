#include<stdio.h>
#include<stdlib.h>
#include"spars.h"


int main(int argc,char* args[]){

	spars m;
	init(&m);
	creatematrix(&m,args[1]);
	printmatrix(m);
}
