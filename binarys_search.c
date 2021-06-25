#include<stdio.h>
int binary_search(int [],int ,int);
int main(){
	int a[1000]={0};
	int n,item,i,search,ch;
	printf("how many element you want in your array...............");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	item = binary_search(a,n,search);
	if(item==-1){
		printf("element not found");
	}else{
		printf("your element found at %d index",item);
	}
}