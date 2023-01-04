
typedef struct node{

	int data;
	struct node* left;
	struct node* right;
}node;

typedef node* bst;


bst constructTree(int A[], int s, int n);

void insert(bst* t,int key);

node* createNode(int key);

void initBst(bst* t);

void inorder(bst t);

void preorder(bst t);

void postorder(bst t);

