
typedef struct node{
	
	int data;
	struct node* left;
	struct node* right;
}node;

typedef node* bst;

void insert(bst* t);
void init(bst* t);
void traverse(bst t);

