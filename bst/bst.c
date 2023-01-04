#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

void init(bst* t){

	*t = NULL;
	return;
}

void insert(bst* t){

	int d;
	
	printf("Enter the data you want to insert");
	scanf("%d",&d);
	
	node* z = (node*) malloc(sizeof(node));
	if(!z)
		return;
	z ->data = d;
	z ->left = z->right = NULL;
	
	
	node* x = *t;
	node* y = NULL;

	while(x != NULL){
		y = x;
		if(z-> data < x ->data)
			x = x->left;
		else
			x = x->right;
	}
	if( y == NULL)
		*t = z;
	else if( z->data < y ->data)
		y ->left = z;
	else
		y ->right = z;
}

void traverse(bst t){
	if ( t != NULL){
		traverse( t->left);
		printf("%d",t->data);
		traverse(t ->right);
	}
}
