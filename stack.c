//Unnati Dharpure    CS23147
#include<stdio.h>
#define MAX 20
int top=-1;
char stack[MAX];

void push(){
    char item;
    if(top==MAX-1){
     printf("stack overflow\n");
     }
    else{
       printf("enter character you want to push:");
       scanf(" %c",&item);
       top++;
       stack[top]=item;
     }
}


void display(){
    int i;
      if(top==-1){
         printf("stack is empty\n");
       }
       else{
          for(i=top;i>=0;i--){
               printf("%c\n",stack[i]);
           }
        }
}

main(){
    int ch;
    while(1){
         printf("1. PUSH\n2. POP\n");
         printf("enter your choice:");
         scanf("%d",&ch);
         switch(ch){
            case 1:
               push();
               break;
            case 2:
               display();
               break;
            default:
               printf("invalid input\n");
               break;
           }
        }
}



















/*
void pop(){

      if(top==-1){
          printf("stack is empty\n");
      }
      else{
           printf("pop item from stack %d\n",stack[top]);
           top--;
      }
}

void peak(){

    if(top==-1){
         printf("stack is empty\n");
      }
     else{
        printf("top element=%d\n",stack[top]);
       }
}*/
