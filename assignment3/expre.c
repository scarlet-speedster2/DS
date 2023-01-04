#include<stdlib.h>
#include<stdio.h>
#include"expre.h"
#include"stack.h"
#include"stack2.h"


node* createNode(char c){
	node* temp = (node*) malloc (sizeof(node));
	if(!temp)
		return NULL;
	temp -> c = c;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void initTree(ex_tree* t,char* e){

	stackN s1;
	init1(&s1);
	stackO s2;
	init2(&s2);
	node* lc = NULL;
	node* rc = NULL;
	node* n = NULL;
	node* o = NULL;
	
	for(int i = 0;e[i] != '\0';i++){

		if(e[i] == '(' || e[i] == ')')
			continue;

		if (e[i] == '0' || e[i] == '1' ||e[i] == '2' ||e[i] == '3' ||e[i] == '4' ||e[i] == '5' ||e[i] == '6' ||e[i] == '7' ||e[i] == '8' ||e[i] == '9') {

			n = createNode(e[i]);
			push1(&s1,&n);

		}

		else if(e[i] == '+'|| e[i] == '-' || e[i] == '*' || e[i] == '/'){

			rc = pop1(&s1);
			lc = pop1(&s1);
			o = createNode(e[i]);
			o -> left = lc;
			o -> right = rc;
			push1(&s1,&o);
		}
		else{
			printf("\nExpression is invalid");
			return;
		}
	}

	*t = pop1(&s1);
}


void traverse(ex_tree t){

	if(t == NULL)
		return;

	traverse(t -> left);
	printf("%c ",t -> c);
	traverse(t -> right);
}

int compute(ex_tree tree){

	if(tree == NULL) 
		return 0;
	
	if(tree->left == NULL && tree->right == NULL) 
		return ((int)tree->c) - 48;

	int left = compute(tree->left);
	int right = compute(tree->right);
	
	if(tree->c== '+') 
		return left + right;
	if(tree->c== '-') 
		return left - right;
	if(tree->c== '*') 
		return left * right;
	if(tree->c== '/') 
		return left / right;

	return -1;

}

	









	
	 

