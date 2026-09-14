#include "DLList.h"


void printDLL(dll_t*);
void printDLL_reverse(dll_t*);

int main() {
    
    dll_t* list = init_dll();

    int a = 4; 
    int b = 3;
    int c = 9; 
    int d = 19; 
    int e = 30; 
    int f = 42; 
    int g = 92; 
    int h = 100; 
    int i = 2; 
    int j = 0; 

    printf("==========APPEND AT TAIL==========\n");
    append_dll_value(list, &a);
    append_dll_value(list, &b);
    append_dll_value(list, &c);
    append_dll_value(list, &d);
    append_dll_value(list, &e);
    append_dll_value(list, &f);
    append_dll_value(list, &g);
    append_dll_value(list, &h);
    append_dll_value(list, &i);
    append_dll_value(list, &j); 
    printDLL(list);
    printDLL_reverse(list);

    printf("==========SIZE OF LIST==========\n");
    printf("Size of List: %zu\n", get_dll_size(list));

    printf("==========DELETE AT TAIL==========\n");
    printf("Deleted node value: %d\n", *(int*)delete_dll_value(list));
    printf("Deleted node value: %d\n", *(int*)delete_dll_value(list));
    printf("Deleted node value: %d\n", *(int*)delete_dll_value(list));
    
    printf("Size of List: %zu\n", get_dll_size(list));
    printf("Head: %d\n", *(int*)list->head->value);
    printf("Tail: %d\n", *(int*)list->tail->value);
    printDLL_reverse(list);
    printDLL(list); 
    
    printf("==========APPEND AT POS==========\n");
    append_dll_value_at_pos(list, &j, 2);
    append_dll_value_at_pos(list, &h, 4);
    append_dll_value_at_pos(list, &i, 19);
    printDLL(list);

    printf("==========DELETE AT POS==========\n");
    delete_dll_value_at_pos(list, 3);
    delete_dll_value_at_pos(list, 0);
    delete_dll_value_at_pos(list, 17);
    printDLL(list);

    destroy_dll(list);
    return 0; 
}

void printDLL(dll_t* dll) {
    
    if(IS_DLL_EMPTY(dll)) {
        return;
    }
    
    dll_node_t* cursor = dll->head;
    while (cursor) {
        printf("%d (%p) --> ", *(int*)cursor->value, cursor);
        cursor = cursor->next;
    }
    printf("NULL\n");

}

void printDLL_reverse(dll_t* dll) {

    if (IS_DLL_EMPTY(dll)) {
        return;
    }

    dll_node_t* cursor = dll->tail; 
    while(cursor) {
        printf("%d --> ", *(int*)cursor->value);
        cursor = cursor->prev; 
    }
    printf("NULL\n");
}
