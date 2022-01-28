
#include <stdio.h>
#include <malloc.h>


#define MAX 50
typedef int KEY;

typedef struct
{
    KEY key;
    /* data */  
}  REGISTER ;

typedef struct 
{
    REGISTER a[50+1];
    int size;
} LIST;

void initList(LIST* l){
    l->size = 0;
}

int getSize(LIST* l){
    return l->size;
}

void showList(LIST* l){

 
    printf("List: \n");
    int i;
    for ( i = 0; i < l->size; i++){
        printf("%d ", l->a[i].key);
    }

    printf("\n");
}
int searchSentinel(LIST *l, KEY key){

    int i = 0;
    l->a[l->size].key = key;

    while(l->a[i].key != key){
        i++;
    }

    return i == l->size ? -1 : i;
    
}
int searchElement(LIST* l,  KEY key){

    int i = 0;
    while( i < l->size){
        if(l->a[i].key ==  key){
            return i;
        }else{
            i++;
        }   
    }
    return -1;
}

int insertElement(LIST *l, int index, REGISTER r ){

    if(l->size != MAX && index < MAX && index <= l->size){
        
        int i;
        REGISTER oldElement;
        for( i = index; i < l->size; i++){

            oldElement = l->a[i];
            if(i == index){
                l->a[i+1] = l->a[i];
            }else{
                l->a[i+1] = oldElement;
            }   
        }
        l->a[index] = r;
        l->size++;
        return 1;

    }else{
        return 0;
    }
}

void restartList(LIST* l){
    l->size = 0;
}

int deleteElement(LIST* l, KEY key){

    int index = searchElement(l,key);

    if(index > -1){
        int i;
   
        for( i = index; i < l->size; i++){
            l->a[i] = l->a[i+1];
        }
        l->size--;
        return 1;
    }else{
        return 0;
    }
}

int insertionShort(LIST* l, REGISTER r){

    if(l->size == MAX){
        return 0;
    }else{

        int pos = l->size;
        while( pos > -1 && l->a[pos-1].key > r.key){
            l->a[pos] = l->a[pos - 1];
            pos--;
        }
        l->a[pos] = r;
        l->size++;
    }
}

int binarySearch(LIST* list, KEY key){

    int l = 0, m, r = list->size-1;

    while(l < r){
        m = (int) (l + r)/2;

        if( list->a[m].key == key){
            return m;
        }else{

            if(list->a[m].key > key ){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
    }

    return -1;

}

int main(){

    LIST l;

    REGISTER r;
    r.key = 2;

    REGISTER r2;
    r2.key = 6;

    REGISTER r3;
    r3.key = 3;

    initList(&l);

    printf("Size=%d\n", getSize(&l));
    printf("%d\n", insertElement(&l, 0, r));
    printf("%d\n", insertElement(&l, 1, r));
    printf("%d\n", insertElement(&l, 2, r));
    printf("%d\n", insertElement(&l, 3, r2));
    printf("%d\n", deleteElement(&l,6));

    printf(" Search sentinel => %d\n", searchSentinel(&l, 2));

    //===== INSERTION SHORT =============
    insertionShort(&l, r);
    insertionShort(&l, r2);
    insertionShort(&l, r);
    insertionShort(&l, r3);
    showList(&l);

    printf("Index %d", binarySearch(&l, r3.key));
    restartList(&l);

    return EXIT_SUCCESS;
}