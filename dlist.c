#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct dlinkedlist{
	struct dlinkedlist *pre;
	int info;
	struct dlinkedlist *next;
}node;
void create_dlinkedlist(node **,node **);
void insert_at_begining(node **,node **,int);
void insert_at_end(node **,node**,int);
void insert_after_element(node *,node **,int);
void insert_before_element(node **,node *,int);
void delete_from_begning(node **,node **);
void delete_from_end(node **,node **);
void delete_after_element(node**,node**,int);
void delete_before_element(node**,node**,int);
void traversing_from_begining(node *);
void traversing_from_end(node *);
int main(){
	node *head,*tail;
	int ch,data,element;
	create_dlinkedlist(&head,&tail);
	while(1){
		printf("\n1.insert at begining");
		printf("\n2.insert at end");
		printf("\n3.insert after element");
		printf("\n4.insert before element");
		printf("\n5. delete from begining");
		printf("\n6. delete from end");
		printf("\n7. delete after element");
		printf("\n8. delete before element");
		printf("\n9.traversing from begining");
		printf("\n10.traversing from end");
		printf("\n11.exit");
		printf("\nenter your choice......");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("enter the data.....");
					scanf("%d",&data);
					insert_at_begining(&head,&tail,data);
					break;
			case 2: printf("enter the data.....");
					scanf("%d",&data);
					insert_at_end(&head,&tail,data);
					break;
			case 3: printf("enter the element after which you want to insert data......");
					scanf("%d",&element);
					insert_after_element(head,&tail,element);
					break;
			case 4: printf("enter the element before which you want to insert data......");
					scanf("%d",&element);
					insert_before_element(&head,tail,element);
					break;
			case 5: delete_from_begning(&head,&tail);
					break;
			case 6:	delete_from_end(&head,&tail);
					break;
			case 7: printf("enter the element after which you want to delete data.....");
					scanf("%d",&element);
					delete_after_element(&head,&tail,element);
					break;
			case 8: printf("enter the element after which you want to delete data.....");
					scanf("%d",&element);
					delete_before_element(&head,&tail,element);
					break;
			case 9: traversing_from_begining(head);
					break;
			case 10: traversing_from_end(tail);
					break;
			case 11: exit(0);
			default : printf("you have entered wrong choice");
		}
	}
}
void create_dlinkedlist(node **HEAD,node **TAIL){
	*HEAD=NULL;
	*TAIL=NULL;
}
void insert_at_begining(node **HEAD,node **TAIL,int data){
	node *N;
	N = (node *)malloc(sizeof(node));
	N->next=NULL;
	N->pre=NULL;
	N->info=data;
	if(*HEAD==NULL){
		*HEAD = N;
		*TAIL = N;
	}
	else{
		N->next=*HEAD;
		(*HEAD)->pre = N;
		*HEAD=N;
	}
}
void insert_at_end(node **HEAD,node **TAIL,int data){
	node *E;
	E = (node *)malloc(sizeof(node));
	E->next=NULL;
	E->pre=NULL;
	E->info=data;
	if(*HEAD==NULL){
		*HEAD = E;
		*TAIL = E;
	}
	else{
		(*TAIL)->next=E;
		E->pre=*TAIL;
		*TAIL=E;
	}
}
void insert_after_element(node *HEAD,node **TAIL,int element){
	int data;
	node *loc,*ptr;
	loc = HEAD;
	printf("enter the data......");
	scanf("%d",&data);
	while(loc !=NULL){
		if(loc->info == element){
			break;
		}
		loc=loc->next;
	}
	if(loc != NULL){
		ptr=(node *)malloc(sizeof(node));
		ptr->info=data;
		if(loc->next!=NULL){
			ptr->next = loc->next;
			ptr->pre=loc;
			(loc->next)->pre=ptr;
			loc->next=ptr;
		}
		else{
			ptr->pre =loc;
			ptr->next = NULL;
			loc->next = ptr;
			*TAIL=ptr;
		}

	}
	else{
		printf("element not found");
	}

}
void insert_before_element(node **HEAD,node *TAIL,int element){
	int data;
	node *loc,*ptr;
	loc = *HEAD;
	printf("enter the data......");
	scanf("%d",&data);
	while(loc != NULL){
		if(loc->info==element){
			break;
		}
		loc=loc->next;
	}
	if(loc!=NULL){
		ptr=(node *)malloc(sizeof(node));
		ptr->info=data;
		if(loc->pre != NULL){
			ptr->pre = loc->pre;
			ptr->next = loc;
			(loc->pre)->next = ptr;
			loc->pre = ptr;
		}
		else{
			ptr->pre = NULL;
			ptr->next=*HEAD;
			loc->pre = ptr;
			*HEAD = ptr;
		}
	}
	else{
		printf("element not found");
	}
}
void delete_from_begning(node **HEAD,node **TAIL){
	node *loc,*temp;
	if(*HEAD==NULL){
		printf("list is empty");
	}
	else if(*HEAD == *TAIL){
		free(*HEAD);
		*HEAD=*TAIL=NULL;
	}
	else{
		loc=*HEAD;
		temp=(*HEAD)->next;
		free(loc);
		temp->pre = NULL;
		*HEAD=temp;
	}
}
void delete_from_end(node **HEAD,node **TAIL){
	node *loc,*temp;
	if(*HEAD==NULL){
		printf("list is empty");
	}
	else if(*HEAD == *TAIL){
		free(*HEAD);
		*HEAD=*TAIL=NULL;
	}
	else{
		loc = *TAIL;
		temp = loc->pre;
		*TAIL = temp;
		temp->next = NULL;
		free(loc);
	}
}
void delete_after_element(node **HEAD,node **TAIL,int element){
	node *temp,*loc;
	loc = *HEAD;
	while(loc != NULL){
		if(loc->info == element){
			break;
		}
		loc=loc->next;
	}
	if(loc == NULL){
		printf("element not found");
	}
	else{
		if(loc->next == NULL){
			printf("no next node is available");
		}
		else if((loc->next)->next == NULL){
			temp=loc->next;
			loc->next = NULL;
			*TAIL = loc;
			free(temp);
		}
		else{
			temp = loc->next;
			(temp->next)->pre = loc;
			loc->next = temp->next;
			free(temp);
		}
	}
}
void delete_before_element(node **HEAD,node **TAIL,int element){
	node *temp,*loc;
	loc = *HEAD;
	while(loc != NULL){
		if(loc->info == element){
			break;
		}
		loc=loc->next;
	}
	if(loc == NULL){
		printf("element not found");
	}
	else{
		if(loc->pre == NULL){
			printf("no previous node is available");
		}
		else if((loc->pre)->pre == NULL){
			temp=loc->pre;
			loc->pre = NULL;
			*HEAD = loc;
			free(temp);
		}
		else{
			temp = loc->pre;
			(temp->pre)->next = loc;
			loc->pre = temp->pre;
			free(temp);
		}
	}
}
void traversing_from_begining(node *HEAD){
	while(HEAD!=NULL){
		printf("%d->",HEAD->info);
		HEAD=HEAD->next;
	}
}
void traversing_from_end(node *TAIL){
	while(TAIL != NULL){
		printf("%d->",TAIL->info);
		TAIL=TAIL->pre;
	}
}