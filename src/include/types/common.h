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

#ifdef __cplusplus
  #define OPTIONAL_ARGS ...
#else
  #define OPTIONAL_ARGS
#endif

typedef void (*function_void)(OPTIONAL_ARGS);
typedef byte (*function_byte)(OPTIONAL_ARGS);
typedef bool (*function_bool)(OPTIONAL_ARGS);
typedef char (*function_char)(OPTIONAL_ARGS);
typedef int (*function_int)(OPTIONAL_ARGS);
typedef long (*function_long)(OPTIONAL_ARGS);
typedef float (*function_float)(OPTIONAL_ARGS);
typedef double (*function_double)(OPTIONAL_ARGS);
typedef pointer (*function_pointer)(OPTIONAL_ARGS);
typedef string (*function_string)(OPTIONAL_ARGS);
typedef wstring (*function_wstring)(OPTIONAL_ARGS);
typedef fixstring_t (*function_fixstring)(OPTIONAL_ARGS);
typedef fixwstring_t (*function_fixwstring)(OPTIONAL_ARGS);
typedef long_fixstring_t (*function_long_fixstring_t)(OPTIONAL_ARGS);
typedef long_fixwstring_t (*function_long_fixwstring_t)(OPTIONAL_ARGS);

typedef struct t_class t_class, *Class;

struct t_class {
  string name;
  wstring wideName;
  pointer ref;
  Class parent;
};

typedef struct t_object *object;
