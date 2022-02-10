
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    int key;
} Cell;

int size = 0;
Cell heap[50];



void insert(int key, int value){

    Cell newCell;
    newCell.key = key;
    newCell.value = value;

    heap[++size] = newCell;
    swim(size);
}

Cell deleteMax(){

    //remove o primeiro elemento (Maior prioridade) e insere o último elemento do último nível na raiz.
    Cell deleted = heap[1];
    heap[1] = heap[size--];
    sink(1);  

    return deleted;  
}

Cell max(){
    return heap[1];
}

void sink(int k ){

    while( less(k, k*2 ) || less(k, k*2 + 1)){

        if(less(k, k*2 )){
            exchange(k,  k*2);
            k = k*2;
        }else{
            exchange(k, k*2 + 1); 
            k = k*2 + 1;
        }
    }
}

void swim(int k){
    // k = posição do novo elemento inserido
    while( k > 1 && less( k/2, k) ){
        exchange(k/2, k);
        k = k/2;
    }
}

int less(int i, int j){
    return heap[i].key < heap[j].key;
}
   

void exchange(int i, int j){
    // i = pai
    // j = filho
    Cell temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}


void showHeap(){

    int i;

    printf("HEAP = [ ");
    for(i = 1; i <= size; i++){
        printf("{key: %d,value: %d}, ", heap[i].key, heap[i].value);
    }
    printf("]\n");
}

int main(){
    printf("================ MAX BINARY HEAP ==================== \n\n\n");
    
    insert(3,1);
    insert(9,12);
    insert(2,3);
    printf("Delete key = %d\n", deleteMax().key);
    insert(1,3);
    insert(4,4);
    insert(5,3);
    printf("Delete key = %d\n", deleteMax().key);
    showHeap();
    printf("Current Max Key = %d", max().key);
    printf("\n\n===================================================== \n\n\n");
    
    return EXIT_SUCCESS;
}