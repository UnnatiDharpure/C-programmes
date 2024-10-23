//Unnati Dharpure   CS23147
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *newnode, *temp, *head;

void createlist() {
	
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL) {
		printf("\nMEMORY NOT ALLOCATED");
		return;
	}
	printf("\nEnter Data: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	if(head == NULL) {
		head = temp = newnode;
	} else {
		temp->next = newnode;
		temp = newnode;
	}
}

void display() {
	temp = head;
	if(head == NULL) {
		printf("\nList is Empty");
		return;
	}
	while(temp != NULL) {
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void insertAtbeg() {
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL) {
		printf("\nMEMORY NOT ALLOCATED");
		return;
	}
	printf("\nEnter Data: ");
	scanf("%d", &newnode->data);
	newnode->next = head;
	head = newnode;
}

void insertAtend() {
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL) {
		printf("\nMEMORY NOT ALLOCATED");
		return;
	}
	printf("\nEnter Data: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	
	if(head == NULL) {
		head = newnode;
	} else {
		temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

int main() {
	int ch;
	head = NULL;
	
	while(1){
		printf("\n1. Create List\n2. Display\n3. Insert at Beginning\n4. Insert at End\n5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		
		switch(ch) {
			case 1:
				createlist();
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
			    exit(0);
				break;
			default:
				printf("\nEnter a Valid Choice\n");
		}
	} 
	
	return 0;
}
