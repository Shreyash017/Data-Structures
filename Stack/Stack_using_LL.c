#include <stdio.h>
#include <stdlib.h>

void push(int);
void pop();
void stackTop();
void displayStack();
void reverseStack();

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newnode, *tos = NULL, *temp = NULL;

int main()
{
    int data, choice;
    do
    {
        printf("\n***Stack Operations using Linked List***");
        printf("\n1.Push\n2.Pop\n3.StackTop\n4.DisplayStack\n5.ReverseStack\n6.Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Data to add in Node: ");
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
            break;
        }
    } while (choice != 6);
    return 0;
}

void push(int info)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = info;
    newnode->next = tos;
    tos = newnode;
    displayStack();
}

void pop()
{
    if (tos == NULL)
        printf("\nStack Underflow\n");
    else
    {
        temp = tos;
        printf("\nElement Popped is: %d\n", temp->data);
        tos = temp->next;
        free(temp);
        displayStack();
    }
}

void stackTop()
{
    if (tos == NULL)
        printf("\nStack is Empty\n");
    else
        printf("\nData at the top of the stack is: %d\n", tos->data);
}

void displayStack()
{
    if (tos == NULL)
        printf("\nStack is Empty\n");
    else
    {
        temp = tos;
        printf("\nStack: \n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void reverseStack()
{
    struct Node *prevnode = NULL, *currentnode = tos, *nextnode = tos;
    // To reverse a Singly-List we maintain 3 pointers as above

    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    tos = prevnode;
    displayStack();
}