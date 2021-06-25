#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void readArray(int [],int);
void swap(int * ,int *);
void outputArray(int [],int);
void bubblesort(int [],int);
void selectionSort(int [],int);
void insertionSort(int [],int);
int main(){
	int a[MAX],i,ch;
	printf("......enter the array element......\n");
	readArray(a,MAX);
	while(1){
		printf("\n.........MENU............\n");
		printf("\n1.bubble sort");
		printf("\n2.selection sort");
		printf("\n3.insertion sort");
		printf("\n4.exit");
		printf("\nenter your choice............");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			bubblesort(a,MAX);
			printf("array after bubble sort\n");
			outputArray(a,MAX);
			break;
			case 2:
			selectionSort(a,MAX);
			printf("array after selection sort\n");
			outputArray(a,MAX);
			break;
			case 3: 
			insertionSort(a,MAX);
			printf("array after insertion sort\n");
			outputArray(a,MAX);
			break;
			case 4:exit(0);
			default:printf("you enter the wrong choice");
		}
	}
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
void bubblesort(int a[],int size){
	int i,j,temp;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(a[j]>a[j+1]){
				/*temp = a[j];
				a[j]= a[j+1];
				a[j+1]=temp;*/
				swap(&a[j],&a[j+1]);
			}
		}
	}
}
void selectionSort(int a[],int size){
	int i,j,min,minindex,temp;
	for(i=0;i<size-1;i++){
		min=a[i];
		minindex=i;
		for(j=i+1;j<size;j++){
			if(a[j]<min){
				min = a[j];
				minindex=j;
			}
		}
		if(minindex!=i){
			swap(&a[i],&a[minindex]);
		}
	}
}
void insertionSort(int a[],int size){
	int i,j,key;
	for(i=;i<size;i++){
		key =a[i];
		j=i-1;
		while(j>=0 && key<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void swap(int *ele1,int *ele2){
	int temp;
	temp = *ele1;
	*ele1=*ele2;
	*ele2=temp;
}