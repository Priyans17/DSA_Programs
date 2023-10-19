#include<stdio.h>
#include<stdlib.h>
#define size 5

int queue[size];
int front , rear;
void init();
void encircular(int);
void decircular();
void display();

void init()
{
front=-1;
rear =-1;
}

void encircular(int x)
{
	if((front==0 && rear==4) || front==rear+1){
		printf("circular queue full");
	}
	
	else
	{
		if(front==-1)    // keeps track of position of element
		{
		front = 0;
		}
		rear = (rear+1)%size;  // adding elements
		queue[rear] = x;
	}
}

void decircular()
{
	if(front ==-1 && rear==-1)
	{
	printf("queue is empty");
	}
	else
	{ 
	int a = queue[front];
        if (front == rear) {    // only one element present
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        printf("\n %dis deleted",a);
	}
}
void display()
{
	if(front ==-1 && rear==-1)
	{
	printf("queue is empty");
	}
	else {
        int i = front;
        printf("Queue elements: ");
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        printf("\n");
    }
    
		
}

void main()
{
int ch,x;
init();

while(1)
{
	printf("\n Circular Queue Operation");
	printf("\n1. Enqueue element");
	printf("\n2.Dequeue element");
	printf("\n3. Display queue element");
	printf("\n4. Exit");
	printf("\n Enter your choice");
	scanf("%d",&ch);
	
	switch(ch)
	{
	case 1: 
		printf("Enter the element to be enqueued");
		scanf("%d",&x);
		encircular(x);
		break;
		
	case 2:
		decircular();
		break;
		
	case 3:
		display();
		break;
	
	case 4:
		exit(0);
		
	default: 
		printf("\n worng choice");
		break;
	}
}
}