#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>

#include "SinglyLinkedList.h"


sll_t* init_SLL() {
    
    sll_t* newList = malloc(sizeof(sll_t));
    
    if (!newList) {
        printf("A new list cannot be memory allocated\n");
        exit(EXIT_FAILURE);  
    }

    newList->head = NULL; 
    newList->tail = NULL; 

    return newList; 
}  

sll_node_t* create_sll_node(sll_data value) {
    
    sll_node_t* newNode = malloc(sizeof(sll_node_t)); 

    if(!newNode) {
        printf("A new node is not memory allocated\n"); 
        exit(EXIT_FAILURE); 
    }

    newNode->value = value; 
    newNode->next = NULL; 

    return newNode; 
}

size_t sll_size(sll_t* sll) {
    size_t count = 0; 
    sll_node_t* cursor = sll->head; 

    while(cursor) {
        count++; 
        cursor = cursor->next; 
    }

    return count; 

}


void append(sll_t* sll, sll_data value) {
    sll_node_t* newNode = create_sll_node(value); 

    if(IS_SLL_EMPTY(sll)) {
        sll->head = newNode; 
        sll->tail = newNode; 
    }

    sll->tail->next = newNode; 
    sll->tail = newNode; 
}

void append_at_pos(sll_t* sll, sll_data value, size_t pos) {
       
    if (pos > sll_size(sll)) {
        printf("The position is greater than the list size\n"); 
        return;
        //exit(EXIT_FAILURE); 
    }

    sll_node_t* cursor = sll->head;

    for(size_t i = 1; i < pos - 1; i++) {
        cursor = cursor->next; 
    }

    sll_node_t* newNode = create_sll_node(value); 

    newNode->next = cursor->next; 
    cursor->next = newNode; 
}

void sll_deleteTail(sll_t* sll) {

    if (IS_SLL_EMPTY(sll)) {
        printf("There is no tail; the list is empty\n"); 
        exit(EXIT_FAILURE); 
    }

    sll_node_t* cursor = sll->head;

    while(cursor->next->next){
        cursor = cursor->next;
    }

    free_sll_node(sll->tail); 

    sll->tail = cursor; 
    cursor->next = NULL; 
}

void sll_deleteHead(sll_t* sll) {
    
    if (IS_SLL_EMPTY(sll)) {
        printf("There is no tail; the list is empty\n"); 
        exit(EXIT_FAILURE); 
    } 

    if (sll->head == sll->tail) {
        free_sll_node(sll->head); 
        sll->tail = NULL; 
        return;
    }

    sll_node_t* cursor = sll->head->next; 
    free_sll_node(sll->head); 
    sll->head = cursor; 
}

void delete_at_pos(sll_t* sll, size_t pos) {
    
    if (pos == 1) {
        sll_deleteHead(sll);
        return;
    }

    if (pos == sll_size(sll)) {
        sll_deleteTail(sll); 
        return;
    }

    sll_node_t* cursor = sll->head;
    for(size_t i = 1; i < pos - 1; i++) {
        cursor = cursor->next; 
    }

    sll_node_t* tmp = cursor->next->next; 
    free_sll_node(cursor->next); 
    cursor->next = tmp; 
}

sll_data sll_get_value_atPos(sll_t* sll, size_t pos) {
    
    sll_node_t* cursor = sll->head; 
        
    for (size_t i = 1; i <= pos; i++) {
        cursor = cursor->next; 
    }

    return cursor->value; 
}

bool sll_search(sll_t* sll, sll_data value) {
    
    if (IS_SLL_EMPTY(sll)) {
        printf("The list is empty.\n"); 
        return false;
    }
    
    sll_node_t* cursor = sll->head;
    for (size_t i = 1; i <= sll_size(sll); i++) {
        if (cursor->value == value) // Possible bug?
            return true;
        else 
            cursor = cursor->next;
    }       
    
    return false; 
}

bool reverse_sll(sll_t* sll) {

    if (IS_SLL_EMPTY(sll)) {
        printf("The list is empty.\n"); 
        return false;
    }
    
    sll_node_t *prev = NULL, *curr = sll->head, *next = NULL;
  
    while (curr) {
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next;
    } 

    sll_node_t* tmp = sll->head; 
    sll->head = sll->tail; 
    sll->tail = tmp; 
    
    return true; 
}

bool clear_sll(sll_t* sll) {
    
    if(IS_SLL_EMPTY(sll)) {
        return true; 
    }
    
    sll_node_t* cursor = sll->head; 
    sll_node_t* tmp;
    while (cursor) {
        tmp = cursor;
        cursor = cursor->next;
        free_sll_node(tmp); 
    }
    tmp = NULL; 

    sll->head = NULL; 
    sll->tail = NULL; 
    return true;
}


void free_sll_node(sll_node_t* node) {

    node->value = NULL; 
    node->next = NULL; 

    free(node);
    node = NULL; 
}

void free_sll(sll_t* sll) {

    sll_node_t* cursor = sll->head; 
    sll_node_t* tmp; 

    while(cursor) {
        tmp = cursor; 
        cursor = cursor->next; 
        free_sll_node(tmp); 
        tmp = NULL; // Does it matter? Is it safer and efficient?
    }

    free(sll); 
    sll = NULL;    
}
