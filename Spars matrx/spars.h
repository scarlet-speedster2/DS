

typedef struct m{
	int row;
	int col;
	int val;
	struct m* right;
	struct m* down;
}m;
typedef struct node{

	int size;
	m** v;
	m** h;
}node;

typedef node* spars;

void init(spars* s);

void creatematrix(spars* s,char* file);

void printmatrix(spars s);


