#include<stdio.h>
#include"expre.h"
#include"itop.h"


int main(){

	char* e;
	ex_tree t;
	
	printf("\nEnter the infix expression\n");
	scanf("%ms",&e);
	e = InfixToPostfix(e);
	//printf("%s",e);
	initTree(&t,e);
	//traverse(t);
	printf("\nAfter Evaluation = %d",compute(t));
	return 0;
}
