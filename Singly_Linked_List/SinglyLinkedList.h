#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define IS_SLL_EMPTY(sll) (!sll->head && !sll->tail)

typedef void* sll_data; 

typedef struct sll_node {
    sll_data value; 
    struct sll_node* next; 
} sll_node_t; 

typedef struct SinglyLinkedList {
    sll_node_t* head; 
    sll_node_t* tail; 
} sll_t; 

// Should i add capacity?
// initializes a new singly linked list
sll_t* init_SLL();
// frees list, making sure it's empty
void free_sll(sll_t*); 
// creates a unique node for the list by accepting a pointer value
sll_node_t* create_sll_node(sll_data);
// frees sll_node_t type node 
void free_sll_node(sll_node_t*); 
// gets size of singly linked list
size_t sll_size(sll_t*); 
// Which is safer: return void or bool
// adds the value on the tail of the list
void append(sll_t*, sll_data); 
// deletes tail node and points to new tail
void sll_deleteTail(sll_t*); 
// deletes head and points to new head
void sll_deleteHead(sll_t*);
// adds a value at a certain position in the list
void append_at_pos(sll_t*, sll_data, size_t); 
// removes a value from a certain position in the list
void delete_at_pos(sll_t*, size_t); 
// gets value from the list by a certain position given in arguments
sll_data sll_get_value_atPos(sll_t*, size_t); 
// verifies if the list contains the value, otherwise not 
bool sll_search(sll_t*, sll_data); 
// the list is reversed, ending up with new head and new tail
bool reverse_sll(sll_t*); 
// clears/rests the singly linked list by erasing all values
bool clear_sll(sll_t*); 

