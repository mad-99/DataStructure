#include<stdio.h>
#define MAX 7
void Merge(int [],int ,int,int);
void MergeSort(int[],int,int);
void readArray(int [],int);
void outputArray(int [],int);
int main(){
	int a[MAX];
	printf("enter the values for sorting...............\n");
	readArray(a,MAX);
	MergeSort(a,1,MAX);
	printf("array after sort..............\n");
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
void Merge(int a[],int p,int q,int r){
	int n1,n2,i,j,k;
	n1=q-p+1;
	n2=r-q;
	int L[n1+1],R[n2+1];
	for(i=1;i<=n1;i++){
		L[i]=a[p+i-1];
	}
	for(j=1;j<=n2;j++){
		R[j]=a[q+j];
	}
	L[n1+1]=999;
	R[n2+1]=999;
	i=1;
	j=1;
	for(k=p;k<=r;k++){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
	}
}
void MergeSort(int a[],int p,int r){
	int q;
	if(p<r){
		q=(p+r)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
}
//madhur