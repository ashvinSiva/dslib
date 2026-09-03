#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "ArrayStack.h"

ArrayStack *init_ArrayStack(size_t capacity) {

    ArrayStack *stack_array = (ArrayStack*)malloc(sizeof(ArrayStack));   
    if (!stack_array) {
        fprintf(stderr, "The Array Stack cannot be malloced\n"); 
        return NULL; 
    }

    *stack_array = (ArrayStack) { 
        .array = (value_ptr*)malloc(sizeof(value_ptr)*capacity), 
        .top = -1, 
        .capacity = capacity 
    };

    return stack_array;
}

bool is_ArrayStack_Empty(ArrayStack *self) {
    return self->top == -1;
}

bool is_ArrayStack_Full(ArrayStack *self) {
    return ((size_t)self->top == self->capacity);
}

size_t get_ArrayStack_size(ArrayStack *self) {
    
    if (is_ArrayStack_Empty(self)) {
        return 0;
    } else if (is_ArrayStack_Full(self)) {
        return self->capacity;
    } else {
        size_t top = (size_t)self->top; 
        top += 1;
        return top; 
    }
}

i64 ArrayStack_peek(ArrayStack *self) {
    return self->top; 
}

bool push_ArrayStack(ArrayStack *self, value_ptr data) {
    if (is_ArrayStack_Full(self)) 
        return false;
    if (!data) 
        return false;  

    i64 top = self->top;
    top += 1;
    self->array[top] = data;
    self->top = top;
    
    return true;
   
}

value_ptr pop_ArrayStack(ArrayStack *self) {

    if (is_ArrayStack_Empty(self)) {
        printf("The Array Stack is Empty\n"); 
        return NULL;
    }

    size_t top = self->top; 
    value_ptr saved = self->array[top];
    self->array[top] = NULL;  
    top -= 1;
    self->top = top; 

    return saved; 
}

bool clear_ArrayStack(ArrayStack *self) {
    
    if (is_ArrayStack_Empty(self))
        return true; 
    if (!self) 
        return false;

    i64 count = self->top; 
    while (count != -1) {
        self->array[count] = NULL;   
        free(self->array[count]);
        count -= 1;
    }
    self->top = -1; 

    return true; 

}

void free_ArrayStack(ArrayStack *self) {
     
    if (!is_ArrayStack_Empty(self)) 
        clear_ArrayStack(self);
    
    free(self->array); 
    free(self);
    self = NULL; 
}

