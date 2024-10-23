//Unnati dharpure  cs23147
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL, *newnode, *temp;


void createCircularList() {
    int choice = 1;
    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("\nMemory not allocated");
            return;
        }
        printf("\nEnter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {  
            head = tail = newnode;
            tail->next = head;  
        } else {
            tail->next = newnode;  
            tail = newnode;        
            tail->next = head;  
        }
		printf("\n add another node (1/0): ");
        scanf("%d", &choice);  
    }
}
void displayCircularList() {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }

    temp = head;
    printf("\nElements in the circular linked list: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  
    printf("(head)\n");
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n1. Create Circular Linked List\n2. Display Circular Linked List\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createCircularList();
                break;
            case 2:
                displayCircularList();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } 
	while (choice != 3);

    return 0;
}
