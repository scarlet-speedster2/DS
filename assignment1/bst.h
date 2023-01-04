
typedef struct node{
	
	int MIS;
	char* name;
	struct node* left;
	struct node* right;
	struct node* parent;
}node;

typedef node* bst;

void initBST(bst* t);   // to initialize the tree.

void insertNode(bst* t,node* nn);

void removeNode(bst* t,int key);

int search(bst t, int key);

node* searchNode(bst t);

void postorder(bst t);  // Non-recursive

void inorder(bst t);

void preorder(bst t);

void display_Level(bst t,int l);

void destroyTree(bst* t);

node* minimum(bst t);

node* maximum(bst t);

node* successor(node* x);

node* predecessor(node* x);

node* createNode();
