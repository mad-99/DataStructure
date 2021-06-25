#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int Heap_s = MAX;
void BMHeap(int [],int);
void heapS(int [],int);
void Mheapify(int [],int);
void readArray(int [],int);
void outputArray(int [],int);
void swap(int * ,int *);
int main(){
	int a[MAX];
	readArray(a,MAX);
	heapS(a,MAX);
	outputArray(a,MAX);
}

void readArray(int a[],int size){
	int i;
	for(i=1;i<=size;i++){
		scanf("%d",&a[i]);
	}
}
void outputArray(int a[],int size){
	int i;
	for(i=1;i<=size;i++){
		printf("%d ",a[i]);
	}
}
void BMHeap(int a[],int size){
	int i;
	for(i=size/2;i>=1;i--){
		Mheapify(a,i);
	}
}
void Mheapify(int a[],int i){
	int l,r,largest;
	l=2*i;
	r=2*i+1;
	if(l<=Heap_s && a[l]>a[i]){
		largest = l;
	}
	else{
		largest = i;
	}
	if(r<=Heap_s && a[r]>a[largest]){
		largest=r;
	}
	if (largest!=i)
	{
		swap(&a[i],&a[largest]);
		Mheapify(a,largest);
	}
}
void heapS(int a[],int size){
	int i;
	BMHeap(a,size);
	for(i=size;i>=2;i--){
		swap(&a[1],&a[i]);
		Heap_s=Heap_s-1;
		Mheapify(a,1);
	}

}
void swap(int *ele1,int *ele2){
	int temp;
	temp = *ele1;
	*ele1=*ele2;
	*ele2=temp;
}