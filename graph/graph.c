#include<stdio.h>
#include<stdlib.h>
#include"graph.h"


void init(graph* g){

	*g = NULL;
	return;
}

lnode createNode(int v){
	
	lnode temp = (lnode)malloc(sizeof(list_node));
	if(!temp)
		return NULL;
	temp -> vertex = v;
	temp -> next = NULL;
	return temp;
}



void createGraph(graph* g,char* file){

	graph t = (graph) malloc (sizeof(node));
	if(!t)
		return;
	FILE* fptr = fopen(file,"r");

	if(!fptr){
		printf("\nUnable to open file");
		return;
	}
	char ch[12];
	fgets(ch,sizeof(ch),fptr);
	int y = atoi(ch);
	t -> v = y;
	printf("\nbefore adj");
	t -> adjlist = malloc(y* sizeof(lnode));
	int num;
	if(!t->adjlist)
		return;
	for(int j = 0;j<y;j++){
		t -> adjlist[j] = NULL;
		printf("\n%d iteration",j);
	}
	int k;
	for(int i=0 ; i<y; i++){
		for(int j=0; j<y; j++){
			fscanf(fptr, "%d", &num);
			if(!t->adjlist[i] && num != 0){

				lnode m = (lnode) malloc (sizeof(node));
				if(!m)
					return;
				m -> next = NULL;
				k = j;
				m -> vertex = ++k;
				m -> w = num;
				t -> adjlist[i] = m;

			}
			else if (num != 0){
				lnode m = (lnode) malloc (sizeof(node));
				if(!m)
					return;
				m -> next = NULL;
				k = j;
				m -> vertex = ++k;
				m -> w = num;
				m -> next = t -> adjlist[i];
				t -> adjlist[i] = m;
			}
			else
				continue;
		}
	}

	(*g) = t;

}

void displayMatrix(graph g){

	if(!g)
		return;
	
	int v = g -> v;
	int a[v];
	int k;
	lnode t = NULL;
	for( int i = 0 ;i< v;i++){
		t = g -> adjlist[i];
		for(int j = 0; j< v;j++){
			k = j;
			if( t ){
				//printf("T vertex = %d",t ->vertex);
				if(j == t->vertex){
					printf(" 1");
					t = t ->next;
				}

				else 
					printf(" 0");


			}
			else
				printf(" 0");
		}
		printf("\n");
		
	}
}

void displayGraph(graph g){
	lnode t;
	for(int i = 0; i< g->v;i++){
		t = g ->adjlist[i];
		printf("\nnode %d neighbors:",i);
		while(t != NULL){
			printf("%d",t ->vertex);
			t = t -> next;
		}
	}
}



				
	

	

