typedef struct list_node{

	int vertex;
	int w;
	struct list_node* next;
}list_node;

typedef list_node* lnode;

typedef struct node{

	int v;
	struct list_node** adjlist;
}node;

typedef node* graph;


void init(graph* g);
void createGraph(graph* g,char* file);
void displayMatrix(graph g);
void displayGraph(graph g);

void dfs(graph g);
