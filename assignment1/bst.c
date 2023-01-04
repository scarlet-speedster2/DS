#include<stdio.h>
#include<stdlib.h>
#include"bst.h"
#include"stack.h"

void initBST(bst* t){

	*t = NULL;
	return;
}

node* minimum(bst t){
	
	if(!t)
		return NULL;
	while(t->left != NULL)
		t = t ->left;
	return t;
}

node* maximum(bst t){
	
	if(!t)
		return NULL;

	while(t ->right != NULL)
		t = t -> right;

	return t;
}

node* searchNode(bst t){
	
	if(!t)
		return NULL;
	int m;
	printf("\nEnter the MIS ");
	scanf("%d",&m);
	while( t != NULL){
		if( t -> MIS == m)
			return t;
		else if(t -> MIS > m)
			t = t -> left;
		else
			t = t -> right;
	}
	
	return NULL;
}

node* successor(node* x){

	if( x -> right != NULL)
		return minimum(x->right);
	node* y = x -> parent;
	while(y != NULL && y -> right == x){
		x = y;
		y = y ->parent;
	}
	return y;
}

node* predecessor(node* x){
	
	if(x -> left != NULL)
		return maximum(x->left);
	
	node* y = x -> parent;

	while( y != NULL && y -> left){
		x = y;
		y = y ->parent;
	}
	return y;
}


void removeNode(bst* t,int key){

	if(!*t){
		printf("\n Tree is empty can not delete nodes");
		return;
	}
	
	node* temp = *t;
	
	while(temp != NULL){
		
		if(temp -> MIS == key)
			break;
		else if( temp -> MIS > key)
			temp = temp -> left;
		else
			temp = temp -> right;
	}
	if(!temp){
		printf("\n The node is not present in the tree");
		return;
	}
	
	node* y = temp -> parent;

	if(temp -> right == NULL && temp -> left == NULL){
		
		
		if( y -> left == temp ){
			y -> left = NULL;
			free( temp);
			return;
		}
		y -> right = NULL;
		free(temp);
		return;
	}
	
	if( temp -> right == NULL || temp -> left == NULL){

		if( y -> right == temp){

			if( temp -> right != NULL){
				y -> right = temp -> right;
				temp -> right -> parent = y;
				free(temp);
				return;
			}

			y -> right = temp -> left;
			temp -> left -> parent = y;
			free(temp);
			return;
		}

		if( temp -> right != NULL){
			
			y -> left = temp -> right;
			temp -> right -> parent = y;
			free(temp);
			return;
		}
		
		y -> left = temp -> left;
		temp -> left -> parent = y;
		free( temp);
		return;
	}
	
	y = successor(temp);
	
	temp -> MIS = y -> MIS;
	temp -> name = y -> name;
	removeNode(&(temp -> right), temp -> MIS);

	
		
}

int search(bst t, int key){

	if( t == NULL)
		return 0;
	if ( t -> MIS == key)
		return 1;
	if(t-> MIS > key)
		return search(t -> left,key);
	else
		return search(t -> right,key);

}

void postorder(bst t){

	if(!t)
		return;
	
	node* previous = NULL;
	stack* ss;
	initStack(&ss);
	while(1){
		while(t != NULL){
			push(&ss,&t);
			t = t ->left;
		}
		while( t == NULL && !isEmpty(ss)){
			t = peek(ss);
			if(t -> right == NULL || t -> right == previous){

				t = pop(&ss);
				previous = t;
				printf("\nMIS = %d ",t ->MIS);
				printf("\nName = %s ",t ->name);
				printf("\n");
				t = NULL;
			}
			else
				t = t ->right;
		}
		if(isEmpty(ss))
			return;
	}
}

void preorder(bst t){
	
	if(!t)
		return;

	stack* ss;
	initStack(&ss);
	while(1){
		while(t != NULL){
			printf("\nMIS No = %d",t->MIS);
			printf(" Name = %s",t->name);
			push(&ss,&t);
			t = t ->left;
		}
		if(isEmpty(ss))
			return;
		
		t = pop(&ss);
		t = t -> right;
	}

			
}
void display_Level(bst t,int l){

	if(!t)
		return;
	if( l == 1 ){

		printf("\n%d",t -> MIS);
		printf("\n%s\n",t -> name);
	}
	else if ( l > 1){
		
		display_Level(t -> left , l-1);
		display_Level(t -> right, l-1);
	}
	
}

void _destroyTree(bst t){         // helper function to destroy..
	
	if(t){
		_destroyTree(t -> left);
		_destroyTree(t -> right);
		free(t);
	}
}
void destroyTree(bst* t){

	if(!*t){
		printf("\ntree is empty");
		return;
	}
	_destroyTree(*t);
	*t = NULL;
}

node* createNode(){
	
	int m;
	printf("Enter the MIS");
	scanf("%d",&m);
	
	char* n;
	printf("\nEnter the name");
	scanf("%ms",&n);
	
	node* nn = (node*) malloc(sizeof(node));
	if(!nn)
		return NULL;
	nn -> MIS = m;
	nn -> name = n;
	nn -> left = NULL;
	nn -> right = NULL;
	nn -> parent = NULL;
	return nn;
}

void insertNode(bst* t,node* nn){

	if(*t == NULL){
		
		*t = nn;
		return;
	}
	
	node* temp = *t;
	
	if(temp -> MIS == nn -> MIS){
		free(nn);
		return;
	}

	if(temp -> MIS > nn -> MIS){
		
		if(temp -> left == NULL){
			temp  -> left = nn;
			nn -> parent = temp;
			return;
		}
		else if (temp ->left -> MIS == nn -> MIS){
			free(nn);
			return;
		}
		else{
			insertNode( &(temp -> left),nn);
		}
	}
	else{
		if( temp ->right == NULL){
			temp -> right = nn;
			nn -> parent = temp;
			return;
		}
		else if( temp -> right ->MIS == nn -> MIS){
			free(nn);
			return;
		}
		
		insertNode(&(temp -> right),nn);
	}
}

void inorder(bst t){

	if(!t){
		printf("\n Tree is empty");
		return;
	}
	stack* ss;

	initStack(&ss);
	
	while(1){

		while(t != NULL){
			
			push(&ss,&t);
			t = t ->left;
		}

		if(isEmpty(ss))
			return;
		t = pop(&ss);
		printf("\nMIS = %d ",t ->MIS);
		printf("\nName = %s ",t ->name);
		t = t->right;
	}
}
	
