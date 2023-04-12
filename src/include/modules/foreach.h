#ifndef TONIGTH_C_FRAMEWORK
  #error "Include tonight.h headerfile"
#endif

#include "../types/common.h"
#include "../macros/base.h"

extern bool __foreach_start(pointer);
extern bool __foreach_assign(pointer);

extern bool __foreachkey_start(pointer);
extern bool __foreachkey_assign(pointer);

#define __foreach_statement__(var, values)  if(__foreach_start(values))\
                                            while(__foreach_assign(&var))

#define __foreachkey_statement__(var, values) if(__foreachkey_start(values))\
                                              while(__foreachkey_assign(&var))

#define __macro_foreach_build__(a)    __foreach_statement__(a)
#define __macro_foreachkey_build__(a) __foreachkey_statement__(a)

#define __macro_foreach__(a, macro, b)    __macro_foreach_build__(macro(a, b))
#define __macro_foreachkey__(a, macro, b) __macro_foreachkey_build__(macro(a, b))

#define foreach(args...)    __macro_foreach__(args)
#define foreachkey(args...) __macro_foreachkey__(args)
