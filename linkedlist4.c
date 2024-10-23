#include<stdio.h>
#include<stdlib.h>

void createlist();
void display();
void InsertAftPos();
void DeleteAtPos();

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;

void createlist() {
	struct node newnode = (struct node*)malloc(sizeof(struct node));
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
		struct node *temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void display() {
	if(head == NULL) {
		printf("\nList is Empty\n");
		return;
	}
	struct node *temp = head;
	while(temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void InsertAftPos() {
	int pos, i = 1, length = 0;
	struct node newnode = (struct node)malloc(sizeof(struct node));
	if(newnode == NULL) {
		printf("\nMEMORY NOT ALLOCATED");
		return;
	}

	struct node *temp = head;
	while(temp != NULL) {
		temp = temp->next;
		length++;
	}

	printf("\nLENGTH = %d", length);
	printf("\nEnter position after which you want to insert the new node: ");
	scanf("%d", &pos);

	if(pos > length || pos < 1) {
		printf("\nINVALID POSITION\n");
		free(newnode);
		return;
	}

	printf("\nEnter data: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;

	temp = head;
	for(i = 1; i < pos; i++) {
		temp = temp->next;
	}

	newnode->next = temp->next;
	temp->next = newnode;

	printf("\nNode inserted successfully\n");
}

void DeleteAtPos() {
	int pos, i = 1, length = 0;
	struct node *temp = head;
	struct node *nextnode = NULL;

	while(temp != NULL) {
		temp = temp->next;
		length++;
	}

	if(head == NULL) {
		printf("\nList is Empty\n");
		return;
	}

	printf("\nLENGTH = %d", length);
	printf("\nEnter position of the node you want to delete: ");
	scanf("%d", &pos);

	if(pos > length || pos < 1) {
		printf("\nINVALID POSITION\n");
		return;
	}

	temp = head;

	if(pos == 1) {
		head = head->next;
		free(temp);
		printf("\nNode deleted successfully\n");
		return;
	}

	for(i = 1; i < pos - 1; i++) {
		temp = temp->next;
	}

	nextnode = temp->next;
	temp->next = nextnode->next;
	free(nextnode);

	printf("\nNode deleted successfully\n");
}

int main() {
	int ch;

	do {
		printf("\n1. Create List\n2. Display\n3. Insert After Position\n4. Delete At Position\n5. Exit\n");
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
				InsertAftPos();
				break;
			case 4:
				DeleteAtPos();
				break;
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("\nEnter a Valid Choice\n");
		}
	} while(ch != 5);
	
	return 0;
}
