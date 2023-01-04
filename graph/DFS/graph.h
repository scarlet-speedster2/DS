
typedef struct list{

	int w,v;

	struct list* next;
}list;

typedef list* lnode;


typedef struct node{

	int vertex;

	struct list** adjlist;
}node;

typedef struct edge{

	int s,d;
	int w;
}edge;

typedef node* graph;

void init(graph* g);

void creategraph(graph* g,char* file);

void printgraph(graph g);

void dfs(graph g);

void bfs(graph g);

edge* prims(graph g);

