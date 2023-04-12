#ifndef TONIGTH_C_FRAMEWORK
  #error "Include tonight.h headerfile"
#endif

#define $first(a, b...) a
#define $second(a, b, c...) b
#define $third(a, b, c, d...) c

#define __macro_in__(a, b) a, b
#define __macro_as__(a, b) b, a

#define $in ,__macro_in__,
#define $as ,__macro_as__,
