#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);
void division(int a, int b);

int main() {
    int a, b, ch;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    printf("Input your option: \n1-Addition\n2-Subtraction\n3-Multiplication\n4-Division\n5-Exit\n");
    scanf("%d", &ch);
    
    switch(ch) {
        case 1:
            add(a, b);
            break;
        case 2:
            sub(a, b);
            break;
        case 3:
            mul(a, b);
            break;
        case 4:
            division(a, b);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid input\n");
            break;
    }
    
    return 0;
}

void add(int a, int b) {
    printf("The addition of %d and %d is: %d\n", a, b, a + b);
}

void sub(int a, int b) {
    printf("The subtraction of %d and %d is: %d\n", a, b, a - b);
}

void mul(int a, int b) {
    printf("The multiplication of %d and %d is: %d\n", a, b, a * b);
}

void division(int a, int b) {
    if (b != 0) {
        printf("The division of %d and %d is: %d\n", a, b, a / b);
    } else {
        printf("Division by zero is not allowed.\n");
    }
}

