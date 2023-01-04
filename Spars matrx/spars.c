#include<stdio.h>
#include<stdlib.h>
#include"spars.h"

/*
typedef struct m{
	int row;
	int col;
	int val;
	struct m* right;
	struct m* down;
}m;
typedef struct node{

	m** v;
	m** h;
	int size;
}node;

typedef node* spars;

void init(spars* s);

void creatematrix(spars* s,char* file);

void printmatrix(spars s);
*/

void init(spars* s){

	*s = NULL;
	return;
}

void creatematrix(spars* s,char* file){

	FILE* fptr = fopen(file,"r");
	if(!fptr){
		printf("\nFile opening failed");
		return;
	}
	int ms;
	fscanf(fptr,"%d",&ms);
	spars matrix = (node*) malloc (sizeof(node));
	matrix -> size = ms;
	matrix ->v = malloc(ms* sizeof(m*));
	matrix ->h = malloc(ms* sizeof(m*));
	int num;
	for(int i = 0;i<ms;i++){
		matrix->v[i] = NULL;
		matrix->h[i] = NULL;
	}
	for(int i = 0;i<ms;i++){
		for(int j = 0;j<ms;j++){
			fscanf(fptr,"%d",&num);
			if(num != 0){
				m* nn = (m*) malloc (sizeof(m));
				nn->row = i;
				nn->col = j;
				nn ->val= num;
				nn -> right = NULL;
				nn -> down = NULL;
				if(matrix->v[i] == NULL){
					matrix->v[i] = nn;
				}
				else{
					m* temp;
					m* f;

					temp = matrix ->v[i];
					f = matrix ->v[i];
					while(temp != NULL){
						f = temp;
						temp = temp -> right;
					}
					f -> right = nn;
				}
				if(matrix->h[j] == NULL){
					matrix->h[j] = nn;
				}
				else{
					m* temp;
					m* f;
					temp =  matrix ->h[j];
					while(temp != NULL){
						f = temp;
						temp = temp -> down;
					}
					f -> down = nn;
				}
			}
		}
	}
	*s = matrix;
}

void printmatrix(spars s){
	printf("\nsize = %d",s->size);

	m* ver;
	m* hor;
	for(int i = 0;i<s->size;i++){
		ver = s->v[i];
	while(ver != NULL){
		printf("\n%d %d %d",ver->row,ver->col,ver->val);
		printf("\t");
		ver = ver->right;
	}
	}
	printf("\n Horizontaly");
	for(int j =0;j<s->size;j++){
		hor = s->h[j];
	while(hor!= NULL){
		printf("\n%d %d %d",hor->row,hor->col,hor->val);
		printf("\t");
		hor= hor->down;
	}
	}

}


