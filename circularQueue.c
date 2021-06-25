#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
#define NILL -1
typedef struct C_Queue_array{
	int CQue[MAX];
	int front;
	int rear;
}CQueue;
int isfull(CQueue *);
int isempty(CQueue*);
void enqueue(CQueue *,int);
int dequeue(CQueue *);
void main(){
	CQueue Q ;
	Q.front = Q.rear = NILL;
	int ch,item,val;
	while(1){
		printf("\n.....................................");
		printf("\n1. Insert in circular Queue");
		printf("\n2. delete from the circular Queue");
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

int isfull(CQueue *Q){
	if((Q->front==0 && Q->rear==MAX-1) || Q->rear==Q->front-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isempty(CQueue *Q){
	if (Q->front==NILL)
	{
		return 1;
	}
	else{
		return 0;
	}
}
void enqueue(CQueue *Q,int item){
	int i;
	if(Q->front==NILL){
		Q->front=Q->rear=0;
	}
	else if(Q->rear==MAX-1){
		/*for(i=Q->front;i<=Q->rear;i++){
			Q->Que[i-Q->front]=Q->Que[i];
		}
		Q->rear=Q->rear-Q->front;
		Q->front=0;
		Q->rear=Q->rear+1;*/
		Q->rear=0;
	}
	else{
		Q->rear=Q->rear+1;
	}
	Q->CQue[Q->rear]=item;
}
int dequeue(CQueue *Q){
	int item;
	item=Q->CQue[Q->front];
	if(Q->front==Q->rear){
		Q->front = Q->rear = NILL;
	}
	else if(Q->front==MAX-1){
		Q->front=0;
	}
	else{
		Q->front=Q->front+1;
	}
	return item;
}