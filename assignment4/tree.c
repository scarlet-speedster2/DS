#include<stdio.h>
#include"avl.h"
#include"io.h"

int main(){

	avl t;
	init(&t);
	int ch;
	int m;
	char* month;
	do{
		printf("\n1.Insert\n2.Remove\n3.Traverse\n4.Destory Tree\n5.Exit");
		scanf("%d",&ch);
		switch(ch){

			case 1:
				m = getMonth();
				insertNode(&t,m);
				break;
			case 2:
				m = getMonth();
				removeNode(&t,m);
				break;
			case 3:
				traverse(t);
				
				break;
			case 4:
				destroyTree(&t);
				break;
			default:
				if(ch != 5)
					printf("\nInvalid option");
				break;
		}
	}while(ch != 5);
	return 0;
}

			
