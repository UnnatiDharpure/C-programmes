//Unnati Dharpure  CS23147
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode; 
    } else {
        rear->next = newNode; 
        rear = newNode;     
    }
}

int dequeue() {
    if (front == NULL) {
        printf("\nQueue is underflow\n");
        return -1;
    }

    struct node* temp = front;
    int dequeuedValue = temp->data;
    front = front->next; 

    if (front == NULL) {
        rear = NULL; 
    }

    free(temp); 
    printf("\nDeleted item: %d\n", dequeuedValue);
    return dequeuedValue;
}

void peek() {
    if (front == NULL) {
        printf("\nQueue is underflow\n");
    } else {
        printf("\ntop item is %d\n", front->data);
    }
}


void display() {
    if (front == NULL) {
        printf("\nQueue is underflow\n");
        return;
    }

    struct node* temp = front;
    printf("\nQueue elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, item;

    while (1) {
        printf("\nSelect the choice\n1. Insert\n2. Dequeue\n3. Display Queue\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nInset item: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
               exit(0);
            default:
                printf("\nEnter a valid choice\n");
        }
    }
}
