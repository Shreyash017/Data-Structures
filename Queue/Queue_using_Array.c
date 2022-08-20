#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void EnQueue(int);
void DeQueue();
void QueueFront();
void QueueRear();
void displayQueue();
int front = -1, rear = -1, queue[MAX];
// In Queue Insertion is done from Rear End
// And Deletion is done from Front End

int main()
{
    int data, choice;
    do
    {
        printf("\n***Queue Operations***");
        printf("\n1.EnQueue\n2.DeQueue\n3.QueueFront\n4.QueueRear\n5.Display\n6.Exit");
        printf("\nEnter The Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Data to add into Queue: ");
            scanf("%d", &data);
            EnQueue(data);
            break;
        case 2:
            DeQueue();
            break;
        case 3:
            QueueFront();
            break;
        case 4:
            QueueRear();
            break;
        case 5:
            printf("\n");
            displayQueue();
            printf("\n");
            break;
        case 6:
            printf("\nThank You\n");
            break;
        default:
            printf("\nSelect a Valid Choice\n");
            break;
        }

    } while (choice != 6);
    return 0;
}

void EnQueue(int data)
{
    if (rear == (MAX - 1))
        printf("\nQueue OverFlow\n");
    else
    {
        if (rear == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("\nAfter Enqueue Operation Queue is: \n");
        displayQueue();
    }
    printf("\nFRONT=%d \t REAR=%d\n", front, rear);
}

void DeQueue()
{
    if (front == -1)
        printf("\nQueue Underflow\n");
    else
    {
        printf("\nElement Dequeued is: %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        displayQueue();
        printf("\nFRONT=%d \t REAR=%d\n", front, rear);
    }
}

void QueueFront()
{
    if (rear == -1)
        printf("\nQueue is Empty\n");
    else
        printf("\nData at the Front end of the Queue is: %d\n", queue[front]);
}

void QueueRear()
{
    if (rear == -1)
        printf("\nQueue is Empty\n");
    else
        printf("\nData at the Rear end of the Queue is: %d\n", queue[rear]);
}

void displayQueue()
{
    int i;
    if (rear == -1)
        printf("\nQueue is Empty\n");
    else
    {
        printf("FRONT: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d", queue[i]);
            printf(" <== ");
        }
        printf(" :REAR");
    }
}