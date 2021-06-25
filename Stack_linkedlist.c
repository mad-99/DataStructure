#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct stack_linkedlist{
	int info;
	struct stack_linkedlist *next;
}stack;
void create_stack(stack **);
void Push(stack **,int);
int Pop(stack **);
int Peep(stack **);
int underflow(stack *);
void main(){
	stack *Top;
	int item,ch;
	create_stack(&Top);
	while(1){
		printf("\n1.PUSH");
		printf("\n2.Pop");
		printf("\n3.peep");
		printf("\n4.exit");
		printf("\n enter your choice................");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter value to be insert :");
				scanf("%d",&item);
				Push(&Top,item);
				break;
			case 2:if(underflow(Top)){
				printf("stack is empty");
			}
			else{ 
				item = Pop(&Top);
				printf("pop element...............%d",item);
			}
			break;
			case 3: if(underflow(Top)){
				printf("stack is empty");
			}
			else{ 
				item = Peep(&Top);
				printf("peep element...............%d",item);
			}
			break;
			case 4:
			exit(0);
			default :
				printf("you have entered wrong choice:");
		}
	}

	
}
void create_stack(stack **Top){
	*Top = NULL;
}
void Push(stack **Top,int data){
	stack *loc;
	loc=(stack *)malloc(sizeof(stack));
	loc->info=data;
	loc->next=NULL;
	if(*Top==NULL){
		*Top=loc;
	}
	else{
		loc->next = *Top;
		*Top=loc;
	}
}
int underflow(stack *Top){
	if(Top == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
int Pop(stack **Top){
	stack *loc;
	int item;
	loc=*Top;
	item = (*Top)->info;
	*Top = (*Top)->next;
	free(loc);
	return item;
	
}
int Peep(stack **Top){
	int item;
	item = (*Top)->info;
	return item;
}