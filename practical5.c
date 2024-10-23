//unnati dharpure   cs23147
#include <stdio.h>
#include <stdlib.h>

void createlist();
void display();
void InsertAftPos();
void DeleteAtPos();

struct node {
    int data;
    struct node *next;
};

struct node *newnode, *temp, *head;

void createlist() {
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMEMORY NOT ALLOCATED");
        return;
    }
    printf("\nEnter Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = temp = newnode;
    } else {
        temp->next = newnode;
        temp = newnode;
    }
}

void display() {
    temp = head;
    if (head == NULL) {
        printf("\nList is Empty");
        return;
    }
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void InsertAftPos() {
    int pos, i = 1, length = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMEMORY NOT ALLOCATED");
        return;
    }

    temp = head;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }
    printf("\nLENGTH = %d", length);
    
    printf("\nEnter position after which you want to insert new node: ");
    scanf("%d", &pos);

    if (pos > length) {
        printf("\nINVALID POSITION");
    } else {
        temp = head;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        
        printf("\nEnter data: ");
        scanf("%d", &newnode->data);

        newnode->next = temp->next;
        temp->next = newnode;

        printf("\nNode inserted successfully\n");
    }
}

void DeleteAtPos() {
    int pos, i = 1, length = 0;
    struct node *nextnode;
    temp = head;

    while (temp != NULL) {
        temp = temp->next;
        length++;
    }
    printf("\nLENGTH = %d", length);

    if (head == NULL) {
        printf("\nList is Empty");
        return;
    }

    printf("\nEnter position which you want to delete the node: ");
    scanf("%d", &pos);

    if (pos > length) {
        printf("\nINVALID POSITION");
    } else if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
        printf("\nNode deleted successfully\n");
    } else {
        temp = head;
        while (i < (pos - 1)) {
            temp = temp->next;
            i++;
        }

        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
        
        printf("\nNode deleted successfully\n");
    }
}

int main() {
    int ch;
    head = NULL;
    
    do {
        printf("\n1. Create List\n2. Display\n3. Insert After Position\n4. Delete At Position\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
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
    } while (ch != 5);

    return 0;
}

