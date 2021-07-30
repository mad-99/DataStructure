#include<stdio.h>
void inputmatrix(int [][10],int,int);
void outputmatrix(int [][10],int,int);
void tranmatrix(int [][10],int);
void main(){
int mat1[10][10],row,col;
	printf("enter the value of row...");
	scanf("%d",&row);//reading the row value
	printf("enter the value of col...");
	scanf("%d",&col);// reading the coloumn value
	printf("enter the first matrix \n");
	inputmatrix(mat1,row,col);//Reading matrix value
	tranmatrix(mat1,row,col);
	printf("transpose of matrix\n");
	outputmatrix(mat1,row);	
}
void inputmatrix(int x[][10],int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("enter the value %d,%d ",i,j);
			scanf("%d",&x[i][j]);
		}
	}
}
void outputmatrix(int x[][10],int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
}
void tranmatrix(int x[][10],int r){
	int i,j,temp=0;
	for(i=0;i<r;i++){
		for(j=0;j<i;j++){
			if (i!=j)
			{
				temp=x[i][j];
				x[i][j]=x[j][i];
				x[j][i]=temp;
			}
		}
	}
}
