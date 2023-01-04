#include<stdio.h>
#include"bst.h"

void main(){
	bst t;
	int ch,f,d;
	int c;
	do{
	printf("\n\n1.Init BST\n2.Insert\n3.Traverse\n4.Is Complete\n5.Exit");
	scanf("%d",&ch);
		switch(ch){

			case 1:
				initBST(&t);
				break;
			case 2:
				printf("\nEnter key");
				scanf("%d",&d);
				insert(&t,d);
				break;
			case 3:
				printf("\n1.Pre Order\n2.In order\n3.Post Order\n");
				scanf("%d",&c);
				switch(c){
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
						printf("In valid choice\n");
						break;
				}
				break;
			case 4:
				f = isCompelete(t);
				if(f == 1)
					printf("\nTree is Complete");
				else
					printf("\nTree is not complete");
				break;
			default:
				if(ch != 5){
					printf("\nInvaild choice");
					break;
				}
		}
	}while(ch != 5);
}

