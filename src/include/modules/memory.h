#ifndef TONIGTH_C_FRAMEWORK
  #error "Include tonight.h headerfile"
#endif

#include "../types/common.h"
#include "../macros/base.h"
#include "./exceptions.h";

typedef const pointer header_t;

struct declare_namespace_Memory {
  pointer   (* alloc)   (size_t);
  pointer   (* realloc) (pointer, size_t);
  size_t    (* size)    (pointer);
  void      (* free)    (pointer);

  struct Header {
    void    (* add)     (pointer, header_t, pointer);
    pointer (* get)     (pointer, header_t);
    void    (* remove)  (pointer, header_t);
  } Header;

  struct Functions {
    void  (* setMalloc)   (pointer (*)(size_t));
    void  (* setRealloc)  (pointer (*)(pointer, size_t));
    void  (* setFree)     (void (*)(pointer));
  } Functions;
};

extern struct declare_namespace_Memory Memory;

extern exception_t MemoryException;
