#include <setjmp.h>
#include "../include/tonight.h";
#include "../include/modules/exceptions.h"

extern pointer  new_stack(void);
extern pointer  stack_push(pointer, pointer);
extern pointer  stack_pop(pointer);
extern void     stack_free(pointer);

extern pointer  new_list_map(void);
extern void     list_map_set(pointer, const pointer, pointer);
extern pointer  list_map_get(pointer, const pointer);
extern void     list_map_unset(pointer, const pointer);
extern void     list_map_free(pointer);

enum try_control {
  CTRL_TRY, CTRL_CATCH, CTRL_EXCEPT
};

typedef struct {
  pointer buff;
  int ctrl;
  exception_t exception;
} try_context_t, *try_context_p;

bool __create_try_context(void) {}

bool __try_context_next(void) {}

bool __try_block(void) {}

bool __catch_block(exception_t type) {}

bool __except_block(void) {}

void Throw(exception_t type, string message, ...) {}
