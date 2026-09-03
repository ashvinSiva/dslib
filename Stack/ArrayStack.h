#include <stdint.h>
#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>

typedef void* value_ptr;
typedef int64_t i64;
typedef struct {
    i64 top; 
    size_t capacity;
    value_ptr* array; // Must point to a stream of bytes
} ArrayStack;


/* Initializes an Array Stack by accepting the capacity of the Stack */
ArrayStack *init_ArrayStack(size_t); 
/* Pushes a value in the Array Stack */
bool push_ArrayStack(ArrayStack*, value_ptr); 
/* Pops and returns the value freom the Array Stack */
value_ptr pop_ArrayStack(ArrayStack*);
/* Checks if the Stack Array is Empty */
bool is_ArrayStack_Empty(ArrayStack*);
/* Checks if the Stack Array is Full */
bool is_ArrayStack_Full(ArrayStack*);
/* Clears the Array Stack, removing all values and reset top */
bool clear_ArrayStack(ArrayStack*); 
/* Returns the size of the Array Stack */
size_t get_ArrayStack_size(ArrayStack*); 
/* Returns the top value of the Array Stack */
i64 ArrayStack_peek(ArrayStack*);
/* Free Array Stack */
void free_ArrayStack(ArrayStack*);
