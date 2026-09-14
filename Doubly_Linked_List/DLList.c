#include "DLList.h"

dll_t* init_dll() {
    
    dll_t* dll = malloc(sizeof(dll_t));
    if(!dll) { return NULL; }
    
    dll->head = NULL; 
    dll->tail = NULL; 

    return dll;
}

dll_node_t* create_dll_node(dll_value value, dll_node_t* next, dll_node_t* prev) {
    
    if (!value) { return NULL; }
    dll_node_t* node = malloc(sizeof(dll_node_t));

    if (!node) { return NULL; }
    
    node->value = value; 
    node->prev = prev; 
    node->next = next; 

    return node; 
}

size_t get_dll_size(dll_t* dll) {

    size_t idx = 0;
    dll_node_t* cursor = dll->head; 
    while(cursor) {
        idx++; 
        cursor = cursor->next; 
    }
    return idx; 
}

bool append_dll_value(dll_t* dll, dll_value value) {
    
    dll_node_t* newNode;

    if (IS_DLL_EMPTY(dll)) {
        newNode = create_dll_node(value, NULL, NULL);
        dll->head = newNode; 
        dll->tail = newNode; 
    } else {
        newNode = create_dll_node(value, NULL, dll->tail); 
        dll->tail->next = newNode;
        dll->tail = newNode; 
    }
    return true;
}

bool append_dll_value_at_pos(dll_t* dll, dll_value value, size_t pos) {
    dll_node_t* newNode; 
    
    if (pos <= 0 || pos > get_dll_size(dll)) {
        return false; 
    }

    if (pos == 1 && dll->head) {
        newNode = create_dll_node(value, dll->head, NULL);
        dll->head->prev = newNode; 
        dll->head = newNode; 
        return true; 
    }

    if (pos == get_dll_size(dll)) {
        return append_dll_value(dll, value); 
    }
    
    dll_node_t* cursor = dll->head;
    for (size_t i = 1; i < pos; i++) {
        cursor = cursor->next;
    }
    newNode = create_dll_node(value, cursor->next, cursor);
    cursor->next = newNode;
    newNode->next->prev = newNode; 

    return true;

}

dll_value delete_dll_value(dll_t* dll) {
    
    if (IS_DLL_EMPTY(dll)) {
        return NULL; 
    } 
    
    dll_value saved;
    if (dll->head == dll->tail) {
        saved = dll->head->value; 
        destroy_dll_node(dll->head);
        dll->head = dll->tail = NULL; 
        return saved; 
    }   
    
    saved = dll->tail->value;
    dll->tail = dll->tail->prev; 
    destroy_dll_node(dll->tail->next); 
    dll->tail->next = NULL; 
    
    return saved; 
}

dll_value delete_dll_value_at_pos(dll_t* dll, size_t pos) {
    
    if (pos <= 0 || pos > get_dll_size(dll)) {
        return NULL;
    }

    if (IS_DLL_EMPTY(dll)){
        return NULL;
    }
    
    dll_value saved;
    if (pos == get_dll_size(dll)) {
        delete_dll_value(dll);
    }

    if (dll->head == dll->tail) {
        saved = dll->head->value;
        destroy_dll_node(dll->head);
        return saved;
    }

    if (dll->head->next == dll->tail) {
        saved = dll->tail->value; 
        destroy_dll_node(dll->tail); 
        dll->tail = dll->head; 
        return saved;
    }
    
    dll_node_t* cursor = dll->head;
    for (size_t i = 0; i < pos; i++){
        cursor = cursor->next;
    }
    dll_node_t* tmp = cursor->next->next; 
    saved = cursor->next->value;
    destroy_dll_node(cursor->next);
    cursor->next = tmp; 
    tmp->prev = cursor;
    
    return saved; 
}




void destroy_dll_node(dll_node_t* node) {
    
    node->prev = NULL; 
    node->next = NULL; 
    node->value = NULL; 

    free(node); 
    node = NULL;
}

void destroy_dll(dll_t* dll) {
    
    if (dll->head && dll->tail) {
        destroy_dll_node(dll->head);
        dll->head = NULL; 
        dll->tail = NULL; 
    }

    dll_node_t* cursor = dll->head; 
    while(cursor) {
        cursor = cursor->next; 
        destroy_dll_node(cursor->prev);
        cursor->prev = NULL; 
    }

}
