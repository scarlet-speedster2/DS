typedef struct node{

	int m;
	struct node* left;
	struct node* right;
	struct node* parent;
	int bf;
}node;

typedef node* avl;


void init(avl* t);

void insertNode(avl* t1,int d);

void removeNode(avl* t,int d);

void traverse(avl t);

void destroyTree(avl* t);

node* LL(avl t);

node* RR(avl t);

node* LR(avl t);

node* RL(avl t);

int height(node* t);

int bf(node* t);



