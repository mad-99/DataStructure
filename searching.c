#include<stdio.h>
#include<stdlib.h>
int linear_search(int [],int,int);
int binary_search(int [],int,int);
int main(){
	int a[1000]={0};
	int n,item,i,search,ch;
	printf("how many element you want in your array...............");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(1){
		printf("\nenter the element you want to search...............");
		scanf("%d",&search);
		printf("\n...............................\n");
		printf("1. linear_search\n");
		printf("2. binary_search\n");
		printf("3. exit\n");
		printf(".............................\n");
		printf("enter your choice..........");
		scanf("%d",&ch);
		switch(ch){
		case 1: item = linear_search(a,n,search);
			if(item==-1){
				printf("element not found");
			}else{
				printf("your element found at %d index",item);
			}
			break;
		case 2:item = binary_search(a,n,search);
			if(item==-1){
				printf("element not found");
			}else{
				printf("your element found at %d index",item);
			}
			break;
		case 3: exit(0);
		default:printf("you enter the wrong choice");
		}
	}
}
int linear_search(int a[],int right,int search){
	int i;
	for(i=0;i<right;i++){
		if(search==a[i]){
			return i;
		}
	}
	return -1;
}
int binary_search(int a[],int right,int search){
	int left=0,mid=0;
	while(left<=right){
		mid = (left+right)/2;
		if(a[mid]==search){
			return mid;
		}
		else if(search<a[mid]){
			right=mid-1;
		}
		else if(search>a[mid]){
			left = mid+1;
		}
	}
	return -1;
}