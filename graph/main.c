#include<stdio.h>
#include"graph.h"


int main(int argc,char* args[]){

	graph g;
	init(&g);
	createGraph(&g,args[1]);
	//dfs(g);
	//displayMatrix(g);
	displayGraph(g);
	return 0;
}
