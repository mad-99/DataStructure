#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
#define NILL -1
typedef struct Queue_array{
	int Que[MAX];
	int front;
	int rear;
}Queue;
int isfull(Queue *);
int isempty(Queue*);
void enqueue(Queue *,int);
int dequeue(Queue *);
void main(){
	Queue Q ;
	Q.front = Q.rear = NILL;
	int ch,item,val;
	while(1){
		printf("\n.....................................");
		printf("\n1. Insert in Queue");
		printf("\n2. delete from the Queue");
		printf("\n3. exit");
		printf("\n.....................................");
		printf("\n enter your choice...........");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			if(isfull(&Q)){
				printf("Queue is full");
			}
			else{
				printf("enter the value...........");
				scanf("%d",&item);
				enqueue(&Q,item);
			}
			break;
			case 2: 
			if(isempty(&Q)){
				printf("Queue is empty");
			}
			else{
				val=dequeue(&Q);
				printf("\nthe delete element is.......%d ",val);
			}
			break;
			case 3:
			exit(0);
			default:
			printf("you enter the wrong choice");
		}
	}
}

int isfull(Queue *Q){
	if(Q->front==0 && Q->rear==MAX-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isempty(Queue *Q){
	if (Q->front==NILL)
	{
		return 1;
	}
	else{
		return 0;
	}
}
void enqueue(Queue *Q,int item){
	int i;
	if(Q->front==NILL){
		Q->front=Q->rear=0;
	}
	else if(Q->rear==MAX-1){
		for(i=Q->front;i<=Q->rear;i++){
			Q->Que[i-Q->front]=Q->Que[i];
		}
		Q->rear=Q->rear-Q->front;
		Q->front=0;
		Q->rear=Q->rear+1;
	}
	else{
		Q->rear=Q->rear+1;
	}
	Q->Que[Q->rear]=item;
}
int dequeue(Queue *Q){
	int item;
	item=Q->Que[Q->front];
	if(Q->front==Q->rear){
		Q->front = Q->rear = NILL;
	}
	else{
		Q->front=Q->front+1;
	}
	return item;
}