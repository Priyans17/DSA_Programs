#include <stdio.h>
#include <stdlib.h>

int stack[5];
int top=-1;

void puh(int);
void pop();
void display();

void main()
{
    int ch;
    int n1;
    
    while(1)
    {
        printf("\n Stack operations");
        printf("\n 1. push element into the stack");
        printf("\n 2. pop element from the stack");
        printf("\n 3. display the stack element");
        printf("\n 4. exit");
        
        printf("\n Enter your choice :");
        scanf("%d",&n1);
        
        switch(ch)
        {
            case 1 :
                printf("enter the elements to be pushed into the stack");
                scanf("%d",&n1);
                push(n1);
                break;
                
            case 2 :
                pop();
                break;
                
            case 3 :
                display();
                break;
                
            case 4 :
                exit(1);
                
            default :
            printf("\n wrong choice");
            break;
            
        }
    }
}
void push(int x)
{
    if(top==4) {
        printf("stack is full");
    }
    
    else {
        top++;
        stack[top]=x;
    }
 }
 
 void pop()
{
    if(top==-1)
    {
        printf("STACK IS EMPTY");
    }

    else {
        int a=stack[top];
        top--;
        printf("\n %d elemnts popped out of the stack",a);
    }

}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty ");
    }

    else {
        printf("elements in the stack are:");
        for(int i =top; i>=0; i--) {
            printf("\n %d",stack[i]);
        }
    }
}
  
