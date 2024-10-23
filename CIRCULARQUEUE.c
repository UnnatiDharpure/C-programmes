//Unnati Dharpure   CS23147
#include<stdio.h>
#define N 5
int front=-1;
int rear=-1;
int queue[N];

void enqueue(){
	int x;
	
   if(front == -1 && rear == -1){
     front=rear=0;
     printf("Enter item to insert:");
     scanf("%d",&x);
     queue[rear]=x;
   }
   else if( (rear+1) % N == front){
      printf("queue is full\n");
   }
   else{
      rear = (rear+1) % N;
      printf("Enter item to insert:");
      scanf("%d",&x);
      queue[rear]=x;
   }
}

void dequeue(){

    if(front == -1 && rear == -1){
      printf("queue is empty\n");
    }
    else if(front==rear){
      printf("deleted item = %d\n",queue[front]);
    }
    else{
       printf("deleted item = %d\n",queue[front]);
       front = (front+1) % N;
    }
}

void peak(){
   if(front == -1 && rear == -1){
      printf("queue is empty\n");
   }
   else{
      printf("top element = %d\n",queue[front]);
   }
}
void display(){
  int i=front;
  if(front == -1 && rear == -1){
     printf("queue is empty\n");
  }
  else{
     while(i!=rear){
       printf("%d\n",queue[i]);
       i = (i+1) % N;
     }
     //printing last item
     printf("%d\n",queue[rear]);
  }
}
main(){
  int ch;
  while(1) {
     printf("1.INSERT ELEMENT\n2.DELETE ELEMENT\n3.PEAK\n4.DISPLAY\n");
     printf("Enter a choice:");
     scanf("%d",&ch);
     switch(ch){
     case 1:
           enqueue();
           break;
    case 2:
           dequeue();
           break;
    case 3:
           peak();
           break;
    case 4:
           display();
           break;
           default:
           printf("invalid input\n");
           break;
      }
  }
}
