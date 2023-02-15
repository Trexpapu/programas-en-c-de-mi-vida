#include<stdio.h>

void print(int A[], int N){
	for(int i=0; i<N; i++){
		printf("%d\n", A[i]);
	}
}

void swap(int A[], int i, int j){
	int aux=A[i];
	A[i]=A[j];
	A[j]=aux;
}

void selection_sort(int A[], int n){
	int j;
	for(int i=1; i<n; i++){
		j=i;
		while(A[j-1]>A[j] &&j>0){
			swap(A, j, j-1);
			j--;
		}
	}
}
int main(){
	int N;
	scanf("%d", &N);
	int A[N];
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);

	}
	selection_sort(A,N);
	print(A,N);
}