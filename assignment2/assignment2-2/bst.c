#include<stdio.h>
#include<stdlib.h>
#include"bst.h"


bst constructTree(int A[], int s, int n)
{
    if (s > n) {
        return NULL;
    }
 
    node* nn = createNode(A[n]);
 
    int i;
    for (i = n; i >=s; i--)
    {
        if (A[i] < nn->data) {
            break;
        }
    }
 
 
    nn->right = constructTree(A, i + 1, n- 1);
 
    nn->left = constructTree(A, s, i);
 
    return nn;
}

/*void create_Tree(int A[],int i,int n,bst* t){

	if(i>n)
		return;
	insert(&(*t),A[n-1]);
	int x = i;
	for(int j = i;j< n-1;j++){
		if(A[j]< A[n-1])
			x++;
	}
	create_Tree(A,i,x,&(*t));
	create_Tree(A,x+1,n-1,&(*t));
}
*/

void initBst(bst* t){
	*t = NULL;
	return;
}

node* createNode(int key){
	
	node* nn = (node*) malloc (sizeof(node));
	if(!nn)
		return NULL;
	nn -> data = key;
	nn -> left = NULL;
	nn -> right = NULL;
	return nn;
}

void insert(bst* t,int key){

	if(*t == NULL){
		(*t) = createNode(key);
		return;
	}
	node* temp = *t;
	node* nn = createNode(key);
	//node* prev = NULL;
	while(temp != NULL){
		
		if(temp -> data > key ){
			if(!temp->left){
				temp  -> left = nn;
				return;
			}
			temp = temp -> left;
		}
		else{
			if(!temp -> right){
				temp -> right = nn;
				return;
			}
			temp = temp -> right;
		}
	}
}


void inorder(bst t){
	
	if(t == NULL)
			return;
	inorder(t->left);
	printf(" %d ",t->data);
	inorder(t ->right);
}

void preorder(bst t){
	

	if(t == NULL)
		return;
	printf(" %d ",t -> data);
	preorder(t -> left);
	preorder(t -> right);
}

void postorder(bst t){


	if( t == NULL)
		return;
	postorder(t -> left);

	postorder( t -> right);
	printf(" %d ", t->data);

}


