#ifndef _ANLIB_RADIX_TREE_H
#define _ANLIB_RADIX_TREE_H

#include <anlib/types.h>

#define RADIX_TREE_MAP_SHIFT 4
#define RADIX_TREE_MAX_TAGS 2

#define RADIX_TREE_MAP_SIZE (1UL << RADIX_TREE_MAP_SHIFT)
#define RADIX_TREE_MAP_MASK (RADIX_TREE_MAP_SIZE - 1)

#define RADIX_TREE_TAG_LONGS \
	((RADIX_TREE_MAP_SIZE + BITS_PER_LONG -1 ) / BITS_PER_LONG)


#define RADIX_TREE_INDIRECT_PTR 1
#define RADIX_TREE_RETRY ((void *)-1UL)

struct radix_tree_node {
	unsigned int height;
	unsigned int count;
	void *slots[RADIX_TREE_MAP_SIZE];
	unsigned long tags[RADIX_TREE_MAX_TAGS][RADIX_TREE_TAG_LONGS];
};

struct radix_tree_root {
	unsigned int height;
	struct radix_tree_nod *rnode;
};

#endif
