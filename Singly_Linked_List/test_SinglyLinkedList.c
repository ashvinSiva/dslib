#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SinglyLinkedList.h"

void printSLL(sll_t*);

int main() {
    
    sll_t* newList = init_SLL(); 

    int a = 1; 
    int b = 2; 
    int c = 3;
    int d = 4; 
    int e = 5;
    int f = 6;
    
    printf("----------APPENDING----------\n");
    append(newList, &a);
    append(newList, &b);
    append(newList, &c);
    append(newList, &d);
    append(newList, &e);     
    printSLL(newList);

    printf("----------DELETE TAIL----------\n");
    sll_deleteTail(newList);
    printSLL(newList);

    printf("----------APPEND AT POSITION----------\n");
    append_at_pos(newList, &e, 2); 
    append_at_pos(newList, &f, 8); 
    printSLL(newList); 
    append_at_pos(newList, &f, 5); 
    printSLL(newList); 
    
    /*
    printf("----------DELETE HEAD----------\n");
    sll_deleteHead(newList); 
    printSLL(newList); 

    printf("----------DELETE AT POSITION----------\n");
    delete_at_pos(newList, 3);
    printSLL(newList); 
    */
    printf("----------REVERSE----------\n");
    reverse_sll(newList); 
    printSLL(newList);

    printf("----------CLEAR----------\n");
    clear_sll(newList); 
    printSLL(newList); 

    free_sll(newList);
    
    return 0; 
}

void printSLL(sll_t* l) {
    
    if (IS_SLL_EMPTY(l)) {
        printf("The list is empty.\n"); 
        return; 
    }


    sll_node_t *cursor = l->head; 

    while(cursor) {
        printf("%d -> ", *(int*)cursor->value); 
        cursor = cursor->next;
    } 
    printf("NULL\n");

    printf("Head of SLL: %d\n", *(int*)l->head->value);
    printf("Tail of SLL: %d\n", *(int*)l->tail->value);
    printf("Size of SLL: %zu\n", sll_size(l));
    
}
