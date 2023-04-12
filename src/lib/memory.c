#include <stdlib.h>
#include "../include/tonight.h";
#include "../include/modules/memory.h";

Define_Exception(MemoryException $as Exception $in "Memory Exception");

extern pointer new_list_map(void);
extern pointer list_map_get(pointer, pointer);
extern pointer list_map_free(pointer);

typedef struct {
  size_t size;
  pointer headers;
  byte data[0];
} memory_t, *memory_p;

pointer Memory_alloc(size_t size) {
  memory_p memory = malloc(sizeof(memory_t) + size);

  if (!memory) Throw(MemoryException, "Memory alloc failed");

  memory->size = size;
  memory->headers = new_list_map();
  return memory->data;
}

pointer Memory_realloc(pointer memory, size_t size) {}

size_t Memory_size(pointer memory) {}

void Memory_free(pointer memory) {}

void Memory_Header_add(pointer memory, header_t header, pointer value) {}

header_t Memory_Header_get(pointer memory, header_t header) {}

void Memory_Header_remove(pointer memory, header_t header) {}

struct declare_namespace_Memory Memory = {
  .alloc = Memory_alloc,
  .realloc = Memory_realloc,
  .size = Memory_size,
  .free = Memory_free,
  .Header = {
    .add = Memory_Header_add,
    .get = Memory_Header_get,
    .remove = Memory_Header_remove
  }
};
