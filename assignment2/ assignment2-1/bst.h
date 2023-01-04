typedef struct node{


	int n; // size of array
	       //
	int A[];  //Array

}node;

typedef node* bst;


void initBST(bst* t);

void insert(bst* t,int key);

void inorder(bst t);

void preorder(bst t);

void postorder(bst t);

int isCompelete(bst t);

