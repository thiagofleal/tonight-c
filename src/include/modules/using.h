#ifndef TONIGTH_C_FRAMEWORK
  #error "Include tonight.h headerfile"
#endif

#include "../types/common.h"

#include "../macros/base.h"

extern bool __using_start(pointer);
extern bool __using_assign(pointer);

#define __using_statement__(var, value) if(__using_start(value))\
                                        while(__using_assign(&var))

#define __macro_using_build__(a)  __using_statement__(a)

#define __macro_using__(a, macro, b)  __macro_using_build__(macro(a, b))

#define Using(args...)  __macro_using__(args)

#ifndef __cplusplus
  #define using Using
#endif
