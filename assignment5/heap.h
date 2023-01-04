
typedef struct node{

	int n;
	
	int heap_size;

	int* A;
}node;

typedef node* heap;

void init(heap* t);

void cpFromFile(heap* t,FILE* f,int size);

void maxHeap(heap t,int i);

void buildHeap(heap t);

void heapSort(heap t);

void traverse(heap t);
