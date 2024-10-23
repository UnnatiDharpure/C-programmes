//Unnati dharpure  cs23147
#include<stdio.h>
#include<stdlib.h>

void createdoublylist();
void display();
void deleteAtbeg();
void deleteAtend();
void deleteAtpos();
void deleteAfterpos();
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
void deleteAtbeg()
{
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		temp=head;
		if(head->next==NULL)
		{
			head=tail=NULL;
			free(temp);
		}
		else
		{
			head=head->next;
			head->prev=NULL;
			free(temp);
		}
		printf("\nDeleted beg node successfully");
	}
}
void deleteAtend()
{
    if (head == NULL)  
    {
        printf("\nLIST IS EMPTY");
    }
    else
    {
        temp = tail;  
        if (head->next == NULL)  
        {
            head = tail = NULL; 
            free(temp);          
        }
        else
        {
            tail = tail->prev;   
            tail->next = NULL;   
            free(temp);          
        }
        printf("\nDeleted End node successfully");
    }
}
void deleteAtpos()
{
    int pos, i = 1, length = 0;
    if (head == NULL)  
    {
        printf("\nLIST IS EMPTY");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    printf("\nLENGTH = %d", length);
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > length)
    {
        printf("\nInvalid position!");
        return;
    }
    if (pos == 1)
    {
        deleteAtbeg();  
        return;
    }
    else if (pos == length)
    {
        deleteAtend();  
        return;
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp);  
        printf("\nNode deleted successfully at position %d", pos);
    }
}
void deleteAfterpos()
{
    int pos, i = 1, length = 0;
    if (head == NULL)
    {
        printf("\nLIST IS EMPTY");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    printf("\nLENGTH = %d", length);
    printf("\nEnter the position after which to delete: ");
    scanf("%d", &pos); 
    if (pos < 1 || pos >= length)  
    {
        printf("\nInvalid position!");
        return;
    }
    temp = head;
    while (i <= pos)
    {
        temp = temp->next;
        i++;
    }
    struct node *delNode = temp->next;
    if (delNode == NULL)
    {
        printf("\nThere is no node to delete after position %d", pos);
        return;
    }
    temp->next = delNode->next;
    if (delNode->next != NULL)  
    {
        delNode->next->prev = temp;
    }
    else
    {
        tail = temp; 
    }
    free(delNode);
    printf("\nNode deleted successfully after position %d", pos);
}
int main() 
{
	int ch;
	head = NULL;
	while(1)
	{
		printf("\n1. Create List\n2. Display\n3. Delete At Beg\n4. Delete At End\n5. Delete At Position\n6. Delete After Position\n7. Exit\n");
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
				deleteAtbeg();
				break;
			case 4:
				deleteAtend();
				break;
			case 5:
				deleteAtpos();
				break;
			case 6:
				deleteAfterpos();
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
