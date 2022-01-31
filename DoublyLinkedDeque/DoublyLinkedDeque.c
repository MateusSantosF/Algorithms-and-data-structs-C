

#include <stdlib.h>
#include <stdio.h>


#define TYPE int

typedef struct aux{
    TYPE key;
    struct aux* next;
    struct aux* previos;
}Node;

typedef struct{
    Node *node;
    int size;
}DoubleEndedQueue;


void initDoubleEndedQueue(DoubleEndedQueue* queue){
    
    queue->node =  malloc(sizeof(int));
    queue->node->next = queue->node;
    queue->node->previos = queue->node;
    queue->size++;
}

void addFirst(DoubleEndedQueue* queue, TYPE value){

    Node* newNode =  malloc( sizeof(Node) );
    newNode->key = value;
    newNode->next = queue->node;
    newNode->previos = NULL;
    queue->node->previos = newNode;
    queue->node = newNode;
    queue->size++;
}

void removeFirst(DoubleEndedQueue* queue){

    Node* node = queue->node;

    node->next->previos = NULL;
    queue->node = node->next;
}

void removeLast(DoubleEndedQueue* queue){
    Node* node = queue->node;

    while(node != node->next){
        node = node->next;
    }

    node->previos->previos->next = node;
    node->previos = node->previos->previos;
}

int getSize(DoubleEndedQueue* queue){
    int tam = 0;

    Node* node = queue->node;
    while(node != node->next){
        tam++;
        node = node->next;
    }

    return tam;
}

int isEmpty(DoubleEndedQueue* queue){
    return getSize(queue) > 0 ? 0 : 1;
}

void addLast(DoubleEndedQueue* queue, TYPE value){

    Node* newNode =  malloc( sizeof(Node) );
    newNode->key = value;
    
    Node* node = queue->node;
    while(node != node->next){
        node = node->next;
    }
    node->previos->next = newNode;
    newNode->previos = node->previos;
    newNode->next = node;
    node->previos = newNode;
   
    queue->size++;
}

void showQueue(DoubleEndedQueue* queue){

    Node* node = queue->node;
    
    printf("DoubleEndedQueue => [ ");
    while(node != node->next){
        printf("%d, ",node->key);
        node = node->next;
    }

    printf(" ]\n");
}

int main(){

    DoubleEndedQueue queue;
    initDoubleEndedQueue(&queue);

    printf("isEmpty() => %d\n", isEmpty(&queue));
    addFirst(&queue, 5);
    addFirst(&queue, 21);
    addFirst(&queue, 4);
    addFirst(&queue, 7);

    showQueue(&queue);

    addLast(&queue, 600);
    addLast(&queue, 700);
    addLast(&queue, 800);

    removeFirst(&queue);
    removeFirst(&queue);
    addFirst(&queue, 9);
    removeLast(&queue);
    removeLast(&queue);
    addLast(&queue, 300);
    showQueue(&queue);
    printf("isEmpty() => %d\n", isEmpty(&queue));
    printf("getSize => %d", getSize(&queue));

    return EXIT_SUCCESS;
}