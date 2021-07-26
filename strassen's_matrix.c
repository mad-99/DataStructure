#include<stdio.h>
void inputmat(int [2][2]);
void outputmat(int [2][2]);
void mulmat(int [2][2],int [2][2],int [2][2]);
void main(){
	int a[2][2],b[2][2],c[2][2];
	printf("enter the element of matrix 1.............\n");
	inputmat(a);
	printf("enter the element of matrix 2.............\n");
	inputmat(b);
	mulmat(a,b,c);
	printf("multipilcation of matrix....................\n");
	outputmat(c);
}
void inputmat(int m[2][2]){
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			scanf("%d",&m[i][j]);
		}
	}
}
void outputmat(int m[2][2]){
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d ",m[i][j]);
		}
	printf("\n");
	}
}
void mulmat(int m[2][2],int n[2][2],int m1[2][2]){
	int p1,p2,p3,p4,p5,p6,p7;
	p1=m[0][0]*(n[0][1]-n[1][1]);
	p2=(m[0][0]+m[0][1])*n[1][1];
	p3=(m[1][0]+m[1][1])*n[0][0];
	p4=m[1][1]*(n[1][0]-n[0][0]);
	p5=(m[0][0]+m[1][1])*(n[0][0]+n[1][1]);
	p6=(m[0][1]-m[1][1])*(n[1][0]+n[1][1]);
	p7=(m[0][0]-m[1][0])*(n[0][0]+n[0][1]);
	m1[0][0]=p5+p4-p2+p6;
	m1[0][1]=p1+p2;
	m1[1][0]=p3+p4;
	m1[1][1]=p1+p5-p3-p7;
}
