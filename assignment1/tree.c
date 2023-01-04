#include<stdio.h>
#include"bst.h"


void main(){
	
	int ch;
	bst t;
	node* n;
	int m;
	

	do{

		printf("1. Initialize BST\n2. Insert Node\n3. Delete Node\n4. Succesor & Predecssor\n5. Traverse \n6. Search\n7. Display Level\n8. Destory Tree\n9. Exit");
		printf("\n\nEnter your choice");
		scanf("%d",&ch);

		switch(ch){
			
			case 1: 
				initBST(&t);
				break;
			case 2:
				n = createNode();
				insertNode(&t,n);
				break;
			case 3:
				printf("\n Enter MIS");
				scanf("%d",&m);
				removeNode(&t,m);
				break;
			case 4:
				
				node* a = searchNode(t);
				node* s = successor(a);
				node* p = predecessor(a);
				printf("\nSuccesor = %d",s-> MIS);
				printf("\nPredecessor = %d",p ->MIS);

				break;
			case 5:
				int cc;
				printf("\n1. Pre-Order \n2. In-Order\n3. Post-Order");
				scanf("%d",&cc);
				switch(cc){
					
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
						printf("\nInvalid case");
						break;
				}
				break;

			case 6:
				int k;
				printf("Enter key");
				scanf("%d",&k);
				int f = search(t,k);
				if(f == 1)
					printf("\nFound");
				else
					printf("\nNOt Found");
				break;
			case 7:
				int level;
				printf("\nEnter the level you want to print");
				scanf("%d",&level);
				display_Level(t,level);
				break;
			
			case 8:
				destroyTree(&t);
				break;
			default:
				if(ch != 9){
				printf("\nInvalid choice");
				}
				break;
		}
	}while(ch != 9);

}		
