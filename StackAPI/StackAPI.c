
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

    stack->a[stack->size++] = item;
    
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

int main(){


    //STACK STATIC 
    StackStatic stack;
    initStack(&stack);

    push(&stack, 2);
    printf("size=> %d\n", stack.size );
    push(&stack, 3);
    push(&stack, 3);
    push(&stack, 3);
    push(&stack, 3);
    push(&stack, 3);
    push(&stack, 3);

    printf("size=> %d\n", stack.size );

    printf("%d\n", pop(&stack).key);
    printf("IsEmpty? %d\n", isEmpty(&stack));
    printf("%d\n", pop(&stack).key);
    printf("IsEmpty? %d\n", isEmpty(&stack));
    push(&stack, 5);
    printf("%d\n", pop(&stack).key);

    // ==========================

    return EXIT_SUCCESS;
}