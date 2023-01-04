#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void init_queue(queue* q){

	*q = NULL;
	return;
}

void enqueue(queue* q,int d){

	queue t = (*q);
	if(!t){
		t = (queue) malloc (sizeof(node1));
		t -> d = d;
		t -> next = NULL;
		(*q) = t;
		return;
	}
	queue f = NULL;
	while(t != NULL){
		f = t;
		t = t -> next;
	}
	queue p = (queue) malloc (sizeof(node1));
	p -> d = d;
	p -> next = NULL;
	f -> next = p;
	return;
}

int dequeue(queue* q){

	if(!*q)
		return -1;
	int d = (*q) -> d;
	(*q) = (*q) -> next;
	return d;
}

int isEmptyq(queue q){
	if(q)
		return 0;
	return 1;
}
