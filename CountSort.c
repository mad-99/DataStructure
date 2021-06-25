#include<stdio.h>
#include<stdlib.h>
#define MAX 8
void readArray(int [],int);
void outputArray(int [],int);
void countSort(int[],int [] ,int);
void main(){
	int a[MAX],b[MAX]={0};
	readArray(a,MAX);
	countSort(a,b,9);
	outputArray(b,MAX);

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
void countSort(int a[],int b[],int k){
	int i,j,c[10];
	for(i=0;i<=k;i++){
		c[i]=0;
	}
	for(j=1;j<=MAX;j++){
		c[a[j]] = c[a[j]]+1;
	}
	
	for(i=1;i<=k;i++){
		c[i]=c[i]+c[i-1];
	}
	for(j=MAX;j>=1;j--){
		b[c[a[j]]] = a[j];
		c[a[j]]=c[a[j]]-1;
	}
}