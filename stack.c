#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
typedef struct stacktype{
	int s[MAX];
	int top ;
}stack;
void Push(stack *,int);
void traverse(stack *);
void pop(stack *);
void main(){
	int value,ch;
	stack s1;
	s1.top= -1;
	while(1){
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. traverse");
		printf("\n4. exit");
		printf("\n enter your choice...........");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
				printf("enter the value...........");
				scanf("%d",&value);
				Push(&s1,value);
				break;
			case 2: pop(&s1);
				break;
			case 3: traverse(&s1);
				break;
			case 4: exit(0);
			
		}
	}

}
void Push(stack *S,int V){
	if(S->top==MAX-1){
		printf("stack is overflow");
	}
	else{
		S->top=S->top+1;
		S->s[S->top]=V;
	}
}
void traverse(stack *S){
	int i;
	for(i=0;i<=(S->top);i++){
		printf("%d\t",S->s[i]);
	}
}
void pop(stack *S){
	int value;
	if(S->top == -1){
		printf("stack is empty");
	}
	else{
		value=S->top;
		S->top=S->top-1;
	}
}