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

typedef struct fixString {
  char text[TONIGHT_FIXSTRING_SIZE];
} fixString;

typedef struct fixWideString {
  char text[TONIGHT_FIXSTRING_SIZE];
} fixWideString;

typedef struct longFixString {
  char text[TONIGHT_LONGFIXSTRING_SIZE];
} longFixString;

typedef struct longFixWideString {
  char text[TONIGHT_LONGFIXSTRING_SIZE];
} longFixWideString;

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
typedef fixString (*function_fixString)(OPTIONAL_ARGS);
typedef fixWideString (*function_fixWideString)(OPTIONAL_ARGS);
typedef longFixString (*function_longFixString)(OPTIONAL_ARGS);
typedef longFixWideString (*function_longFixWideString)(OPTIONAL_ARGS);

typedef enum class_visibility {
  v_private = 0,
  v_protected = 1,
  v_public = 2
} class_visibility;

typedef struct t_class t_class, *Class;

struct t_class {
  string name;
  wstring wideName;
  pointer ref;
  Class parent;
};

typedef struct t_object *object;
