#include <stdio.h>
#include <stdlib.h>

struct emp {
    char name[20];
    int salary;
};

int main() {
    struct emp *ptr;
    int i, n, total = 0;
    float avg;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    ptr = (struct emp *)malloc(n * sizeof(struct emp));
    struct emp *temp = ptr;
    
    if (ptr == NULL) {
        printf("Memory not created\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        printf("Enter details of employee %d\n", i + 1);
        printf("Enter name: ");
        scanf("%s", ptr->name);
        printf("Enter salary: ");
        scanf("%d", &ptr->salary);
        total += ptr->salary;
        ptr++;
    }
    
    avg = (float)total / n;
    ptr = temp;
    
    printf("Employee details are:\n");
    for (i = 0; i < n; i++) {
        printf("Details of employee %d:\n", i + 1);
        printf("Name: %s\n", ptr->name);
        printf("Salary: %d\n", ptr->salary);
        ptr++;
    }
    
    printf("Total salary of employees is: %d\n", total);
    printf("Average salary of employees is: %.2f\n", avg);
    
    free(temp);
    
    return 0;
}
