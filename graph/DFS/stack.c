#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


void init_stack(stack* s){
	*s = NULL;
	return;
}

void push(stack* s,int d){

	if(!*s){
		//printf("\nFrom push");
		*s = (stack) malloc(sizeof(ss));
		(*s) -> a = (int*) malloc(10 * (sizeof(int)));
		(*s) -> size = 10;
		(*s) -> top = -1;
	}
	//printf("\nFrom push 2n time");
	int p = (*s) -> top;
	(*s) -> a[++p] = d;
	(*s) -> top += 1;
	return;
}

int pop(stack* s){
	int t;

	if((*s) -> top != -1){
		t = (*s) -> a[(*s) -> top];
		(*s) -> top -= 1;
		return t;
	}
	return -1;
}

int peek(stack s){

	if(s)
		return (s-> a[s-> top]);
	return -1;
}

int isEmpty(stack s){

	if(!s|| s-> top == -1)
		return 1;
	return 0;
}

	 




