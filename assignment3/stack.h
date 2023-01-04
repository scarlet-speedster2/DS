
typedef struct s1{

	node* n;
	struct s1* next;
}s1;

typedef s1* stackN;

void init1(stackN* s);

node* peek1(stackN s);

node* pop1(stackN* s);

void push1(stackN* s,node** t);

int isEmpty1(stackN s);








