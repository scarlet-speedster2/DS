#include<stdio.h>
#include<stdlib.h>
#include"bst.h"
#include"stack.h"


void initStack(stack** s){
	
	*s = NULL;
	return;
}

void push(stack** s,node** temp){

	if(*s == NULL){
		
		stack* p = (stack*) malloc (sizeof(stack));
		if (!p)
			return;
		p-> n = (*temp);
		p -> next = NULL;
		(*s) = p;
		return;
	}
	
	stack* p = (stack*) malloc (sizeof(stack));
	if (!p)
		return;
	p -> n = *temp;
	p -> next = *s;
	*s = p;


}

node* peek(stack* s){
	
	return(s->n);
}

int isEmpty(stack* s){
	
	if(s == NULL){
		return 1;
	}

	return 0;
}

node* pop(stack** s){
	
	node* temp = (*s) -> n;
	(*s) = (*s) -> next;

	return temp;
}
