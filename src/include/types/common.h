#ifndef TONIGTH_C_FRAMEWORK
  #error "Include tonight.h headerfile"
#endif

#include <stddef.h>

#define ARRAY *

typedef unsigned char byte;

#ifndef __cplusplus
  typedef unsigned char bool;
  #define true 0x01
  #define false 0x00
#endif

typedef void * pointer;
typedef char * string;
typedef wchar_t * wstring;

#ifndef TONIGHT_FIXSTRING_SIZE
  #define TONIGHT_FIXSTRING_SIZE 100
#endif

#ifndef TONIGHT_LONGFIXSTRING_SIZE
  #define TONIGHT_LONGFIXSTRING_SIZE 1000
#endif

typedef struct fixstring_t {
  char text[TONIGHT_FIXSTRING_SIZE];
} fixstring_t;

typedef struct fixwstring_t {
  wchar_t text[TONIGHT_FIXSTRING_SIZE];
} fixwstring_t;

typedef struct long_fixstring_t {
  char text[TONIGHT_LONGFIXSTRING_SIZE];
} long_fixstring_t;

typedef struct long_fixwstring_t {
  wchar_t text[TONIGHT_LONGFIXSTRING_SIZE];
} long_fixwstring_t;

typedef struct t_class t_class, *Class;

struct t_class {
  string name;
  wstring wideName;
  pointer ref;
  Class parent;
};

typedef struct t_object *object;
