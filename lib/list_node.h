#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

#ifndef BOOL
typedef enum bool {
	FALSE,
	TRUE
} bool;
#define BOOL
#endif

typedef struct list_node_t
{
	/* data */
	void * value;
	struct list_node_t *next;
	struct list_node_t *prev;
}list_node_t;

extern inline list_node_t* node_new(void *);
list_node_t* array_to_list(int *, int);
void print_list(const list_node_t *);

void push_back(list_node_t **, void *);

#endif /* __LIST_NODE_H__ */
