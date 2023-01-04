#include<stdio.h>
#include<stdlib.h>

typedef struct tree{

	int data;
	struct node* left;
	struct node* right;
};

typedef struct stack {
	
	int top;
	int capacity;
	int* array;
	
};

int isfull

stack* create_stack(int c){
	stack* ss = (stack*) malloc(sizeof(stack));
	ss-> top = -1;
	ss -> capacity = c;
	ss ->array = (int*) malloc(sizeof(c*sizeof(int)));
	return (ss);
}


tree* create_tree(int d){

	tree* new_node = (tree*) malloc (sizeof(tree));
	if (!new_node) return;
	new_node ->data = d;
	new_node ->left = NULL;
	new_node ->right = NULL;
	return(new_node);
}


