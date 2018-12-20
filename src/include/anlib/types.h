#ifndef _ANLIB_TYPES_H
#define _ANLIB_TYPES_H

#define BITS_PER_LONG (sizeof(long))

struct list_head {
	struct list_head *next, *prev;
};

struct hlist_head{
	struct hlist_node *first;
};

struct hlist_node{
	struct hlist_node *next, **pprev;
};

#endif
