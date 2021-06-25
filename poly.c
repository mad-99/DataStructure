#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct polynomial{
	int coeff;
	int power;
	struct polynomial *next;
}poly;
void create_linkedlist(poly **,poly **,poly**,poly **);
void insert_at_begining(poly **,int,int);
void addition(poly *,poly *,poly **);
void Multiplication(poly *,poly *,poly **);
void after_multplication_add(poly *);
void traversing(poly *);
void main(){
	int n,n1,n2,c,p;
	poly *head1,*head2,*head3,*head4;
	create_linkedlist(&head1,&head2,&head3,&head4);
	printf("how many element you want in polynomial1.......");
	scanf("%d",&n1);
	n=1;
	while(n<=n1){
		printf("enter the coeff and power of term %d.......",n);
		scanf("%d %d",&c,&p);
		insert_at_begining(&head1,c,p);
		n++;
	}
	printf("how many element you want in polynomial2.......");
	scanf("%d",&n2);
	n=1;
	while(n<=n2){
		printf("enter the coeff and power of term %d.......",n);
		scanf("%d %d",&c,&p);
		insert_at_begining(&head2,c,p);
		n++;
	}
	
	
	printf("first polynomial.........");
	traversing(head1);
	printf("\nsecond polynomial.........");
	traversing(head2);
	printf("\n.........\n");
	addition(head1,head2,&head3);
	printf("addition.....\n");
	traversing(head3);
	Multiplication(head1,head2,&head4);
	printf("\nMultiplication.............");
	after_multplication_add(head4);
	printf("..........................");
	traversing(head4);
	
}
void create_linkedlist(poly **HEAD1,poly **HEAD2,poly **HEAD3,poly **HEAD4){
	*HEAD1=*HEAD2=*HEAD3=*HEAD4=NULL;
}
void insert_at_begining(poly **HEAD,int c,int p){
	poly *loc;
	loc=(poly *)malloc(sizeof(poly));
	loc->coeff=c;
	loc->power=p;
	loc->next=NULL;
	if(*HEAD==NULL){
		*HEAD=loc;
	}
	else{
		loc->next = *HEAD;
		*HEAD=loc;
	}
}
void addition(poly *HEAD1,poly *HEAD2,poly **HEAD3){
	poly *loc1,*loc2;
	int sum,flag=0;
	loc1=HEAD1;
	while(loc1!=NULL){
		loc2=HEAD2;
		flag=0;
		while(loc2!=NULL){
			if(loc1->power==loc2->power){
				sum = (loc1->coeff)+(loc2->coeff);
				insert_at_begining(HEAD3,sum,loc1->power);
				flag=1;
				break;
			}
			loc2=loc2->next;
		}
		if(flag==0){
			insert_at_begining(HEAD3,loc1->coeff,loc1->power);
		}
		loc1=loc1->next;
	}
	loc2=HEAD2;
	while(loc2!=NULL){
		loc1=HEAD1;
		flag=0;
		while(loc1!=NULL){
			if(loc1->power==loc2->power){
				flag=1;
				break;
			}
			loc1=loc1->next;
		}
		if(flag==0){
			insert_at_begining(HEAD3,loc2->coeff,loc2->power);
		}
		loc2=loc2->next;
	}
	
}
void Multiplication(poly *HEAD1,poly *HEAD2,poly **HEAD4){
	poly *loc1,*loc2;
	int sum,flag=0;
	loc1=HEAD1;
	while(loc1!=NULL){
		loc2=HEAD2;
		flag=0;
		while(loc2!=NULL){
			insert_at_begining(HEAD4,((loc1->coeff)*(loc2->coeff)),((loc1->power)+(loc2->power)));
			loc2=loc2->next;
		}
		loc1=loc1->next;
	}
}

void traversing(poly *loc){
	if(loc == NULL){
		printf("\n list is empty");
	}
	else{
		while(loc != NULL){
			printf("%dX^%d + ",loc->coeff,loc->power);
			loc = loc->next;
		}
	}
}
void after_multplication_add(poly *HEAD4){
	poly *ptr1,*ptr2,*ptr;
    ptr=HEAD4;
    while(ptr!=NULL)
    {
        ptr1=ptr;
        ptr2=ptr->next;
        while(ptr2!=NULL)
        {
            if(ptr->power==ptr2->power)
            {
                ptr->coeff=ptr->coeff+ptr2->coeff;
                ptr1->next=ptr2->next;
                free(ptr2);
            }
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        ptr=ptr->next;
    }
}
//Multiplication.............4X^3 + 4X^2 + 4X^2 + 4X^1 +