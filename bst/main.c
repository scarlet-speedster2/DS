#include<stdio.h>
#include"bst.h"

void main(){

	bst t;
	init(&t);
	insert(&t);
	insert(&t);
	insert(&t);
	insert(&t);
	insert(&t);
	traverse(t);
}
