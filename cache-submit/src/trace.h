#ifndef __TRACE_H
#define __TRACE_H

typedef unsigned long address_type;

typedef struct {
  address_type address;
  int          size;
  char         operation;
} TraceLine;


#endif
