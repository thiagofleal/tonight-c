#include <stdlib.h>
#include "../include/tonight.h";
#include "../include/modules/memory.h";

Define_Exception(MemoryException $as Exception $in "Memory Exception");

extern pointer  new_list_map(void);
extern void     list_map_set(pointer, const pointer, pointer);
extern pointer  list_map_get(pointer, const pointer);
extern void     list_map_unset(pointer, const pointer);
extern void     list_map_free(pointer);

typedef struct {
  size_t size;
  pointer headers;
  byte data[0];
} memory_t, *memory_p;

static pointer (* p_malloc)(size_t) = malloc;
static pointer (* p_realloc)(pointer, size_t) = realloc;
static void    (* p_free)(pointer) = free;

static pointer Memory_alloc(size_t size) {
  memory_p memory = p_malloc(sizeof(memory_t) + size);

  if (!memory) Throw(MemoryException, "Memory alloc failed");

  memory->size = size;
  memory->headers = new_list_map();
  return memory->data;
}

static pointer Memory_realloc(pointer _memory, size_t size) {
  memory_p memory = _memory - sizeof(memory_t);
  pointer headers = memory->headers;
  memory = p_realloc(memory, sizeof(memory_t) + size);

  if (!memory) Throw(MemoryException, "Memory realloc failed");

  memory->size = size;
  memory->headers = headers;
  return memory->data;
}

static size_t Memory_size(pointer _memory) {
  memory_p memory = _memory - sizeof(memory_t);
  return memory->size;
}

static void Memory_free(pointer _memory) {
  memory_p memory = _memory - sizeof(memory_t);
  p_free(memory);
}

static void Memory_Header_add(pointer _memory, header_t header, pointer value) {
  memory_p memory = _memory - sizeof(memory_t);
  list_map_set(memory->headers, header, value);
}

static pointer Memory_Header_get(pointer _memory, header_t header) {
  memory_p memory = _memory - sizeof(memory_t);
  return list_map_get(memory->headers, header);
}

static void Memory_Header_remove(pointer _memory, header_t header) {
  memory_p memory = _memory - sizeof(memory_t);
  return list_map_unset(memory->headers, header);
}

static void Memory_Functions_setMalloc(pointer (*func)(size_t)) {
  p_malloc = func;
}

static void Memory_Functions_setRealloc(pointer (*func)(pointer, size_t)) {
  p_realloc = func;
}

static void Memory_Functions_setFree(void (*func)(pointer)) {
  p_free = func;
}

struct declare_namespace_Memory Memory = {
  .alloc = Memory_alloc,
  .realloc = Memory_realloc,
  .size = Memory_size,
  .free = Memory_free,
  .header = {
    .add = Memory_Header_add,
    .get = Memory_Header_get,
    .remove = Memory_Header_remove
  },
  .functions = {
    .setMalloc = Memory_Functions_setMalloc,
    .setRealloc = Memory_Functions_setRealloc,
    .setFree = Memory_Functions_setFree
  }
};
