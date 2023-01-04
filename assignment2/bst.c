#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stddef.h>
#include<stdbool.h>
#include"bst.h"

void initBST(bst* t){
	
	size_t size = 50;
	(*t) = (node*) malloc (sizeof(struct node) + sizeof(int) * size);
	if(!*t)
		return;
	(*t) -> n = size;

	node* temp = (*t);
	for(size_t i = 0 ;i< size;++i){
		temp -> A[i] = INT_MIN;
	}

}


void _inorder(bst t,int i, int n){   // Helper funtionn

	if(i<n){
		_inorder(t,(2*i)+1,n);
		if (t->A[i] == INT_MIN)
			printf(" - ");
		else
			printf(" %d ",t->A[i]);
		_inorder(t,(2*i)+2,n);
	}
}
void inorder(bst t){

	int i = 0;
	int n = t->n;
	
	_inorder(t,i,n);
}

void insert(bst* t,int key){
	
	node* temp = *t;
	int n = temp -> n;
	int i = 0;

	while(i<n){
		if(temp -> A[i] == key){
			printf("\n already present in the tree");
			return;
		}
		if(temp -> A[i] == INT_MIN){

			temp ->A[i] = key;
			printf("\nInserted at %d index ",i);
			break;
		}
		else if(temp -> A[i] >key)
			i = (2*i) + 1;
		else 
			i = (2*i) + 2;
	}
}
int count(bst t){                           // helper for is complete
	int c = 0;
	for(int i = 0;i< t->n;i++){
		if(t->A[i] != INT_MIN)
			c++;
	}
	return c;
}
	
	
int isCompelete(bst t){
	if(!t)
		return 1;
	int n = count(t);
	int j = 0;
	for(int i = 0; i<t->n;i++){
		if(t->A[i] != INT_MIN)
			j = i;
	}
	if(j>= n)
		return 0;
	return 1;
}

void _preorder(bst t,int i,int n){   // helper for pre
	
	if(i<n){
		if(t->A[i] != INT_MIN)
			printf("%d ",t ->A[i]);
		_preorder(t ,(2*i)+1,n);
		_preorder(t,(2*i) +2,n);
	}
}

void preorder(bst t){
	
	int i = 0;
	int n = t->n;
	if(!t)
		return;
	_preorder(t,i,n);

}
void _postorder(bst t,int i,int n){   // helper for p
				      // ost order
	
	if(i<n){
		_postorder(t,(2*i)+1,n);
		_postorder(t,(2*i) +2,n);
		if(t->A[i] != INT_MIN)
			printf("%d ",t ->A[i]);
	}
}
void postorder(bst t){
	int i = 0;
	int n = t->n;
	if(!t)
		return;
	_postorder(t,i,n);
}
