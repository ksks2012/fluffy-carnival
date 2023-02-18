#ifndef __SORT_H__
#define __SORT_H__

#include <time.h>
#include <stdlib.h>
#include <assert.h>

#include "list_node.h"

#ifndef BOOL
typedef enum bool {
	false,
	true
} bool;
#endif

#define swap(x,y) {int t; (t)=(x); (x)=(y); (y)=(t);}

list_node_t* list_insertion_sort(list_node_t *);
void list_quick_sort(list_node_t **);

#endif
