#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct linkedlist{
	int info;
	struct linkedlist *next;
}node;
void create_linkedlist(node **);
void insert_at_begining(node **,int);
void insert_at_end(node **,int);
void insert_after_element(node *,int);
void insert_at_any_position(node *,int);
void traversing(node *);
void searching(node *,int);
void delete_from_begining(node **);
void delete_from_end(node **);
void delete_after_element(node **,int);
void delete_from_any_position(node **,int);
void delete_specific_element(node **,int);
void main(){
	int ch,sear;
	//char choice;
	node *head;
	int data,item,position;
	create_linkedlist(&head);
	while(1){
		printf("\n1. insert at begining");
		printf("\n2. insert at end");
		printf("\n3. insert after element");
		printf("\n4. insert at any position");
		printf("\n5. traversing");
		printf("\n6. searching");
		//printf("\n7.traversing in reverse order");
		printf("\n8. delete from begining");
		printf("\n9. delete from end");
		printf("\n10. delete after element");
		printf("\n11. delete element from specific position");
		printf("\n12. delete specific element");
		//printf("\n13. reverse linked list");
		printf("\n14. exit");
		printf("\nenter your choice.....");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter value to be insert :");
				scanf("%d",&data);
				insert_at_begining(&head,data);
				break;
			case 2:
				printf("enter value to be insert :");
				scanf("%d",&data);
				insert_at_end(&head,data);
				break;
			case 3:
				printf("enter the value after which you want to insert :");
				scanf("%d",&item);
				insert_after_element(head,item);
				break;
			case 4:
				printf("enter the position after which you want to insert :");
				scanf("%d",&position);
				insert_at_any_position(head,position);

				break;
			case 5:
				traversing(head);
				break;
			case 6:
				printf("enter the value");
				scanf("%d",&sear);
				searching(head,sear);
				break;
			case 7: break;
			case 8: 
				delete_from_begining(&head);
				break;
			case 9:
				delete_from_end(&head);
				break;
			case 10:
				printf("enter the iteam after which element to be delete.....");
				scanf("%d",&item);
				delete_after_element(&head,item);
				break;
			case 11:
				printf("enter the position  after which element to be delete.....");
				scanf("%d",&position);
				delete_from_any_position(&head,position);
				break;
			case 12: 
				printf("enter the element to be delete......");
				scanf("%d",&item);
				delete_specific_element(&head,item);
				break;
			case 14:
				exit(0);
			default :
				printf("you have entered wrong choice:");
		}

	}

}
void create_linkedlist(node **HEAD){
	*HEAD = NULL;
}
void insert_at_begining(node **HEAD,int data){
	node *loc;
	loc=(node *)malloc(sizeof(node));
	loc->info=data;
	loc->next=NULL;
	if(*HEAD==NULL){
		*HEAD=loc;
	}
	else{
		loc->next = *HEAD;
		*HEAD=loc;
	}
}
void traversing(node *loc){
	if(loc == NULL){
		printf("\n list is empty");
	}
	else{
		while(loc != NULL){
			printf("%d ->",loc->info);
			loc = loc->next;
		}
	}
}
void insert_at_end(node **HEAD,int data){
	node *loc,*locNext;
	loc=(node *)malloc(sizeof(node));
	loc->next = NULL;
	loc->info = data;
	if(*HEAD==NULL){
		*HEAD=loc;
	}
	else{
		locNext=*HEAD;
		while(locNext->next != NULL){
			locNext=locNext->next;
		}
		locNext->next=loc;
	}
	
}
void searching(node *loc,int sear){
	int count=0;
	while(loc!=NULL){
		count++;
		if(loc->info == sear){
			break;
		}
		loc=loc->next;
	}
	if(loc==NULL){
		printf("item not found");
	}
	else{
		printf("item found at %p address",loc->next);
		printf("\nindex value of item %d",count);
	}
}
void insert_after_element(node *loc,int item){
	int data;
	node *newnode;
	printf("enter the data.....");
	scanf("%d",&data);
	while(loc != NULL){
		if(loc->info == item){
			break;
		}
		loc=loc->next;
	}
	if(loc ==NULL){
		printf("item not found");
	}
	else{
		newnode = (node *)malloc(sizeof(node));
		newnode->info = data;
		newnode->next = loc->next;
		loc->next=newnode;
		printf("data insert succesfully\n"); 
	}
}
void insert_at_any_position(node *loc,int position){
	int count=0,data;
	node *newnode;
	printf("enter the data.....");
	scanf("%d",&data);
	while(loc != NULL){
		if(count == position-1){
			break;
		}
		else{
			count++;
			loc=loc->next;
		}
	}
	if(loc ==NULL){
		printf("position not found");
	}
	else{
		newnode = (node *)malloc(sizeof(node));
		newnode->info = data;
		newnode->next = loc->next;
		loc->next=newnode; 
		printf("data insert succesfully\n");
	}
}
void delete_from_begining(node **HEAD){
	node *loc;
	loc=*HEAD;
	if(loc == NULL){
		printf("list is empty");
	}
	else{
		*HEAD=(*HEAD)->next;
		free(loc);
		printf("delete succesfully");
	}
}
void delete_from_end(node **HEAD){
	node *loc;
	loc = *HEAD;
	if(loc ==NULL){
		printf("list is empty");
	}
	else if(loc->next == NULL){
		*HEAD = NULL;
		free(loc);
		printf("delete succesfully");
	}
	else{
		while((loc->next)->next != NULL){
			loc = loc->next;
		}
		node *temp;
		temp = loc->next;
		loc->next = NULL;
		free(temp);
		printf("delete succesfully");
	}
}
void delete_after_element(node **HEAD,int item){
	node *loc,*temp;
	loc = *HEAD;
	while(loc != NULL){
		if(loc->info == item){
			break;
		}
		loc=loc->next;
	}
	if(loc->next == NULL){
		printf("element not found");
	}
	else{
		temp=loc->next;
		loc->next=temp->next;
		free(temp);
	}
}
void delete_specific_element(node **HEAD,int item){
	node *loc,*bfoot,*temp;
	loc = *HEAD;
	bfoot= NULL;
	while(loc != NULL){
		if(loc->info == item){
			break;
		}
		bfoot = loc;
		loc = loc->next;
	}
	if(*HEAD==loc){
		*HEAD=(*HEAD)->next;
		free(loc);
	}
	else if(loc == NULL){
		printf("element not found");
	}
	else{
		bfoot->next = loc->next;
		free(loc);
	}
}
void delete_from_any_position(node **HEAD,int position){
	int count=0;
	node *loc,*bfoot,*temp;
	loc = *HEAD;
	bfoot= NULL;
	while(loc != NULL){
		if(position == count){
			break;
		}
		bfoot=loc;
		loc=loc->next;
		count++;
	}
	if(*HEAD == loc){
		*HEAD=(*HEAD)->next;
		free(loc);
		printf("element deleted");
	}
	else if(loc == NULL){
		printf("element not found");
	}
	else{
		bfoot->next = loc->next;
		free(loc);
		printf("element deleted");
	}
}