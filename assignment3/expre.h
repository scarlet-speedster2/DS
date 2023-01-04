

typedef struct node{

	char c;

	struct node* left;
	struct node* right;
}node;

typedef node* ex_tree;


void initTree(ex_tree* t,char* e);

void traverse(ex_tree t);


int compute(ex_tree t);

node* createNode(char c);
