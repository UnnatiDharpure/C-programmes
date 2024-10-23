// Name: Unnati Dharpure  USN No.: CS23147
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct inventory 
{
	char name[20],code[10],category[10];
	float price;
	int quantity;
};

struct inventory *addItem(struct inventory *ptr,int n)
{
	
    printf("Enter name:");
	scanf("%s",ptr->name);
	printf("Enter code:");
	scanf("%s",ptr->code);
	printf("Enter category:");
	scanf("%s",ptr->category);
	printf("Enter price:");
	scanf("%f",&ptr->price);
	printf("Enter quantity:");
	scanf("%d",&ptr->quantity);
	ptr++;
	return ptr;
}

void displayItem(struct inventory *ptr1,struct inventory *ptr)
{
	printf("\n-----------------------------------------------\n");
	printf("NAME\tCODE\tCATEGORY\tPRICE\tQUANTITY\n");
	printf("\n-----------------------------------------------\n");
	while(ptr1!=ptr){
		printf("%s\t%s\t%s\t%.2f\t%d\n",ptr1->name,ptr1->code,ptr1->category,ptr1->price,ptr1->quantity);
		ptr1++;
	}
	printf("\n-----------------------------------------------\n");
}
void searchItem(struct inventory *ptr1,struct inventory *ptr)
{
	char temp[10];
	int flag=1;
	printf("enter code of item you want to find:");
	scanf("%s",temp);
	
	while(ptr1!=ptr){
		if((strcmp(ptr1->code,temp))==0)
		{
			flag=0;
			break;
	    }
	   	ptr1++;
	   }
	    if(flag==0)
	    {
			printf("item found...displaying item\n");
			printf("name:%s\n",ptr1->name);
			printf("code:%s\n",ptr1->code);
			printf("category:%s\n",ptr1->category);
	        printf("price:%.2f\n",ptr1->price);
			printf("quantity:%d\n",ptr1->quantity);
			
		}
		else
	    {
	    	printf("item not found");
	    	
		}
	
	}
void updateQuantity(struct inventory *ptr1,struct inventory *ptr)
{
	char cde[10];
	int flag=1;
	printf("enter code of item you want to increase quantity:");
	scanf("%s",cde);
	
	while(ptr1!=ptr){
		if((strcmp(ptr1->code,cde))==0)
		{
			flag=0;
			printf("how much you want to increase");
	    	scanf("%d",&ptr1->quantity);
	    }
	    ptr1++;
	}
		if(flag==0)
		{
			printf("item quantity increased.");
			
		}
		else{
			printf("item not found");
			
		}
		
	
}
main()
{
	struct inventory *ptr;
	int ch,n,stock=0;
	printf("enter no. of items:");
	scanf("%d",&n);
	ptr=(struct inventory*)malloc(n*sizeof(struct inventory));
	struct inventory *ptr1;
	ptr1=ptr;
	while(1)
	{
		printf("1.Add item\n2.Display item\n3.Search item\n4.Update item\n5.exit\n");
		printf("choose one(1-3):\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		if(stock==n){
	    			printf("stock full cannot add item.");
	    			break;
				}
				else{
					ptr = addItem(ptr,n);
					break;
				}
			case 2:
				displayItem(ptr1,ptr);
				break;
			case 3:
				searchItem(ptr1,ptr);
				break;
			case 4:
				updateQuantity(ptr1,ptr);
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
