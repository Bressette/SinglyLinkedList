#include "stdlib.h"
#include "stdio.h"

int size = 0;

struct node
{
    int element;
    struct node *next;
};

struct node *insertLast(struct node *head, int newElement)
{
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->element = newElement;
    newNode->next = NULL;

    temp = head;

    if(head == NULL)
    {
        head = newNode;
    }

    else
    {


        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    size++;
    return head;

}

int get(struct node *head, int index)
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return -1000;
    }

    else
    {


        for(int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp->element;
    }

}

void printList(struct node *head)
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
    }

    else
    {



        while(temp->next != NULL)
        {
            printf("%d ", temp->element);
            temp = temp->next;
        }
        printf("%d \n", temp->element);
    }
}

int main()
{
    struct node *head = NULL;
    head = insertLast(head, 3);
    head = insertLast(head, 4);
    head = insertLast(head, 5);
    head = insertLast(head, 6);
    printList(head);

    return 0;
}
