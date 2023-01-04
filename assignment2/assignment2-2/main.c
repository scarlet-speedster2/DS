#include<stdio.h>
#include<string.h>
#include"bst.h"

void main(){

	bst t;

	initBst(&t);
	int n;
	printf("\nEnter the size of posfix expression\n");
	scanf("%d",&n);
	int i,ch;
	int A[n];
	printf("\nEnter the posfix expre...\n");
	for(int k = 0;k<n;k++){
		scanf("%d",&A[k]);
	}
	t = constructTree(A,0,n-1); 
	printf("\nTree constructed!.....\n");
	do{

	printf("\n1.Pre order \n2.In order\n3.Post order\n4.Exit\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			preorder(t);
			break;
		case 2:
			inorder(t);
			break;
		case 3:
			postorder(t);
			break;

		default:
			if(ch != 4)
			printf("\nInvalid case\n");
			break;
	}
	}while(ch!= 4);
	
	
	
}
