// Approach
/* 
For getting O(1) for insert, remove and get we need to forge 2 data structure. I did resizable vector with hash map, 
we use the hash map to get the item with O(1) complexity and to insert and remove we use the resizable vector!

  I used UTHASH for the hashmap - [UTHASH](https://github.com/troydhanson/uthash/blob/master/src/uthash.h)
*/

// Complexity
// Time complexity: O(1) average case

//Space complexity: O(n).

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"

typedef struct {
  int *data; // pointer to array
  int size; // current number of elements
  int capacity; // allocated capacity
} Vector;

#define VECTOR_INIT_CAPACITY 16

Vector* vector_init() {
  Vector *init = malloc(sizeof(Vector));
  init->capacity = VECTOR_INIT_CAPACITY;
  init->size = 0;
  init->data = malloc(VECTOR_INIT_CAPACITY * sizeof(int));

  return init;
}

void vector_push_back(Vector *v, int val) {
  if(v->size == v->capacity) {
    v->capacity *= 2;
    v->data = realloc(v->data, v->capacity * sizeof(int));
  }

  v->data[v->size++] = val;
}

typedef struct {
  int key;
  int index;
  UT_hash_handle hh;
} HashEntry;

typedef struct
{
  Vector vec;
  HashEntry *map;
} RandomizedSet;

RandomizedSet *randomizedSetCreate()
{
  RandomizedSet* rs = malloc(sizeof(RandomizedSet));
  Vector* vec = vector_init();

  rs->vec = *vec;
  rs->map = NULL;

  srand((unsigned)time(NULL));
  
  return rs;
}

bool randomizedSetInsert(RandomizedSet *obj, int val)
{
  HashEntry *entry;
  HASH_FIND_INT(obj->map, &val, entry);
  if(entry != NULL) {
    return false;
  }

  vector_push_back(&obj->vec, val);
  entry = malloc(sizeof(HashEntry));
  entry->key = val;
  entry->index = obj->vec.size - 1;
  HASH_ADD_INT(obj->map, key, entry);

  return true;
}

bool randomizedSetRemove(RandomizedSet *obj, int val)
{
  HashEntry *entry;
  HASH_FIND_INT(obj->map, &val, entry);
  if(entry == NULL) {
    return false;
  }

  int idx = entry->index;
  int last_val = obj->vec.data[obj->vec.size-1];
  obj->vec.data[idx] = last_val;

  HashEntry *last_entry;
  HASH_FIND_INT(obj->map, &last_val, last_entry);
  last_entry->index = idx;

  obj->vec.size--;

  HASH_DEL(obj->map, entry);
  free(entry);

  return true;
}

int randomizedSetGetRandom(RandomizedSet *obj)
{
  int idx = rand() % obj->vec.size;
  return obj->vec.data[idx];

}

void randomizedSetFree(RandomizedSet *obj)
{
  HashEntry *curr, *tmp;
  HASH_ITER(hh, obj->map, curr, tmp) {
    HASH_DEL(obj->map, curr);
    free(curr);
  }

  free(obj->vec.data);
  free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/