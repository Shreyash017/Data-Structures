#include <stdio.h>
#include <stdlib.h>

struct Node *createNode(int);
void addAtFront(int);
void addAtEnd(int);
void addAtPosition(int);
void deleteAtFront();
void deleteAtEnd();
void deleteAtPosition();
void deleteByValue();
void searchElement();
void displayList();
void primeNumbers();
void perfectNumber();
void reverseList();

int count = 0;

struct Node
{
    int data;
    struct Node *next, *prev;
};

struct Node *head = NULL, *last = NULL, *temp = NULL, *p = NULL, *newnode;

int main()
{
    int data, choice;
    do
    {
        printf("\nCount= %d\n", count);
        printf("\n***Doubly Linked List***");
        printf("\n1.Add at Front\n2.Add at End\n3.Add at Position\n4.Delete at Begin\n5.Delete at End\n6.Delete at Position\n7.Delete by Value\n8.Search Data\n9.Display\n10.Sum of Prime Numbers\n11.Sum of Perfect Numbers\n12.Reverse the List\n13.Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Data to add in Node: ");
            scanf("%d", &data);
            addAtFront(data);
            break;
        case 2:
            printf("\nEnter Data to add in Node: ");
            scanf("%d", &data);
            addAtEnd(data);
            break;
        case 3:
            printf("\nEnter Data to add in Node: ");
            scanf("%d", &data);
            addAtPosition(data);
            break;
        case 4:
            deleteAtFront();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            deleteByValue();
            break;
        case 8:
            printf("\nEnter Data to be Searched: ");
            scanf("%d", &data);
            searchElement(data);
            break;
        case 9:
            displayList();
            break;
        case 10:
            primeNumbers();
            break;
        case 11:
            perfectNumber();
            break;
        case 12:
            reverseList();
            break;
        case 13:
            printf("\nThank You\n");
            break;
        default:
            printf("\nSelect a Valid Choice\n");
            break;
        }

    } while (choice != 13);
    return 0;
}

struct Node *createNode(int info)
{
    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = info;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void addAtFront(int info)
{
    newnode = createNode(info);
    if (head == NULL)
    {
        head = newnode;
        last = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    count++;
    displayList();
}

void addAtEnd(int info)
{
    newnode = createNode(info);
    if (head == NULL)
    {
        head = newnode;
        last = newnode;
    }
    else
    {
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
    count++;
    displayList();
}

void addAtPosition(int info)
{
    int position, i;
    printf("\nEnter a position: ");
    scanf("%d", &position);
    temp = head;

    if (position == 1)
    {
        addAtFront(info);
    }
    else if (position <= count)
    {
        newnode = createNode(info);
        for (int i = 0; i < position - 1; i++)
        {
            p = temp;
            temp = temp->next;
        }
        p->next = newnode;
        newnode->prev = p;
        newnode->next = temp;
        temp->prev = newnode;
        count++;
        displayList();
    }
    else
    {
        printf("\nInvalid Position or List is Empty\n");
    }
}

void deleteAtFront()
{
    if (head == NULL)
    {
        printf("\nList is Empty");
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        free(temp);
        count--;
        displayList();
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        count--;
        displayList();
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("\nList is Empty");
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        free(temp);
        count--;
        displayList();
    }
    else
    {
        temp = last;
        last = last->prev;
        last->next = NULL;
        free(temp);
        count--;
        displayList();
    }
}

void deleteAtPosition()
{
    int position, i;
    printf("\nEnter a position: ");
    scanf("%d", &position);
    temp = head;

    if (position == 1)
    {
        deleteAtFront();
    }
    else if (position == count)
    {
        deleteAtEnd();
    }
    else if (position < count)
    {
        struct Node *temp1;
        for (int i = 0; i < position - 1; i++)
        {
            p = temp;
            temp = temp->next;
        }
        p->next = temp->next;
        temp1 = temp->next;
        temp1->prev = p;
        free(temp);
        count--;
        displayList();
    }
    else
    {
        printf("\nInvalid Position or List is Empty\n");
    }
}

void deleteByValue()
{
    int value, flag = 0, position = 1;
    printf("\nEnter a Node Value: ");
    scanf("%d", &value);
    temp = head;

    if (head == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                flag = 1;
                break;
            }
            position++;
            temp = temp->next;
        }
        if (position == 1)
        {
            deleteAtFront();
        }
        else if (position == count)
        {
            deleteAtEnd();
        }
        else if (flag == 1)
        {
            struct Node *temp1;
            temp = head;
            for (int i = 0; i < position - 1; i++)
            {
                p = temp;
                temp = temp->next;
            }
            p->next = temp->next;
            temp1 = temp->next;
            temp1->prev = p;
            free(temp);
            count--;
            displayList();
        }
        else
        {
            printf("\n%d is not in List", value);
        }
    }
}

void displayList()
{
    temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList()
{
    // Revesing a Doubly Linked List means Swap the Previous Pointer with Next Pointer for each Node
    // and at last swap the head and last pointer
    struct Node *currentnode = head, *nextnode;
    // To reverse a Doubly-List we maintain 2 pointers as above

    while (currentnode != NULL)
    {
        // Here we first update the current->next part with current->prev part
        // as we have 1 more pointer at current->next
        nextnode = currentnode->next;
        currentnode->next = currentnode->prev;
        currentnode->prev = nextnode;
        currentnode = nextnode;
    }
    // Here we swap head & last
    temp = head;
    head = last;
    last = temp;
    displayList();
}

void searchElement(int info)
{
    int position = 1;
    int flag = 0;
    temp = head;

    for (temp = head; temp != NULL; temp = temp->next)
    {
        if (temp->data == info)
        {
            flag = 1;
            printf("\n%d is at Position: %d\n", info, position);
            break;
        }
        position++;
    }
    if (flag == 0)
    {
        printf("\nNo Data Found\n");
    }
}

int findPrime(int info)
{
    int count = 0;
    for (int i = 1; i <= info; i++)
    {
        if (info % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void primeNumbers()
{
    if (head == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        int data, result, sum = 0;
        temp = head;

        printf("\nPrime Numbers are:\n");
        while (temp != NULL)
        {
            data = temp->data;
            result = findPrime(data);
            if (data > 0 && result == 1)
            {
                sum += data;
                printf("%d-->", data);
            }
            temp = temp->next;
        }
        printf("\nSum of Prime Numbers: %d", sum);
    }
}

int get_factor_sum(int info)
{
    int sum = 0;
    int i = 1;
    while (i <= (info / 2))
    {
        if (info % i == 0)
        {
            sum += i;
        }
        i++;
    }
    if (sum == info)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void perfectNumber()
{
    if (head == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        int data, result, sum = 0;
        temp = head;

        printf("\nPerfect Numbers are:\n");
        while (temp != NULL)
        {
            data = temp->data;
            result = get_factor_sum(data);
            if (data > 0 && result == 1)
            {
                sum += data;
                printf("%d-->", data);
            }
            temp = temp->next;
        }
        printf("\nSum of Perfect numbers: %d", sum);
    }
}