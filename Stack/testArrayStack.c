#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayStack.h"

int main() {
    
    int a = 2, b = 4, c = 6, d = 8, e = 10; 
    ArrayStack *stack = init_ArrayStack(256); 
    if (is_ArrayStack_Empty(stack)) {
        printf("1. The Array Stack is Empty\n"); 
    }

    push_ArrayStack(stack, &a);
    push_ArrayStack(stack, &b);   
    push_ArrayStack(stack, &c);
    push_ArrayStack(stack, &d);
    push_ArrayStack(stack, &e);
    
    if (!is_ArrayStack_Empty(stack)) {
        printf("2. The Array Stack is not Empty\n"); 
    }

    if (is_ArrayStack_Full(stack)) {
        printf("3. The Array Stack is Full\n"); 
    } else {
        printf("3. The Array Stack is not Full\n"); 
    }
    
    /* To actually print the value, you have to cast the return type as
     * an integer pointer [to get the memory address from void*] and then 
     * dereference it to access the value. This is because the function 
     * will try to print out the memory address as the integer, which is 
     * not what we want. */
    for (int i = 0; i < 2; i++) {
        printf("4. Popped value: %d\n", *(int*)pop_ArrayStack(stack)); 
    }

    free_ArrayStack(stack);
    
    return 0; 
}
