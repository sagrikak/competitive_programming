#include <stdio.h>
#include <stdlib.h>
#define max 5
int arr[max], front, rear;

void enqueue(int x)
{
    if(front==-1)
    {
        front++;
        rear++;
        arr[rear]=x;
        return;
    }
    if(rear==front-1 || rear-front==max-1)
    {
        printf("No more space!\n");
        return;
    }
    rear=(rear+1)%max;
    arr[rear]=x;
}

int dequeue()
{
    int x;
    x=arr[front];
    if(front==0 && rear==0)
    {
        front--;
        rear--;
    }
    else if(front==-1)
    {
        printf("Queue empty.\n");
        return 0;
    }
    else front=(front+1)%max;
    return x;
}

void display()
{
    int i;
    //printf("front=%d rear=%d\n", front, rear);
    if(front<=rear && front!=-1)
    {
        for(i=front; i<=rear; i++)
        {
        printf("%d ", arr[i]);
        }
    }
    if(front>rear)
    {
        for(i=front; i<max; i++)
            printf("%d ", arr[i]);
        for(i=0; i<=rear; i++)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, x;
    front=-1;
    rear=-1;
    while(1)
    {
        printf("\nEnter your choice.\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                printf("Enter the integer.\n");
                scanf("%d", &x);
                enqueue(x);
                break;
            }
            case 2:
            {
                printf("The removed integer is %d.\n", dequeue());
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(0);
            }
        }
    }
    return 0;
}
