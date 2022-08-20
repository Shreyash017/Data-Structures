#include <stdio.h>
#include <stdlib.h>
#define MAX 11

void push(int);
void pop();
void stackTop();
void displayStack();
void reverseStack();
int tos = -1, stack[MAX];

int main()
{
    char info;
    int data, choice;
    do
    {
        printf("\n***Stack Operations using Array***");
        printf("\n1.Push\n2.Pop\n3.StackTop\n4.DisplayStack\n5.ReverseStack\n6.Exit");
        printf("\nEnter The Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Data to add into Stack: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            stackTop();
            break;
        case 4:
            displayStack();
            break;
        case 5:
            reverseStack();
            break;
        case 6:
            printf("\nThank You\n");
            break;
        default:
            printf("\nSelect a Valid Choice\n");
        }

    } while (choice != 6);
    return 0;
}

void push(int data)
{
    if (tos == (MAX - 1))
        printf("\nStack Overflow\n");
    else
    {
        tos++;
        stack[tos] = data;
        displayStack();
    }
}

void pop()
{
    if (tos == -1)
        printf("\nStack Underflow\n");
    else
    {
        printf("\nElement Popped is: %d\n", stack[tos]);
        tos--;
        displayStack();
    }
}

void stackTop()
{
    if (tos == -1)
        printf("\nStack is Empty\n");
    else
        printf("\nData at the top of the stack is: %d\n", stack[tos]);
}

void displayStack()
{
    int i;
    if (tos == -1)
        printf("\nStack is Empty\n");
    else
    {
        printf("\nStack: \n");
        for (i = tos; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void reverseStack()
{
    int i, j;
    if (tos == -1)
        printf("\nStack is Empty\n");
    else
    {
        int tempArray[MAX];
        int temp;
        for (i = tos, j = 0; i >= 0; i--, j++)
        {
            temp = stack[i];
            tempArray[j] = temp;
        }
        for (i = 0; i <= tos; i++)
        {
            temp = tempArray[i];
            stack[i] = temp;
        }
        displayStack();
    }
}