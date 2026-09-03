#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef void* q_data; 

typedef struct node {
    q_data value; 
    struct node *next; 
} qNode; 

typedef struct {
    // size_t size; 
    qNode *head;    
    qNode *tail; 
} LQueue; 

// Suppose both header files have the same prototype name, but different arguement data type, will it still compile and produce the correct results?

// Might need capacity of Queue to optimize, then i could possibly add merge()
LQueue *init_LQueue(void);
qNode *create_qNode(q_data); 
bool enqueue(LQueue*, q_data); 
q_data dequeue(LQueue*); 
bool is_LQueue_Empty(LQueue*); 
void free_LQueue(LQueue*);
void free_qNode(qNode*);
size_t q_size(LQueue*); 
bool clear_LQueue(LQueue*);



