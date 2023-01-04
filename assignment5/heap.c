#include<stdlib.h>
#include<stdio.h>
#include"heap.h"


/*typedef struct node{

	int n;
	
	int heap_size;

	int* A;
}node;

typedef node* heap;
*/

void init(heap* t){
	
	*t = NULL;
}

void cpFromFile(heap* t,FILE* f,int size){

	node* temp;
	temp = (node*) malloc (sizeof(node));

	temp -> A = (int*) malloc (size * (sizeof(int)));
	temp -> n = size;
	temp -> heap_size = --size;
	int i = 0;
	int c = 0;
	if(size == 200000){
		while(getw(f) != EOF){
			temp ->A[i]= getw(f);
			i++;
		}
	}
	else
	{
		while(getw(f) != EOF){
			temp ->A[i]= getw(f);
			i++;
			c++;
			if(c == size)
				break;
		}
	}
	(*t) = temp;
	
	return;
}

void traverse(heap t){

	if(!t)
		return;

	for(int i = 0 ;i< t->n;i++){
		printf("%d\n ",t -> A[i]);
	}
}
	

void maxHeap(heap t,int i){
	
	int l = (2*i) + 1;
	int r = (2*i) + 2;
	int largest;
	if(l <= t -> heap_size && t -> A[i] < t -> A[l])
		largest = l;
	else
		largest = i;
	if(r <= t -> heap_size && t -> A[r] > t -> A[largest])
		largest = r;

	if( i != largest){
		t->A[i] += t->A[largest];
		t->A[largest] = t->A[i] - t->A[largest];
		t->A[i] = t -> A[i] - t -> A[largest];
		maxHeap(t,largest);
	}

}

void buildHeap(heap t) {
	
	for(int i = ((t->n)/2) - 1; i>= 0; i--){
		maxHeap(t,i);
	}
}

void heapSort(heap t){
	
	buildHeap(t);

	for(int i = (t-> n) -1; i > 0 ;i --){
		t -> A[0] += t -> A[i];
		t -> A[i] = t -> A[0] - t -> A[i];
		t -> A[0] = t -> A[0] - t -> A[i];
		t -> heap_size = t -> heap_size - 1; 
		maxHeap(t,0);
	}

}
