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

void list_map_set(pointer list, const pointer key, pointer data) {
  list_p map = list;

  if (map) {
    node_p node = createNode(key, data);

    if (map->list) {
      node_p iterator = map->list;
      while (iterator) {
        if (iterator->key == key) {
          iterator->data = data;
          return;
        }
        iterator = iterator->next;
      }
      node->next = map->list;
    }
    map->list = node;
  }
}

void list_map_unset(pointer list, const pointer key) {
  list_p map = list;

  if (map) {
    if (map->list) {
      node_p iterator = map->list;
      if (iterator->key == key) {
        node_p current = map->list;
        iterator = map->list = iterator->next;
        free(current);
      }
      while (iterator->next) {
        if (iterator->next->key == key) {
          node_p next = iterator->next;
          iterator->next = next->next;
          free(next);
        }
      }
      iterator = iterator->next;
    }
  }
}

pointer list_map_get(pointer list, const pointer key) {
  list_p map = list;

  if (map) {
    if (map->list) {
      node_p iterator = map->list;
      while (iterator) {
        if (iterator->key == key) {
          return iterator->data;
        }
      }
      iterator = iterator->next;
    }
  }
  return NULL;
}

void list_map_free(pointer list) {
  list_p map = list;
  node_p node = map->list;

  while (node) {
    node_p next = node->next;
    free(node);
    node = next;
  }
  free(list);
}
