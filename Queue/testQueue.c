#include <stdio.h>

#include "Queue.h"

void print_LQueue(LQueue*); 

int main() {
    
    int a = 0; 
    int b = 32; 
    int c = 24; 
    int d = 39; 
    int e = 29; 
    int f = 938; 
  
    LQueue* queue = init_LQueue(); 
    
    enqueue(queue, &a); 
    enqueue(queue, &b); 
    enqueue(queue, &c); 
    enqueue(queue, &d); 
    enqueue(queue, &e); 
    enqueue(queue, &f);

    printf("-----TEST PRINT-----\n"); 
    print_LQueue(queue);  
    printf("Size of Linked Queue: %zu\n", q_size(queue)); 

    printf("-----TEST DEQUEUE-----\n");
    dequeue(queue); 
    print_LQueue(queue); 
    printf("Size of Linked Queue: %zu\n", q_size(queue)); 

    printf("-----TEST CLEAR-----\n");
    clear_LQueue(queue); 
    printf("Size of Linked Queue: %zu\n", q_size(queue)); 
    dequeue(queue);


    free_LQueue(queue);

    return 0; 
}

void print_LQueue(LQueue* queue) {
    
    if (is_LQueue_Empty(queue)) {
        printf("Queue is empty\n"); return;
    }


    qNode* cursor = queue->head;  

    while(cursor != NULL) {
       
        printf("%d <- ", *(int*)cursor->value);
        if (!cursor->next) 
            printf("NULL\n");
    
        cursor = cursor->next; 
    }
    printf("Head of Queue: %d\n", *(int*)queue->head->value); 
    printf("Tail of Queue: %d\n", *(int*)queue->tail->value); 

}





