#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Queue{
	int info;
	struct Queue *next;
}Que;
void create_Q(Que **,Que **);
void Enqueue(Que **,Que **,int);
int dequeue(Que **);
int isunderflow(Que *);
int main(){
	Que *front,*rear;
	int ch,data=0,element;
	create_Q(&front,&rear);
	while(1){
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.exit");
		printf("\nenter your choice.............");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enqueue the element...............");
					scanf("%d",&element);
					Enqueue(&front,&rear,element);
					break;
			case 2:if(isunderflow(front)){
				printf("Queue is empty");
			}
			else{
				data=dequeue(&front);
				printf("\nthe element that dequeue....%d",data);
			}
			break;
			case 3: exit(0);
			default:printf("you have entered wrong choice");
		}
	}
	return 0;
}
void create_Q(Que **f,Que **r){
	*f=*r=NULL;
}
void Enqueue(Que **front,Que **rear,int data){
	Que *loc,*locNext;
	loc=(Que *)malloc(sizeof(Que));
	loc->next = NULL;
	loc->info = data;
	if(*front==NULL){
		*front=loc;
		*rear=loc;
	}
	else{
		locNext=*rear;
		while(locNext->next != NULL){
			locNext=locNext->next;
		}
		locNext->next=loc;
	}
}
int dequeue(Que **front){
	int item;
	Que *loc;
	loc=*front;
	if(loc == NULL){
		printf("Queue is empty");
	}
	else{
		*front=(*front)->next;
		item= loc->info;
		free(loc);
		printf("delete succesfully");
		return item;
	}
}
int isunderflow(Que *front){
	if(front==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
		