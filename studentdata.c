// Name: Unnati Dharpure  USN No.: CS23147
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	char name[20];
	float marks;
	int roll;
};

struct student *addDetails(struct student *ptr,int n)
{
	
    printf("Enter name:");
	scanf("%s",ptr->name);
	printf("Enter marks:");
	scanf("%f",&ptr->marks);
	printf("Enter roll no.:");
	scanf("%d",&ptr->roll);
	ptr++;
	return ptr;
}

void displayDetails(struct student *ptr1,struct student *ptr)
{
	printf("\n-----------------------------------------------\n");
	printf("NAME\t\tROLL NO\t\tMARKS\n");
	printf("\n-----------------------------------------------\n");
	while(ptr1!=ptr){
		printf("%s\t\t%d\t\t%.2f\n",ptr1->name,ptr1->roll,ptr1->marks);
		ptr1++;
	}
	printf("\n-----------------------------------------------\n");
}
void MinMarks(struct student *ptr1,struct student *ptr)
{
	int min_marks=ptr1->marks;
	
	while(ptr1!=ptr)
	{
		if(min_marks > ptr1->marks)
		{
			min_marks = ptr1->marks;
		}
	    ptr1++;
	}
	printf("Minimum marks among students are = %d\n",min_marks);
}

void MaxMarks(struct student *ptr1,struct student *ptr)
{
	int max_marks=ptr1->marks;
	
	while(ptr1!=ptr)
	{
		if(max_marks < ptr1->marks)
		{
			max_marks = ptr1->marks;
		}
	    ptr1++;
	}
	printf("Maximum marks among students are = %d\n",max_marks);
}

main()
{
	struct student *ptr;
	int ch,n,stock=0;
	printf("enter no. of students:");
	scanf("%d",&n);
	ptr=(struct student*)malloc(n*sizeof(struct student));
	struct student *ptr1;
	ptr1=ptr;
	while(1)
	{
		printf("1.Add student details\n2.Display student details\n3.Display minimum marks\n4.Display maximum marks\n5.exit\n");
		printf("choose one(1-5):\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
				if(stock==n){
	    			printf("cannot add more student details");
	    			break;
				}
				else{
					ptr = addDetails(ptr,n);
					break;
				}
			case 2:
				displayDetails(ptr1,ptr);
				break;
			case 3:
				MinMarks(ptr1,ptr);
				break;
			case 4:
				MaxMarks(ptr1,ptr);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("invalid input");
				break;
		}
	}
	return 0;
}
