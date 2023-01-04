
#include<stdlib.h>
#include"expre.h"
#include"stack.h"
/*
typedef struct s1{

	node* n;
	struct stackN* next;
}s1;


typedef s1* stackN;
*/

void init1(stackN* s){

	*s = NULL;
	return;
}

node* peek1(stackN s){
	if (!s)
		return NULL;
	return s->n;
}

node* pop1(stackN* s){

	node* temp = (*s) -> n;
	*s = (*s)-> next;
	return temp;
}

void push1(stackN* s,node** t){


	stackN p = (stackN) malloc(sizeof(s1));
	if(!p)
		return;
	p -> n = (*t);
	p -> next = NULL;
	if(!*s){
		(*s) = p;
		return;
	}
	p -> next = *s;
	*s = p;
	return;
}



int isEmpty1(stackN s){

	if(!s)
		return 1;
	return 0;
}



