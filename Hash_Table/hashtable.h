#include <stdio.h> 
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t u32;
typedef uint64_t u64; 
typedef char* key_t; // Should i do char* for simplicity?
typedef void* value_t; 

// Function [pointer] type definition (similar to interface functions in Java)
// Syntax: typedef return_type (*functionName)(parameter_types);
typedef u64 (hash_f)(size_t, const key_t);

// Entry Node
typedef struct entryNode {
    key_t key;
    value_t value; 
    struct entryNode* next; 
} entry_t;

typedef struct hash_table {
    size_t capacity;
    hash_f* hash; 
    entry_t** elements;
} hashTable_t; 

hashTable_t* init_hashTable(size_t capacity, hash_f* hf);
entry_t* init_entry(key_t, value_t); 
u64 ht_index(hashTable_t*, key_t); 
void ht_destroy(hashTable_t*); 
void destroy_entry(entry_t*); 

bool ht_insert(hashTable_t*, key_t, value_t);
bool ht_lookup(hashTable_t*, key_t, value_t); 
value_t ht_delete(hashTable_t*, key_t); 
//value_t ht_get(hashTable_t*, key_t); 







