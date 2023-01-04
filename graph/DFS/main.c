#include<stdio.h>
#include"graph.h"

void main(int argc,char* args[]){

	graph g;
	init(&g);
	creategraph(&g,args[1]);
	//printgraph(g);
	bfs(g);
}
