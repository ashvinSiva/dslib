#include "hashtable.h"

inline u64 ht_index(hashTable_t* ht, key_t key) {
    return ht->hash(ht->capacity, key); 
}

hashTable_t* init_hashTable(size_t capacity, hash_f *hf) {

    hashTable_t* ht = malloc(sizeof(hashTable_t)); 

    if (!ht) {
        printf("Cannot initialize new Hash Table. The pointer is NULL\n"); 
        return NULL; 
    }

    ht->capacity = capacity;
    ht->hash = hf; 
    ht->elements = calloc(sizeof(entry_t*), capacity);

    return ht; 
}

bool ht_insert(hashTable_t* ht, key_t key, value_t value) {
    
    if (!key || !value) 
        return false;
    
    u64 idx = ht->hash(ht->capacity, key);
   
    entry_t* entry = init_entry(key, value);
   
    // What if we are adding the same key again? 
    // Do we still add the second key or not?

    if (!ht->elements[idx]) {
        ht->elements[idx] = entry; 
    } else {
        entry_t* cursor = ht->elements[idx];
        while(cursor->next) {
            cursor = cursor->next;
        }
        cursor->next = entry;
    }
    return true;
}

entry_t* init_entry(key_t key, value_t value) {

    entry_t* newEntry = malloc(sizeof(entry_t));
    if(!newEntry) {
        printf("Cannot initialize new entry. The pointer is NULL\n");
        return NULL;
    }
    
    newEntry->key = key; 
    newEntry->value = value; 
    newEntry->next = NULL; 

    return newEntry;
}

bool ht_lookup(hashTable_t* ht, key_t key, value_t value) {
    
    if (!key || !value) 
        return false;
    
    u64 idx = ht->hash(ht->capacity, key);
    entry_t* cursor = ht->elements[idx];

    while(cursor) {
        if (cursor->value == value) 
            return false;
        cursor = cursor->next; 
    } 

    return true;
}

value_t ht_delete(hashTable_t* ht, key_t key) {

    if (!key) 
        return NULL; 
    
    u64 idx = ht_index(ht, key);
    entry_t* cursor = ht->elements[idx];
    value_t saved = NULL; 

    if (!cursor)
        return NULL; 

    while (cursor->key != key) {
        cursor = cursor->next; 
        if (!cursor) 
            return NULL; 
    }
    if (!cursor->next) {
        saved = cursor->value; 
        destroy_entry(cursor);
        ht->elements[idx] = NULL; 
    } else {
        if (cursor == ht->elements[idx] && cursor->next){
            ht->elements[idx] = cursor->next;
            saved = cursor->value; 
            destroy_entry(cursor);
        } else {
            entry_t* tmp = ht->elements[idx];
            while(tmp->next != cursor) {
                tmp = tmp->next;
            }
            saved = cursor->value; 

            tmp->next = cursor->next; 
            cursor->key = NULL; 
            cursor->value = NULL; 
            cursor->next = NULL; 
            free(cursor); 
            cursor = NULL; 
        }
    }
    return saved; 
}

void destroy_entry(entry_t* entry) {
    entry->next = NULL; 
    entry->value = NULL; 
    entry->key = NULL; 
    free(entry); 
    entry = NULL;
}
//value_t ht_get(hashTable_t*, key_t); 

void ht_destroy(hashTable_t* ht) {
    
    u64 idx = 0; 
    entry_t* cursor = ht->elements[idx]; 
    entry_t* tmp = NULL; 

    do {

        if (cursor) {
            tmp = cursor; 
            cursor = cursor->next; 
        
            tmp->key = NULL;
            tmp->value = NULL; 
            tmp->next = NULL; 
            free(tmp); 
            tmp = NULL; // Is it safer to set tmp to NULL in or after the while loop?
        }

        if (!cursor && idx != ht->capacity-1) 
            cursor = ht->elements[++idx]; 

    } while (idx != ht->capacity-1 && cursor);

    free(ht->elements); 
    ht->elements = NULL; 
    ht->hash = NULL; 
    free(ht);
    ht = NULL; 
    
    /*
    printf("Status Check:\n");
    if (ht->elements == NULL && ht == NULL) {
        printf("ht->elements: NULL\nht: NULL\n");
    }
    */
}

