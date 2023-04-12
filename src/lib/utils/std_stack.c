#include <stdlib.h>

#include "../../include/tonight.h"

typedef struct t_node t_node, *p_node;

struct t_node {
  pointer data;
  p_node next;
};

typedef struct {
  p_node list;
} t_stack, *p_stack;

static p_node createNode(pointer data) {
  p_node node = malloc(sizeof (t_node));
  node->data = data;
  node->next = NULL;
  return node;
}

pointer new_stack(void) {
  p_stack stack = malloc(sizeof (t_stack));

  if (stack) {
    stack->list = NULL;
  }
  return stack;
}

pointer stack_push(pointer stack, pointer data) {
  p_stack pstack = stack;
  p_node node = createNode(data);

  if (node) {
    node->next = pstack->list;
    pstack->list = node;
  }
}

pointer stack_pop(pointer stack) {
  p_stack pstack = stack;
  p_node node = pstack->list;

  if (node) {
    pstack->list = node->next;
    free(node);
  }
}
