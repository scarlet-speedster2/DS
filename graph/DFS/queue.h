typedef struct node1{

	int d;
	struct node1* next;
}node1;


typedef node1* queue;

void init_queue(queue* q);

void enqueue(queue* q,int d);

int dequeue(queue* q);

int isEmptyq(queue q);

