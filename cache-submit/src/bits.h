#ifndef BITS_H_
#define BITS_H_
#include "cache.h"

address_type get_set(Cache *cache, address_type address);
address_type get_line(Cache *cache, address_type address);
address_type get_byte(Cache *cache, address_type address);

#endif /* BITS_H_ */
