
typedef struct ss{

	int* a;
	int top;
	int size;
}ss;

typedef ss* stack;

void init_stack(stack* s);

void push(stack* s,int d);

int pop(stack* s);

int peek(stack s);

int isEmpty(stack s);
