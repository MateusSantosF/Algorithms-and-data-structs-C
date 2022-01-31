

#include <stdio.h>
#include <stdlib.h>

#define TYPE int
#define TRUE 1
#define FALSE 0


typedef struct Node
{
   TYPE key;
   struct Node* next;
   struct Node* previos;

} Node;

typedef struct{
    Node* node;
}Queue;


void initQueue(Queue* queue){
    
    Node* node = malloc(sizeof(Node));
    node->next = node;
    node->previos = node;
    queue->node = node;
}


void showQueue(Queue* queue){

    Node* node = queue->node;
    
    //find last node
    while(node != node->next){
        node = node->next;
    }

    printf("Queue = [");
    while(node->previos != NULL){
        printf("%d, ", node->previos->key);
        node = node->previos;
    }
    printf(" ]\n");
}

void enqueue(Queue* queue, TYPE value){

    Node* newNode = malloc(sizeof(Node));
    newNode->key = value;

    Node* node = queue->node;
    newNode->next = node;
    newNode->previos = NULL;
    node->previos = newNode;
 

    queue->node = newNode; 

}

TYPE dequeue(Queue* queue){
    
    Node* temp = queue->node;
    Node* deleted;
    while(temp->next != temp){
        temp = temp->next;
    }
    temp = temp->previos;
    deleted = temp;
    temp->previos->next = temp->next;
    temp->next->previos = temp->previos;
    
    return deleted->key;
}


int main(){

    Queue queue;
    initQueue(&queue);
  

    enqueue(&queue, 4);
    enqueue(&queue, 10);
    enqueue(&queue, 12);
    enqueue(&queue, 14);

    showQueue(&queue);
    printf("Dequeue=> %d\n",  dequeue(&queue) );
    printf("Dequeue=> %d\n",  dequeue(&queue) );
    showQueue(&queue);

    return EXIT_SUCCESS;
}