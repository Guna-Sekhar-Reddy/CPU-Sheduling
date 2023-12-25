//linked list insertion 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}nodet;

nodet *head;
nodet* create(nodet* head)
{
	nodet *temp=head,*temp1;

	while(temp->next)
	{
		temp=temp->next;
	}
	
	temp->next=(nodet*)malloc(sizeof(nodet));
	temp=temp->next;
	scanf("%d",&temp->data);
	temp->next=NULL;
	return head;
}

void traverse(nodet *temp)
{
	while(temp)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}


int main()
{
	int n;
	printf("Enter number of elements u want to enter in linked list\n");
	
	scanf("%d",&n);
	
	head=(nodet*)malloc(sizeof(nodet));
	printf("Enter elements\n");
	scanf("%d",&head->data);
	head->next=NULL;
	
	for(int i=0;i<n-1;i++)
	{
		head=create(head);
	}
	
	printf("Entered list is \n");
	traverse(head);
}
