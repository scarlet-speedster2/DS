#include<stdio.h>
#include<stdlib.h>

void Merge(int A[],int p,int q,int r){

	int n1 = (q - p)+1;
	int n2 = r - q;
	int i = 0;
	int j = 0;
	printf("n1 = %d",n1);
	printf("n2 = %d",n2);
	printf("\n");
	
	
	int Left[n1],Right[n2];
	for(i = 0; i<n1;i++){
		Left[i] = A[i];
	}
	for(j = 0; j<n2;j++){
		Left[j] = A[j+q];
	}
	
	int c = 0;
	

	while(i< n1 && j< n2){
		if(Left[i] <= Right[j]){
			A[c] = Left[i];
			i++;
			c++;
		}
		else{
			A[c] = Right[j];
			j++;
			c++;
		}
	}
	while(i<n1){
		A[c] = Left[i];
		i++;
		c++;
	}
	while(j<n2){
		A[c] = Right[j];
		j++;
		c++;
	}
	for(c = 0;c<(n1+n2);c++){
		printf("%d ",A[c]);
	}
	printf("\n");

}


void Merge_sort(int A[], int p,int r){
	
	if(p< r){

	int q = p + (r - p)/2;
	
	Merge_sort(A,p,q);
	Merge_sort(A,q+1,r);
	Merge(A,p,q,r);
	}
}

void main(){

	int Array[] = { 5,6,3,2};
	Merge_sort(Array,0,3);
	int i = 0;
}
