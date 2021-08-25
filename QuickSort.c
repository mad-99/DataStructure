#include<stdio.h>
#define MAX 7
int Partition(int [],int ,int);
void QuickSort(int[],int,int);
void readArray(int [],int);
void outputArray(int [],int);
void swap(int * ,int *);
int main(){
	int a[MAX];
	printf("enter the values for sorting...............\n");
	readArray(a,MAX);
	QuickSort(a,0,MAX-1);
	printf("array after sort..............\n");
	outputArray(a,MAX);
}

void readArray(int a[],int size){
	int i;
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
}
void outputArray(int a[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
}
void QuickSort(int a[],int LI,int RI){
	int q;
	if(LI<RI){
		q=Partition(a,LI,RI);
		QuickSort(a,LI,q-1);
		QuickSort(a,q+1,RI);
	}
}
int Partition(int a[],int LI,int RI){
	int i=LI-1,j=0;
	int Pivot = a[RI];
	for(j=LI;j<=RI-1;j++){
		if(a[j]<= Pivot){
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[RI]);
	return i+1;
}
void swap(int *elet1,int *elet2){
	int temp;
	temp = *elet1;
	*elet1=*elet2;
	*elet2=temp;
}
