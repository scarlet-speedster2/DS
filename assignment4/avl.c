#include<stdio.h>
#include<stdlib.h>
#include"avl.h"
#include"io.h"

node* minimum(avl t){
	
	if(!t)
		return NULL;
	while(t->left != NULL)
		t = t ->left;
	return t;
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

int height(node* t){
	
	int l,r;
	if(t == NULL)
		return 0;
	else{
		l = height(t -> left);
		r = height(t -> right);
		if(l>r)
			return (l +1);
		else
			return( r+ 1);
	}
}

int bf(node* t){

	if(t == NULL)
		return 0;
	int b = height(t -> left) - height(t->right);
	return b;
}


void init(avl* t){
	*t = NULL;
	return;
}
node* createNode(int d){
	node* temp = (node*) malloc (sizeof(node));
	if(!temp)
		return NULL;
	temp -> m = d;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> parent = NULL;
	temp -> bf = 0;
	return temp;
}

node* LL(avl y){
	
	node* y1 = (y);
	node* x = (y1) -> left;
	node* temp = (y1) -> parent;
	(y1)-> left = x -> right;
	x -> right = y1;
	(y1) -> parent = x;
	x -> parent = temp;
	x -> bf = bf(x);
	(y1) -> bf = bf ((y1));
	return (x);
}
	
node* RR(avl y){
	
	node* y1 = (y);
	node* x = (y1) -> right;
	node* temp = (y1) -> parent;
	(y1)-> right = x -> left;
	x -> left= y1;
	(y1) -> parent = x;
	x -> parent = temp;
	x -> bf = bf(x);
	(y1) -> bf = bf ((y1));
	return (x);
}
node* adjust(avl t){
	node* y = t;
	node* x;
	if ( y -> bf == 2){
		x = y -> left;
		if(x -> left){
			y = LL(y);
			return y;
		}
		else
			y = LR(y);
		}
	else if( y -> bf == -2){
		x = y -> right;
		if( x -> right){
			y = RR(y);
			return y;
			}
		else 
			y = RL(y);
		}
	return t;
}
void updatebf(node* y){

	while(y != NULL){
		y -> bf = bf(y);
		y = y -> parent;
	}
}
void insertNode(avl* t1,int d){

	node* nn = createNode(d);

	node* y = *t1;
	node* f = *t1;
	node* t = *t1;
	while(t != NULL){
		y = t;
		if(nn -> m > t -> m)
			t = t ->right;
		else
			t = t -> left;
	}
	nn -> parent = y;
	if(y == NULL){
		*t1 = nn;
		return;
	}
	if(y -> m > nn -> m)
		y -> left = nn;
	else 
		y -> right = nn;

	//updating bf
	
	node* temp = *t1;
	while(temp != NULL){
		
		temp -> bf = bf(temp);
		if(nn -> m > temp -> m)
			temp = temp -> right;
		else
			temp = temp -> left;
	}
	while(y){
		y = adjust(y);
		updatebf(y);
		f = y;
		y = y -> parent;
	}
	*t1 = f;
	
}

void _removeNode(avl* t,int key){

	if(!*t){
		printf("\n Tree is empty can not delete nodes");
		return;
	}
	
	node* temp = *t;
	
	while(temp != NULL){
		
		if(temp -> m == key)
			break;
		else if( temp -> m > key)
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
	
	temp -> m= y -> m;
	_removeNode(&(temp -> right), temp -> m);

	
		
}

void removeNode(avl* t,int d){
	
	_removeNode(&(*t),d);
	node* f= *t;
	node* temp = *t;
	node* y = NULL;
	while(temp != NULL){
		y = temp;
		temp -> bf = bf(temp);
		if(d > temp -> m)
			temp = temp -> right;
		else
			temp = temp -> left;
	}
	while(y){
		y = adjust(y);
		updatebf(y);
		f = y;
		y = y -> parent;
	}
	*t  = f;
}
	


void _destroyTree(avl t){         // helper function to destroy..
	
	if(t){
		_destroyTree(t -> left);
		_destroyTree(t -> right);
		free(t);
	}
}
void destroyTree(avl* t){

	if(!*t){
		printf("\ntree is empty");
		return;
	}
	_destroyTree(*t);
	*t = NULL;
}


node* LR(avl t){

	t -> left = RR(t -> left);
	return (LL(t));

}
node* RL(avl t){
	t -> right = LL(t -> right);
	return (RR(t));
}
void traverse(avl t){

	if(t == NULL){
		return;
	}
	traverse(t ->left);
	printf("%s - %s - %d  ,",getName(t),getParent(t),t -> bf);
	traverse(t -> right);
}
