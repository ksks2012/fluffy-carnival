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
	int value;
	struct list_node_t *next;
}list_node_t;

typedef struct list_t {
	list_node_t *head;
} list_t;

extern inline list_node_t* node_new(int );
list_t* array_to_list(int *, int);
void print_list(const list_node_t *);
void delete_list(list_t *);

void push_back(list_node_t **, int);
void push_front(list_node_t **, int );

void insert_mid(list_node_t **, int );
void insert_nth_last(list_node_t **, int , int);

void remove_nth_node_from_tail(list_node_t **, int);
void remove_mid_node(list_node_t **);
void remove_duplicates_node(list_node_t **);
void remove_duplicates_node_in_none_sort_list(list_node_t **);
void remove_nth_node(list_node_t **, int);

inline void list_add_node(list_node_t **, list_node_t *);
inline void list_concat(list_node_t **, list_node_t *);

bool list_is_ordered(list_node_t *);

#endif /* __LIST_NODE_H__ */
