#ifndef TONIGTH_C_FRAMEWORK
  #error "Include tonight.h headerfile"
#endif

#include "../types/common.h"
#include "../macros/base.h"

typedef const pointer *exception_t;

typedef struct except_definition {
  exception_t parent;
  const string name;
} except_definition_t;

extern bool __create_try_context(void);
extern bool __try_context_next(void);
extern bool __try_block(void);
extern bool __catch_block(exception_t);
extern bool __except_block(void);
extern void Throw(exception_t, string, ...);

#define try if (__create_try_context())\
              while(__try_context_next())\
                if (__try_block())

#define catch(exc)  if (__catch_block(exc))

#define except      if (__except_block())

#define __define_exceptions__(super, var, text)  \
  static except_definition_t __definition_##var = {\
    .parent = &super,\
    .name = text\
  };\
  exception_t var = (exception_t)&__definition_##var;

#define __define_exceptions_once__(arg) \
  __define_exceptions__(arg)

#define __prepare_define_exceptions__(a, macro1, b, macro2, c)  \
  __define_exceptions_once__(macro2(macro1(a, b), c))

#define Define_Exception(args...) \
  __prepare_define_exceptions__(args)

#ifndef __cplusplus
  #define throw Throw
#endif

extern exception_t Exception;
