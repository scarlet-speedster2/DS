#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"graph.h"
#include"queue.h"

/* typedef struct list{

	int w,v;

	struct list* next;
}list;

typedef list* lnode;


typedef struct node{

	int vertex;

	struct list** adjlist;
}node;

typedef node* graph;

void init(graph* g);

void creategraph(graph* g,char* file);

void printgraph(graph g);
*/


	
void bfs(graph g){
	int start = 3;
	int* visited = (int*) calloc (g->vertex,sizeof(int));
	queue q;
	init_queue(&q);
	lnode temp = NULL;
	enqueue(&q,start);
	int p;
	while(!isEmptyq(q)){
		p = dequeue(&q);
		temp = g ->adjlist[p];
		printf("%d ",p+1);
		visited[p] = 1;
		while(temp != NULL){
			if(visited[temp->v -1] == 0){
				enqueue(&q,temp -> v -1);
				visited[temp->v -1] = 1;
			}
			temp = temp -> next;
		}
		
	}
}
		

	
void dfs(graph g){

	int start = 3;

	int* visited = (int*) calloc (g->vertex,sizeof(int));
	lnode temp = g -> adjlist[3];
	stack s;
	init_stack(&s);
	int p;
	push(&s,start);
	visited[start] = 1;
	printf("%d ",start + 1);
	while(!isEmpty(s)){

		if(temp) {
			if(visited[temp -> v -1 ] == 0){
				push(&s,temp->v -1);
				visited[temp ->v -1] = 1;
				printf("%d ",temp->v );
				temp = g -> adjlist[temp ->v -1];
			}
			temp = temp ->next;
		}
		else{
			p = pop(&s);
			if(p == -1 )
				break;
			temp = g -> adjlist[p];
		}
	}
}


	
void init(graph* g){
	*g = NULL;
	return;
}

void creategraph(graph* g,char* file){

	graph t = (graph) malloc (sizeof(node));
	if(!t)
		return;

	FILE* fpt = fopen(file,"r");
	if(!fpt)
		return;
	char c[20];

	fgets(c,sizeof(c),fpt);
	int y = atoi (c);
	t -> vertex = y;
	t -> adjlist = malloc(y*sizeof(lnode));
	if(!t -> adjlist)
		return;

	for(int j=0;j<y;j++){
		t ->adjlist[j] = NULL;
	}
	int k;
	int num;
	for(int i = 0;i<y;i++){
		for(int j=0;j<y;j++){

			fscanf(fpt,"%d",&num);
			if(!t->adjlist[i] && num != 0){

				lnode l = (lnode) malloc (sizeof(list));
				l ->next = NULL;
				l -> w = num;
				k = j;
				l -> v = ++k;
				t->adjlist[i] = l;
			}
			else if( num != 0){

				lnode l = (lnode) malloc (sizeof(list));
				l -> w = num;
				k = j;
				l -> v = ++k;
				l -> next = t -> adjlist[i];
				t->adjlist[i] = l;
			}
			else{
			}
		}
	}

	*g = t;

				
}

void printgraph(graph g){

	printf("\nNumber of vertices are %d",g->vertex);
	int k;
	for(int i = 0;i< g ->vertex;i++){
		lnode temp = g ->adjlist[i];
		k = i;
		printf("\n %d node list :", ++k);
		while(temp != NULL){
			printf(" vertex %d weight %d ",temp ->v,temp ->w);
			temp = temp -> next;
		}
	}
}



