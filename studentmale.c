// Name: Unnati Dharpure  USN No.: CS23147
#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[20], gender[10], grade[10];
    int roll, age;
};

int main() 
{
    struct student *ptr;
    int i, n;
    
    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    // Allocate memory for 'n' students dynamically
    ptr = (struct student*)malloc(n * sizeof(struct student));
    
    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Temporary pointer to keep track of the original memory block
    struct student *temp = ptr;
    
    // Input details for each student
    for (i = 0; i < n; i++)
	{
        printf("Enter details of student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", ptr->name);
        printf("Enter gender (M/F): ");
        scanf("%s", ptr->gender);
        printf("Enter roll no.: ");
        scanf("%d", &ptr->roll);
        printf("Enter age: ");
        scanf("%d", &ptr->age);
        printf("Enter grade: ");
        scanf("%s", ptr->grade);
        ptr++;
    }
    ptr = temp;
    
    // Print names of all male students
    printf("\nThe names of all male students are:\n");
    for (i = 0; i < n; i++) {
        if (ptr->gender[0] == 'M' || ptr->gender[0] == 'm') {
            printf("%s\n", ptr->name);
        }
        ptr++;
    }
    free(temp);
    return 0;
}
