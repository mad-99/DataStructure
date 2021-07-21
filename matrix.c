#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void inputmat(int [10][10],int,int);
void outputmat(int [10][10],int,int);
void mulmat(int [10][10],int[10][10],int [10][10],int,int,int);
void addmat(int [10][10],int [10][10],int [10][10],int,int);
int main(){
	int a[10][10],b[10][10],c[10][10],row1,row2,col1,col2,ch;
	//clrscr();
	printf("enter the row and col for matrix 1......");
	scanf("%d %d",&row1,&col1);
	printf("enter the element of matrix 1.............\n");
	inputmat(a,row1,col1);
	printf("enter the row and col for matrix 2......");
	scanf("%d %d",&row2,&col2);
	printf("enter the element of matrix 2.............\n");
	inputmat(b,row2,col2);
	while(1){
		printf("__________________________");
		printf("\n1.addition");
		printf("\n2.multiplication");
		printf("\n3.exit");
		printf("\nenter your choice....................................");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			if(row1==row2 && col1==col2){
				addmat(a,b,c,row1,col1);
				printf("addition of array.....................\n");
				outputmat(c,row1,col1);
			}
			else{
				printf("addition can not be possible");
			}
			break;
			case 2:
			if(row1==col2){
				mulmat(a,b,c,row1,col1,row2);
				printf("multiplication of array................\n");
				outputmat(c,row1,col1);
			}
			else{
				printf("multiplication can not be possible");
			}
			break;
			case 3: exit(0);
			default:
			printf("you enter wrong choice");
		}
	}
	//getch();
	return 0;
}
void inputmat(int m[10][10],int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&m[i][j]);
		}
	}
}
void outputmat(int m[10][10],int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",m[i][j]);
		}
	printf("\n");
	}
}
void addmat(int m[10][10],int n[10][10],int m1[10][10],int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			m1[i][j]=m[i][j]+n[i][j];
		}
	}
}
void mulmat(int m[10][10],int n[10][10],int m1[10][10],int r,int c,int r1){

	int i,j,k;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			m1[i][j]=0;
			for(k=0;k<r1;k++){
				m1[i][j] += (m[i][j]*n[j][k]);
			}
		}
	}
}