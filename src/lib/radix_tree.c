#include <anlib.h>
#include <anlib/radix_tree.h>

#define RADIX_TREE_INDEX_BITS (8 * sizeof(unsigned long))

static unsigned long height_to_maxindex[RADIX_TREE_MAX_PATH + 1];

static unsigned long __maxindex(unsigned int height)
{
	unsigned int width = height * RADIX_TREE_MAP_SHIFT;
	int shift = RADIX_TREE_INDEX_BITS - width;

	if(shift < 0)
		return ~0UL;
	if(shift >= BITS_PER_LONG)
		return 0UL;
	return ~0UL >> shift;	
}

static void radix_tree_init_maxindex(void)
{
	unsigned int i;
	
	for(i = 0; i < ARRAY_SIZE(height_to_maxindex); i++)
	{
		height_to_maxindex[i] = __maxindex(i);
	}
	
}

/**
 * radix_tree_insert  -  insert into a radix tree
 * @root: radix tree root
 * @index: index key
 * @item: item to insert
 *
 * Insert an item into the radix tree at position @index.
 */
int radix_tree_insert(struct radix_tree_root *root,
	unsigned long index, void *item)
{
	int error;
}

