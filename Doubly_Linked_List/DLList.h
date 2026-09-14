#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define IS_DLL_EMPTY(dll) (!dll->head && !dll->tail)

typedef void* dll_value; 

typedef struct dll_node {
    dll_value value; 
    struct dll_node* prev;
    struct dll_node* next;
} dll_node_t; 

typedef struct dll {
    dll_node_t* head;
    dll_node_t* tail;
} dll_t;

dll_t* init_dll();
dll_node_t* create_dll_node(dll_value, dll_node_t*, dll_node_t*); 
void destroy_dll(dll_t*); 
void destroy_dll_node(dll_node_t*);

bool append_dll_value(dll_t*, dll_value);
bool append_dll_value_at_pos(dll_t*, dll_value, size_t);
dll_value delete_dll_value(dll_t*);
dll_value delete_dll_value_at_pos(dll_t*, size_t);

size_t get_dll_size(dll_t*);


