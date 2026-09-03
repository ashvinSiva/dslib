#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "Queue.h"

LQueue *init_LQueue(void) {
    LQueue *queue = malloc(sizeof(LQueue)); 
    if (!queue) {
        printf("A queue is not memory allocated\n");
        return NULL; 
    };

    queue->head = NULL;    
    queue->tail = NULL;

    return queue; 

}

bool enqueue(LQueue *queue, q_data value) {

    if (!queue || !value) {
        printf("A node cannot be created\n"); 
        return false; 
    }
    
    qNode *newQNode = create_qNode(value); 

    if (!queue->head && !queue->tail) {
        queue->head = newQNode; 
        queue->tail = newQNode; 
        return true; 
    }

    assert(!queue->tail->next); 
    queue->tail->next = newQNode; 
    queue->tail = newQNode; 
    return true; 
  
}

q_data dequeue(LQueue *queue) {
    
    if (is_LQueue_Empty(queue)) {
        return NULL; 
    }

    q_data saved = queue->head->value; 
    qNode *tmp = queue->head; 
    queue->head = queue->head->next; 
    free_qNode(tmp); 
    tmp = NULL; 
    return saved;
    
}

void free_LQueue(LQueue* queue) {
    
    if (!queue->head && !queue->tail) {
        free(queue); 
        queue = NULL; 
        return; 
    }
    
    if (!queue) {
        return; 
    }
    
    qNode* cursor = queue->head; 
    while (cursor != NULL) {
        free_qNode(cursor); 
        cursor = cursor->next; 
    }


    return;
}


void free_qNode(qNode* node) {
   

    node->next = NULL;  
    free(node); 
    node = NULL; 
    return; 
}


bool is_LQueue_Empty(LQueue* queue) {

    if (queue->head == NULL && 
        queue->tail == NULL) {
        printf("Queue is Empty\n");
        return true; 
    }

    return false; 
}



qNode *create_qNode(q_data value) {
    qNode *newNode = malloc(sizeof(qNode)); 
    if (!newNode) {
        printf("New node cannout be created\n"); 
        return NULL; 
    }

    newNode->value = value; 
    newNode->next = NULL; 

    return newNode; 
}

size_t q_size(LQueue* queue) {
    
    if (is_LQueue_Empty(queue)){
        return 0;
    }

    size_t count = 0;
    qNode* cursor = queue->head; 

    while (cursor) {
        count++;
        cursor = cursor->next; 
    }

    return count;
}

bool clear_LQueue(LQueue* queue) {
   if (is_LQueue_Empty(queue)) 
        return false;

   qNode* cursor = queue->head; 
   qNode* tmp = NULL;

   while(cursor) {
        tmp = cursor; 
        cursor = cursor->next; 
        free_qNode(tmp); 
   }

   queue->head = NULL; 
   queue->tail = NULL; 

   return true;

   
}




