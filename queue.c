//Unnati Dharpure     CS23147
#include<stdio.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;


void enqueue(int item){
    if(rear==(max-1))
  printf("\n Overflow");
  else if(front==-1 && rear==-1){
 front=rear=0;
  queue[rear]=item;
  }
  else{
  rear++;
     queue[rear]=item;
    }
 }
void display(){
   int i;
  if(front==-1 && rear==-1){
  printf("\n Queue is Underflow");

      }
   else if((front==-1)||(front>rear)){
   printf("\n Queue is Underflow");
    }
    else{

   for(i=front;i<=rear;i++){
   printf("\n%d",queue[i]);

   }  
   }
 }
void dequeue()
{
    if(front==-1 && rear==-1){
        printf("\n Queue is Underflow");

}
        else if((front==-1)||(front>rear)){
    printf("\n Queue is Underflow");
  }
else
  {

   printf("\n removing the Item %d",queue[front]);
   front++;
  printf("\n New front the Item %d",queue[front]);
   }
   }
void peek()
{
    if(front=-1 && rear==-1){
   printf("\n Queue is Underflow");

  }
   else{

     printf("\n Last Item is  %d",queue[front]);
	 }
  }
   int main(){

   int choice;

   while(1){

       printf("\n Select the choice \n 1. Insert in Queue \n 2. Display in Queue \n 3.Dequeue \n 4.Peek \n 5. Exit");
       scanf("%d",&choice);
       int item;
       switch(choice)
       {
           case 1:
               printf("\n you chose to insert :");
               scanf("%d",&item);
               enqueue(item);
               break;
           case 2:
               display();
               break;
           case 3:
               dequeue();
               break;
           case 4:
                peek();
                break;
           case 5:
                return 0;
            default :
            printf("\n enter Valid Choice");
       }

    }
 }
