//Unnati dharpure  cs23147
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL, *tail = NULL, *newnode, *temp;
void createCircularDoublyList() {
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
        newnode->prev = NULL;

        if (head == NULL) {  
            head = tail = newnode;
            head->next = head;  
            head->prev = head;  
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;  
            head->prev = newnode;  
            tail = newnode;
        }
        printf("\n add another node? (1/0): ");
        scanf("%d", &choice);
    }
}
void displayCircularDoublyList() {
    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }
    temp = head;
    printf("\nElements in the circular doubly linked list: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  
    printf("(head)\n");
}
int main() {
    int choice;

    while(1) {
        printf("\nMenu:\n1. Create Circular Doubly Linked List\n2. Display Circular Doubly Linked List\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createCircularDoublyList();
                break;
            case 2:
                displayCircularDoublyList();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } 

    return 0;
}
