
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *node;
    int size;
} LinkedList;

void initLinkedList(LinkedList *list)
{
    list->node = NULL;
    list->size = 0;
}

void searchAndDelete(LinkedList *list, int value)
{

    Node *previosNode = NULL;
    Node *searchNode;
    Node *node = list->node;

    while (node != NULL)
    {

        if (node->data == value)
        {
            searchNode = node;
            break;
        }
        else
        {
            previosNode = node;
        }
        node = node->next;
    }

    if (previosNode != NULL)
    {
        previosNode->next = searchNode->next;
        free(searchNode);
        list->size--;
    }
}

void deleteIndex(LinkedList *list, int index)
{

    if (index < list->size)
    {
        int i;
        Node *previosNode = NULL;
        Node *searchNode;
        Node *node = list->node;

        for (i = 0; node != NULL && i <= index; i++, node = node->next)
        {

            if (i == index)
            {
                searchNode = node;
            }
            else
            {
                previosNode = node;
            }
        }
        previosNode->next = searchNode->next;
        free(searchNode);
        list->size--;
    }
}

void insert(LinkedList *list, int value)
{

    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->node;

    list->node = newNode;
    list->size++;
    
}

void insertIndex(LinkedList *list, int value, int pos)
{

    if (pos <= list->size)
    {
        int i;
   

        Node *node = list->node;
        Node *previousNode = NULL;
        Node *searchNode = NULL;

        Node *newNode = malloc(sizeof(Node));
        newNode->data = value;

        for (i = 0; node != NULL && i <= pos; node = node->next, i++)
        {
            if (i == pos)
            {
                searchNode = node;
            }
            else
            {
                previousNode = node;
            }
        }

        if(previousNode != NULL)
        {
            previousNode->next = newNode;
        }

        newNode->next = searchNode;
    
        if(pos == 0) list->node = newNode;
        list->size++;

    }else{
        printf("Invalid Index\n");
    }
}

void insertEnd(LinkedList *list, int value)
{

    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    Node *nextNode = list->node;

    while (nextNode != NULL)
    {

        if (nextNode->next == NULL)
        {
            nextNode->next = newNode;
            break;
        }
        nextNode = nextNode->next;
       
    }
    list->size++;
}

void revertLinkedList(LinkedList *list){
    
    Node* node = list->node;
    Node* next = node->next;
    
    Node* aux = next;

    while(next != NULL){

        aux = aux->next;
        next->next = node;
        node = next;
        next = aux;

    }

    list->node->next  = NULL;
    list->node = node;
}   


void printLinkedList(LinkedList *list)
{

    Node *nextNode = list->node;
    printf("LinkedList => [ ");
    while (nextNode != NULL)
    {
        printf("%d, ", nextNode->data);
        nextNode = nextNode->next;
    }
    printf("]");
}

int main()
{

    LinkedList linkedList;
    initLinkedList(&linkedList);

    insert(&linkedList, 1);
    insert(&linkedList, 2);
    insertEnd(&linkedList, 4);
    insert(&linkedList, 3);
    insertIndex(&linkedList, 3, 1);

    //searchAndDelete(&linkedList, 10);
    //deleteIndex(1);
    revertLinkedList(&linkedList);
    printLinkedList(&linkedList);
    // 3 3 2 1 4
    return EXIT_SUCCESS;
}