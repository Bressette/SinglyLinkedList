#include "stdlib.h"
#include "stdio.h"

int size = 0;

//struct used for linked list recursively points to another struct node and holds int element
struct node
{
    int element;
    struct node *next;
};

struct node *insertLast(struct node *head, int newElement)
{
    struct node *newNode, *temp;

    //allocates space for a new node that will hold the new element
    newNode = (struct node *)malloc(sizeof(struct node));
    //sets new node to the new element
    newNode->element = newElement;
    //sets the next pointer to NULL as there is no node after newNode
    newNode->next = NULL;

    //sets temp to head for iterating through the list
    temp = head;

    //if size of list is 0 sets the list to newNode
    if(head == NULL)
    {
        head = newNode;
    }

    else
    {
    //iterates while temp points to a valid element
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
    //inserts new node at the previously null next pointer
        temp->next = newNode;
    }

    size++;
    return head;

}

struct node *removeLast(struct node *head)
{
    struct node *temp = head;

    for(int i = 0; i < size-2; i++)
    {

        temp = temp->next;
    }
    temp->next = NULL;
    size--;
    return head;
}

struct node *reverseListIterative(struct node *head)
{
    struct node *prev, *next, *current;
    current = head;

    //loop that reverses the elements by swapping pointers
    while(current != NULL)
    {
        //sets the next pointer to point to the element after current position
        next = current->next;
        //the current position points backwards to previous
        current->next = prev;
        //previous and current are set to values for the next iteration
        prev = current;
        current = next;
    }
    //head is set to prev as prev will hold the final correct value of current
    head = prev;


    return head;
}


struct node *removeElement(struct node *head, int index)
{
    struct node *temp = head;
    struct node *prev = head;

    if(head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    else
    {
        for(int i = 0; i < index; i++)
        {
            prev = temp;
            temp = temp->next;
        }
    }


    prev->next = temp->next;
    free(temp);

    return head;
}

struct node *insertAt(struct node *head, int index, int newElement)
{
    struct node *temp;
}

int sizeOfList(struct node *head)
{
    struct node *temp = head;
    int newSize = 1;
    if(head == NULL)
    {
        printf("The size of the list is 0");
        return 0;
    }

    else
    {


    while(temp->next != NULL)
    {
        newSize++;
        temp = temp->next;
    }
    return newSize++;
    }
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

    head = removeLast(head);
    printList(head);
    head = removeElement(head, 1);
    printList(head);

    int listSize = sizeOfList(head);
    printf("The size of the list is %d element(s)\n", listSize);
    head = insertLast(head, 10);
    head = insertLast(head, 15);
    head = insertLast(head, 20);
    printList(head);
    head = reverseListIterative(head);
    printList(head);

    return 0;
}
