#include<stdio.h>
#include<stdlib.h>

#define size 5

int queue[size];
int front,rear;

void init();
void enqueue(int);
void dequeue();
void display();

void init()
{
front=0;
rear=-1;
}

void enqueue(int x)
{
    if(rear==size-1){
    printf("Queue overflow");
    }
    else
        {
            rear =rear+1;
            queue[rear]=x;
        }
}

void dequeue()
{
    if(rear<front)
        printf("\n Queue is empty");
        else
        {
            printf("\n %d is deleted",queue[front++]);
        }

}

void display()
{
    int i;
    if(rear<front)
        printf("\n Queue underflow");
    else
        for(i=front;i<=rear;i++)   
        {
            printf("\n %d",queue[i]);
        } 
}

void main()
{
    int ch;
    int x;
    init();

   while(1)
   {
    printf("\n Queue Operation");
    printf("\n1. Enqueue element");
    printf("\n2. Dequeue element");
    printf("\n3. Displaythe Queue elements");
    printf("\n4. Exit");
    printf("\n Enter your choice:");
    scanf("%d",&ch);

    switch(ch)
{
    case 1: printf("\n Enter the element to be enqueued:");
        scanf("%d",&x);
        enqueue(x);
        break;
 
    case 2: dequeue();
        break ;
         
    case 3: display();
        break;
         
    case 4: exit(1);
    default: printf("\n wrong choice"); 
        break;       
            
        }
}

}
