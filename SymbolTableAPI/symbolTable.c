
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int key;
    int value;
    struct node* next;
}Node;

typedef struct{
    Node* node;
    int size;

}LinkedSymbolTable;

typedef int Key;
typedef int Value;

LinkedSymbolTable linkedSymbolTable;


void put(Key key, Value value){

    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if(linkedSymbolTable.node == NULL){
        linkedSymbolTable.node = newNode;
    }else{

        Node* temp = linkedSymbolTable.node;
        while(temp->next != NULL){
            if(temp->key == key){
                temp->value = value; // match update value
              
                break;
            }
            temp = temp->next;
        }
        temp->next = newNode; // miss match -> insert 
    }
}

Value get(Key key){

    Node* temp = linkedSymbolTable.node;
    while(temp != NULL){
        if(temp->key == key){
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void initLinkedSymbolTable(LinkedSymbolTable* t){
    printf("============ INIT LinkedSymbolTable ================\n");
    t->node = NULL;
    t->size = 0;
}


int main(){

    initLinkedSymbolTable(&linkedSymbolTable);

    put(1,5);
    put(2,6);
    put(3,10);
    put(4,12);
    put(5,14);
    put(6,67);

    printf("Search Key 4\n");
    printf("\tValue => %d\n", get(4));
    printf("Search Key 3\n");
    printf("\tValue => %d\n", get(3));

    return EXIT_SUCCESS;
}