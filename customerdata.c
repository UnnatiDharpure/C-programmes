// Name: Unnati Dharpure  USN No.: CS23147
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer
{
	char name[20],address[20];
	int cus_ID,CurrentAmt;
};

struct customer *addDetails(struct customer *ptr,int n)
{
	
    printf("Enter name:");
	scanf("%s",ptr->name);
	printf("Enter address:");
	scanf("%s",ptr->address);
	printf("Enter customer ID:");
	scanf("%d",&ptr->cus_ID);
	printf("Enter current amount:");
	scanf("%d",&ptr->CurrentAmt);
	ptr++;
	return ptr;
}

void displayDetails(struct customer *ptr1,struct customer *ptr)
{
	printf("\n--------------------------------------------------------\n");
	printf("NAME\t\tADDRESS\t\tCUSTOMER ID\t\tCURRENT AMOUNT\n");
	printf("\n---------------------------------------------------------\n");
	while(ptr1!=ptr){
		printf("%s\t\t%s\t\t%d\t\t%d\n",ptr1->name,ptr1->address,ptr1->cus_ID,ptr1->CurrentAmt);
		ptr1++;
	}
	printf("\n---------------------------------------------------------\n");
}
void DepositAmt(struct customer *ptr1,struct customer *ptr)
{
	int temp,deposit,flag=1;
	printf("Enter customer ID:");
	scanf("%d",&temp);
	
	while(ptr1!=ptr)
	{
	     if(temp == ptr1->cus_ID )
	     {
	     	flag=0;
	     	break;
		 }
		 ptr1++;
	}
	if(flag==0)
	{
	 	printf("How much money you want to deposit?\n");
	    scanf("%d",&deposit);
	    ptr1->CurrentAmt = ptr1->CurrentAmt + deposit;
	    printf("Amount deposited successfully\n");
	}
	else
	{
		printf("customer ID not found\n");
	}
}

void WithdrawAmt(struct customer *ptr1,struct customer *ptr)
{
	int withdraw,temp,flag=1;
	printf("Enter customer ID:");
	scanf("%d",&temp);
	
	while(ptr1!=ptr)
	{
	     if(temp == ptr1->cus_ID )
	     {
	     	flag=0;
	     	break;
		 }
		 ptr1++;
	}
	if(flag==0)
	{
		if(ptr1->CurrentAmt < 500)
		{
			printf("money withdrawl not possible as current balance is less than 500\n");
		}
		else
		{
			printf("How much money you want to withdraw?\n");
	        scanf("%d",&withdraw);
    	    ptr1->CurrentAmt = ptr1->CurrentAmt - withdraw;
	        printf("Amount withdrawn successfully\n");
		}
	}
	else
	{
		printf("customer ID not found\n");
	}
	
}

main()
{
	struct customer *ptr;
	int ch,n,balance,stock=0;
	printf("enter no. of customers:");
	scanf("%d",&n);
	ptr=(struct customer*)malloc(n*sizeof(struct customer));
	struct customer *ptr1;
	ptr1=ptr;
	while(1)
	{
		printf("1.Add customer details\n2.Display customer details\n3.Deposit amount\n4.Withdraw amount\n5.exit\n");
		printf("choose one(1-5):\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		if(stock==n){
	    			printf("cannot add more customer details\n");
	    			break;
				}
				else{
				       printf("enter current balance:");
	    	        	scanf("%d",&balance);
	    	        	if(balance >= 500)
	    	     	{
	    		    	ptr = addDetails(ptr,n);
			        	break;
			    	}
				    else
			    	{
				    	printf("minimum balance should be 500 to create account\n");
					    break;
			    	}
				}
				
				case 2:
				displayDetails(ptr1,ptr);
				break;
			case 3:
				DepositAmt(ptr1,ptr);
				break;
			case 4:
				WithdrawAmt(ptr1,ptr);
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
