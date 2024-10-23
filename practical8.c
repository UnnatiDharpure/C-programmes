//Unnati Dharpure    CS23147
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Node {
    int key;
    char value[20];
    struct Node* next;
};

struct HashTable {
    struct Node* table[SIZE];
};

void initializeHashTable(struct HashTable* ht) {
    int i;
    for (i = 0; i < SIZE; i++) {
        ht->table[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(struct HashTable* ht, int key, char value[]) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        struct Node* currNode = ht->table[index];
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
}

void display(struct HashTable* ht) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (ht->table[i] != NULL) {
            printf("%d: ", i);
            struct Node* currNode = ht->table[i];
            while (currNode != NULL) {
                printf("(%d, %s) ", currNode->key, currNode->value);
                currNode = currNode->next;
            }
            printf("\n");
        }
    }
}

void search(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct Node* currNode = ht->table[index];
    while (currNode != NULL) {
        if (currNode->key == key) {
            printf("Value: %s\n", currNode->value);
            return;
        }
        currNode = currNode->next;
    }
    printf("Element not found.\n");
}

void delete(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    struct Node* currNode = ht->table[index];
    struct Node* prevNode = NULL;

    while (currNode != NULL && currNode->key != key) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (prevNode == NULL) {
        ht->table[index] = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    free(currNode);
    printf("Element deleted successfully.\n");
}

int main() {
    struct HashTable ht;
    initializeHashTable(&ht);

    int choice;
    int key;
    char value[20];

    while (1) {
        printf("\nMenu-driven program for Hash table\n");
        printf("1. Insert an element\n");
        printf("2. Display elements\n");
        printf("3. Search an element\n");
        printf("4. Delete an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%s", value);
                insert(&ht, key, value);
                break;
            case 2:
                display(&ht);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(&ht, key);
                break;
            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(&ht, key);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}
