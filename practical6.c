//unnati dharpure  cs23147
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create();
void insert(struct node*, struct node*);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);
struct node* deleteNode(struct node*, int);
struct node* findMin(struct node*);
void menu();

struct node *root = NULL;

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert Node\n2. Delete Node\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // Insert Node
                struct node *newnode = create();
                if (root == NULL) {
                    root = newnode;
                } else {
                    insert(root, newnode);
                }
                break;
            }
            case 2: // Delete Node
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3: // Preorder Traversal
                printf("Tree Values in preorder sequence are:\n");
                preorder(root);
                printf("\n");
                break;
            case 4: // Inorder Traversal
                printf("Tree Values in inorder sequence are:\n");
                inorder(root);
                printf("\n");
                break;
            case 5: // Postorder Traversal
                printf("Tree Values in postorder sequence are:\n");
                postorder(root);
                printf("\n");
                break;
            case 6: // Exit
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    return 0;
}

struct node *create() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter Value: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert(struct node* root, struct node* newnode) {
    if (newnode->data < root->data) {
        if (root->left != NULL) {
            insert(root->left, newnode);
        } else {
            root->left = newnode;
        }
    } else if (newnode->data > root->data) {
        if (root->right != NULL) {
            insert(root->right, newnode);
        } else {
            root->right = newnode;
        }
    }
}

struct node* deleteNode(struct node* root, int value) {
    if (root == NULL) {
        printf("Value not found!\n");
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else { // Node found
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else {
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

struct node* findMin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d->", root->data);
    }
}

