//Unnati dharpure  cs23147
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL, *newnode, *temp;
void createdoublylist() {
    int choice=1;
    
    while(choice!=0) {
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
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
      printf("\nwant to insert more element(1/0): ");
      scanf("%d",&choice);
        
    }
}
void displayReverse() {
    if (tail == NULL) {
        printf("\nLIST IS EMPTY");
        return;
    }

    temp = tail;
    printf("\nElements in reverse order: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    createdoublylist(); 
    displayReverse();  
    return 0;
}
