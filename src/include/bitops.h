#ifndef _ANLIB_BITOPS_H
#define _ANLIB_BITOPS_H

#include <anlib/types.h>

#define BIT_MASK(nr) (1UL << (nr % BITS_PER_LONG))
#define BIT_WORD(nr) ((nr) / BITS_PER_LONG)

#endif
