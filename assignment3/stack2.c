#include<stdlib.h>
#include"stack2.h"
#include"expre.h"


void init2(stackO* s){

	*s = NULL;
	return;
}
char peek2(stackO s){

	if(!s)
		return '\0';
	return (s -> c);
}

char pop2(stackO* s){

	if(!*s)
		return '\0';
	char a = (*s) -> c;
	(*s)  = (*s) -> next;
	return a;
}

int isEmpty2(stackO s){

	if(!s)
		return 1;
	return 0;
}

void push2(stackO* s,char t){

	stackO p = (stackO) malloc(sizeof(s2));
	p -> c = t;
	p ->next = NULL;
	if(!*s){
		*s = p;
		return;
	}
	p -> next = *s;
	*s = p;
	return;
}
