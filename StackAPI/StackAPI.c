
#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define  TYPE int
#define INIT_MAX 50
#define bool int


typedef struct {
    TYPE key;
}Item;

typedef struct {
    Item a[INIT_MAX];
    int size;
}StackStatic;


void initStack(StackStatic* stack){
    stack->size = -1;

}

void push(StackStatic* stack, TYPE value){

    Item item;
    item.key = value;

    stack->a[++stack->size] = item;

}

int length(Item* item){
    return sizeof(Item);
}

Item pop(StackStatic* stack){


    return stack->a[--stack->size];
}

bool isEmpty(StackStatic* stack){
    return stack->size < 0 ? TRUE : FALSE;
}

int size(StackStatic* stack){
    return stack->size + 1;
}

Item peek(StackStatic* stack){
    return stack->a[stack->size];
}

int main(){


    //STACK STATIC 
    StackStatic stack;
    initStack(&stack);

    push(&stack, 1);
    printf("Push 1\n");
    push(&stack, 2);
    printf("Push 2\n");
    push(&stack, 3);
    printf("Push 3\n");
    push(&stack, 4);
    printf("Push 4\n");
    push(&stack, 5);
    printf("Push 5\n");

    printf("Size => %d\n", size(&stack));

    printf("Pop => %d\n", pop(&stack).key);
    printf("size=> %d\n", size(&stack));

    printf("IsEmpty? %d\n", isEmpty(&stack));
    printf("Pop => %d\n", pop(&stack).key);
    printf("size=> %d\n", size(&stack));
    printf("IsEmpty? %d\n", isEmpty(&stack));
    printf("Pop => %d\n", pop(&stack).key);
    printf("Stack Size=> %d\n", size(&stack));
    printf("Peek() => %d", peek(&stack).key);

    // ==========================

    return EXIT_SUCCESS;
}