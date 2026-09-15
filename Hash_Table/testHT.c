#include "hashtable.h"


u64 hash(size_t, const key_t);
void printHT(hashTable_t*); 

int main() {

    hashTable_t* hash_table = init_hashTable(16, hash);
    
    char* p1 = "Jason";
    ht_insert(hash_table, p1, &p1);
    char* p2 = "Tyson"; 
    ht_insert(hash_table, p2, &p2);
    char* p3 = "Dylan"; 
    ht_insert(hash_table, p3, &p3);
    char* p4 = "Baron"; 
    ht_insert(hash_table, p4, &p4);
    char* p5 = "Alvin"; 
    ht_insert(hash_table, p5, &p5);
    char* p6 = "Simon";
    ht_insert(hash_table, p6, &p6);
    char* p7 = "George", *p8 = "Sean", *p9 = "Apple", *p10 = "Monkey";
    char* p11 = "Sally", *p12 = "Ternus", *p13 = "John";
    char* p14 = "Dog", *p15 = "Coook", *p16 = "Timmy"; 
    ht_insert(hash_table, p7, &p7);
    ht_insert(hash_table, p8, &p8);
    ht_insert(hash_table, p9, &p9);
    ht_insert(hash_table, p10, &p10);
    ht_insert(hash_table, p11, &p11);
    ht_insert(hash_table, p12, &p12);
    ht_insert(hash_table, p13, &p13);
    ht_insert(hash_table, p14, &p14);
    ht_insert(hash_table, p15, &p15);
    ht_insert(hash_table, p16, &p16);
    printHT(hash_table);
    
    printf("%s\n", *(char**)ht_delete(hash_table, p16));
    printf("%s\n", *(char**)ht_delete(hash_table, p15));
    printf("%s\n", *(char**)ht_delete(hash_table, p5));
    printHT(hash_table);

    

    ht_destroy(hash_table);
    return 0; 
}

u64 hash(size_t capacity, const key_t key) {
if (!key) 
        exit(EXIT_FAILURE);

    u64 hash_code = 0; 
    
    size_t len = strlen(key);

    for (size_t i = 0; i < len; i++) {
        hash_code += key[i];
    }
    
    return hash_code % capacity;
}

void printHT(hashTable_t* ht) {
    printf("Start of Table\n");
    for (size_t i = 0; i < ht->capacity; i++) {
        printf("\t%zu\t", i);
        if (!ht->elements[i]) {
            printf("NULL\n");
        } else {
            entry_t* cursor = ht->elements[i];
            while(cursor) {
                printf("%s --> ", *(char**)cursor->value);
                cursor = cursor->next;
            }
            printf("NULL\n");
        }
    }
    printf("End of Table\n");
    
}



