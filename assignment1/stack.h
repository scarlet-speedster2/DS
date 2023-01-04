
typedef struct stack{

	node* n;
	struct stack* next;
}stack;


node* pop(stack** s);

void push(stack** s,node** temp);

node* peek(stack* s);

int isEmpty(stack* s);

void initStack(stack** s);


