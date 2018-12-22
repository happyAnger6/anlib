#include <anlib.h>
#include <anlib/radix_tree.h>

#define RADIX_TREE_INDEX_BITS (8 * sizeof(unsigned long))

static unsigned long height_to_maxindex[RADIX_TREE_MAX_PATH + 1];

static inline int root_tag_get(struct radix_tree_root *root, unsigned int tag)
{
        return (unsigned)root->gfp_mask & (1 << (tag + __GFP_BITS_SHIFT));
}

static inline unsigned long radix_tree_maxindex(unsigned int height)
{
    return height_to_maxindex[height];
}

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



static struct radix_tree_node *
radix_tree_node_alloc(struct radix_tree_root *root)
{
    return (struct radix_tree_node *)malloc(sizeof(struct radix_tree_node));
}

static int radix_tree_extend(struct radix_tree_root *root, unsigned long index)
{
    struct radix_tree_node *node;
    unsigned int height;
    int tag;

    height = root->height + 1;
    while(index > radix_tree_maxindex(height))
        height++;

    if(root->rnode == NULL)
    {
        root->height = height;
        goto out;
    }	

    do {
        unsigned int newheight;
        if (!(node = radix_tree_node_alloc(root))
                return -ENOMEM;

        node->slots[0] = radix_tree_indirect_to_ptr(root->rnode);


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

    if(index > radix_tree_maxindex(root->height))
    {
        error = radix_tree_extend(root, index);
        if(error)
            return error;
    }

    slot = radix_tree_indirect_to_ptr(root->rnode);


}

