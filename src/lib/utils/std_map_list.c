#include <stdlib.h>

#include "../../include/tonight.h"

typedef struct node_t node_t, *node_p;

struct node_t {
  pointer key;
  pointer data;
  node_p next;
};

typedef struct {
  node_p list;
} list_t, *list_p;

static node_p createNode(const pointer key, pointer data) {
  node_p node = malloc(sizeof (node_t));
  if (node) {
    node->key = key;
    node->data = data;
    node->next = NULL;
  }
  return node;
}

pointer new_list_map(void) {
  list_p list = malloc(sizeof (list_t));

  if (list) {
    list->list = NULL;
  }
  return list;
}

void list_map_add(pointer list, const pointer key, pointer data) {
  list_p listMap = list;

  if (listMap) {
    node_p node = createNode(key, data);
    if (listMap->list) {
      node->next = listMap->list;
      listMap->list = node;
    } else {
      listMap->list = node;
    }
  }
}

pointer list_map_get(pointer list, const pointer key) {}

void list_map_free(pointer list) {}
