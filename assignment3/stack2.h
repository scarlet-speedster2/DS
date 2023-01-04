
typedef struct s2{

	char c;

	struct s2* next;
}s2;


typedef s2* stackO;

void init2(stackO* s);

char peek2(stackO s);

char pop2(stackO* s);

void push2(stackO* s,char t);

int isEmpty2(stackO s);

