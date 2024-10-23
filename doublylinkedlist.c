//Unnati Dharpure   CS23147
#include<stdio.h>
#include<stdlib.h>

void createdoublylist();
void display();
void insertAtbeg();
void insertAtend();
void insertAtpos();
void insertAfterPos();
struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head,*tail,*newnode,*temp;

void createdoublylist()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL) 
	{
		printf("\nMEMORY NOT ALLOCATED");
		return;
	}
	printf("\nEnter Data: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	if(head == NULL) 
	{
		head = tail = newnode;
	} 
	else
	{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
	}
}
void display()
{
	temp=head;
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void insertAtbeg()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMEMORY NOT ALLOCATED");
		return;
	}
	else
	{
		printf("\nEnter Data:");
		scanf("%d",&newnode->data);
		head->prev=newnode;
		newnode->next=head;
		newnode->prev=NULL;
		head=newnode;
	}
}
void insertAtend()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMEMORY NOT ALLOCATED");
		return;
	}
	else
	{
		printf("\nEnter Data:");
		scanf("%d",&newnode->data);
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
		tail->next=NULL;
	}
}
void insertAtpos()
{
	int pos,i=1;
	int length=0;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		length++;
	}
	printf("\nLENGTH=%d",length);
	printf("\nEnter position where you want to insert newnode:");
	scanf("%d",&pos);
	if(pos<1 && pos>length+1)
	{
		printf("INVALID POSITION");
		return;
	}
	else if(pos==1)
	{
		insertAtbeg();
	}
	else
	{
		temp=head;
		printf("\nEnter Data:");
		scanf("%d",&newnode->data);
		while(i<(pos-1))
		{
			temp=temp->next;
			i++;
			newnode->prev=temp;
			newnode->next=temp->next;
			temp->next=newnode;
			temp->next->prev=newnode;
		}
	}
}
void insertAfterPos()
{
	int pos, i = 1;
	temp = head;
	
	printf("\nEnter the position after which to insert: ");
	scanf("%d", &pos);
	
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMEMORY NOT ALLOCATED");
		return;
	}
	
	printf("\nEnter Data: ");
	scanf("%d", &newnode->data);
	
	if(head == NULL) 
	{
		printf("\nList is empty, inserting at the beginning\n");
		head = tail = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
		return;
	}

	while(i < pos && temp != NULL) 
	{
		temp = temp->next;
		i++;
	}
	
	if(temp == NULL) 
	{
		printf("\nPosition out of bounds, inserting at the end instead.\n");
		insertAtend();
		return;
	}
	
	newnode->next = temp->next;
	newnode->prev = temp;
	
	if(temp->next != NULL) 
	{
		temp->next->prev = newnode;
	}
	else 
	{
		tail = newnode; 
	}
	
	temp->next = newnode;
}
int main() 
{
	int ch;
	head = NULL;
	while(1)
	{
		printf("\n1. Create List\n2. Display\n3. Insert At Beg\n4. Insert At End\n5. Insert At Position\n6. Insert After Position\n7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch) 
		{
			case 1:
				createdoublylist();
				break;
			case 2:
				display();
				break;
			case 3:
				insertAtbeg();
				break;
			case 4:
				insertAtend();
				break;
			case 5:
				insertAtpos();
				break;
			case 6:
				insertAfterPos();
				break;
			case 7:
			    printf("Exiting...\n");
				break;
			default:
				printf("\nEnter a Valid Choice\n");	
		}
	}
	return 0;
}
