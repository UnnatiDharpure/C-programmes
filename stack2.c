//Unnati Dharpure    CS23147
#include<stdio.h>
#include<string.h>
#define MAX 20
int top=-1;
char stack[MAX];

void push(char item){
    if(top==MAX-1){
     printf("stack overflow\n");
     }
    else{
       top++;
       stack[top]=item;
     }
}

void pop(){

      if(top==-1){
          printf("stack is empty\n");
      }
      else{
           printf("pop item from stack %c\n",stack[top]);
           top--;
      }
}

main(){
    char str[] = "EAS*Y*QUE***ST***IO*N***";
    int length = strlen(str);
    int i;
     for (i = 0; i < length; i++) {
        if (str[i] != '*') {
            push(str[i]);
        } else {
            pop();
        }
    }
}
