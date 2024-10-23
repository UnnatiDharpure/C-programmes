// Name: Unnati Dharpure  USN No.: CS23147
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct company
{
	char name[20],address[20];
	int noOfemployees;
};

struct company *addDetails(struct company *ptr,int n)
{
	
    printf("Enter name:");
	scanf("%s",ptr->name);
	printf("Enter address:");
	scanf("%s",ptr->address);
	printf("Enter no. of employees working in the company:");
	scanf("%d",&ptr->noOfemployees);
	ptr++;
	return ptr;
}

void displayDetails(struct company *ptr1,struct company *ptr)
{
	printf("\n-----------------------------------------------\n");
	printf("NAME\t\tADDRESS\t\tNO. OF EMPLOYEES\n");
	printf("\n-----------------------------------------------\n");
	while(ptr1!=ptr){
		printf("%s\t\t%s\t\t%d\n",ptr1->name,ptr1->address,ptr1->noOfemployees);
		ptr1++;
	}
	printf("\n-----------------------------------------------\n");
}

void UpdateDetail(struct company *ptr1,struct company *ptr)
{
     char temp[10];
      int flag=1;
      printf("enter company address:");
       scanf("%s",temp);

          while(ptr1!=ptr){
             if((strcmp(ptr1->address,temp))==0)
             {
                flag=0;
                 break;
               }
             ptr1++;
           }
            if(flag==0)
              {
                  printf("enter number of employees working in the company\n");
                  scanf("%d",&ptr1->noOfemployees);
                     printf("data updated successfully\n");
               }
            else
               {
                   printf("data not found\n");
               }

}

void DisplayMaxDetails(struct company *ptr1,struct company *ptr)
{
    char add[10];
    int flag=1;
    printf("enter company address:");
    scanf("%s",add);

          while(ptr1!=ptr){
             if((strcmp(ptr1->address,add))==0)
             {
                flag=0;
                 break;
               }
             ptr1++;
           }
            if(flag==0)
              {
                  printf("maximum number of employees working in the company are %d\n",ptr1->noOfemployees);
               }
            else
               {
                   printf("data not found\n");
               }
}

main()
{
	struct company *ptr;
	int ch,n,stock=0;
	printf("enter no. of companie:");
	scanf("%d",&n);
	ptr=(struct company*)malloc(n*sizeof(struct company));
	struct company *ptr1;
	ptr1=ptr;
	while(1)
	{
		printf("1.Add company details\n2.Display company details\n3.Update employee details\n4.Display maximum employee details\n5.exit\n");
		printf("choose one(1-5):\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
					if(stock==n){
	    			printf("cannot add more company details\n");
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
				UpdateDetail(ptr1,ptr);
				break;
			case 4:
				DisplayMaxDetails(ptr1,ptr);
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
