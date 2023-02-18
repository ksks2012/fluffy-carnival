#include "cheader.h"

inline list_node_t* node_new(void* value) {
	list_node_t *new_node = (list_node_t *)malloc(sizeof(list_node_t));
	if(new_node == NULL)
		return NULL;
	new_node->next = NULL;
	new_node->value = (typeof(value))value;
	return new_node;
}

list_t* array_to_list(int *arr, int size) {
	if(arr == NULL || size <= 0) {
		return NULL;
	}
	list_t *list = (list_t *)malloc(sizeof(list_t));
	for(int i = 0; i < size; i++) {
		push_back(&(list->head), &(arr[i]));
	}
	return list;
}

void print_list(const list_node_t *head) {
	list_node_t const *ptr = head;
	while (ptr)
	{
		/* code */
		printf("%d -> ", *((int *)(ptr->value)));
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void delete_list(list_t *list) {
	list_node_t **head = &(list->head);
	while (*head) {
		list_node_t *next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(list);
}

// add node to back
void push_back(list_node_t **head, void *input) {
	list_node_t **indirect = head;
	list_node_t *new_node = node_new(input);
	while (*indirect)
	{
		indirect = &((*indirect)->next);
	}
	*indirect = new_node;
}

void push_front(list_node_t **head, void *input) {
	list_node_t **indirect = head;
	list_node_t *new_node = node_new(input);
	new_node->next = *indirect;
	*head = new_node;
}

void insert_mid(list_node_t **head, void *input) {
	list_node_t **fast = head;
	list_node_t **slow = head;
	list_node_t *new_node = node_new(input);
	while(*fast && (*fast)->next) {
		fast = &((*fast)->next->next);
		slow = &((*slow)->next);
	}
	new_node->next = (*slow)->next;
	(*slow)->next = new_node;
}

void insert_nth_last(list_node_t **head, void *input, int n) {
	/*
		insert the node to list in n-th position from last
		if n > length of node then push in front
	*/
	list_node_t **fast_ptr = head;
	list_node_t **slow_ptr = head;
	list_node_t *new_node = node_new(input);

	for(int i = 0; i < n + 1; i++) {
		if (*fast_ptr == NULL) {
			push_front(head, input);
			return;
		}
		fast_ptr = &((*fast_ptr)->next);
	}

	while(*fast_ptr) {
		fast_ptr = &((*fast_ptr)->next);
		slow_ptr = &((*slow_ptr)->next);
	}
	new_node->next = (*slow_ptr)->next;
	(*slow_ptr)->next = new_node;
}

void remove_nth_node(list_node_t **head, int n) {
	list_node_t **indirect = head;
	
	int count = 0;
	while (*indirect && count < n - 1)
	{
		indirect = &((*indirect)->next);
		count++;
	}
	if(!(*indirect)) {
		return;
	}
	list_node_t *tmp = (*indirect)->next;
	(*indirect)->next = (*indirect)->next->next;
	free(tmp);
}

void remove_mid_node(list_node_t **head) {
	list_node_t **fast_ptr = head;
	list_node_t **slow_ptr = head;

	while ((*fast_ptr)->next && (*fast_ptr)->next->next)
	{
		slow_ptr = &((*slow_ptr)->next);
		fast_ptr = &((*fast_ptr)->next->next);
	}
	if(!(*slow_ptr)) {
		return;
	}
	list_node_t *tmp = (*slow_ptr)->next;
	(*slow_ptr)->next = (*slow_ptr)->next->next;
	free(tmp);
}

void remove_duplicates_node(list_node_t **head) {
	if (!list_is_ordered(*head) || *head == NULL) {
		return;
	}
	list_node_t *current = *head;
	list_node_t *tmp = (*head)->next;
	list_node_t *hold;

	while (tmp != NULL)
	{
		if(*((int *)tmp->value) == *((int *)current->value)) {
			hold = tmp;
		} else {
			current = tmp;
		}
		
		tmp = tmp->next;
		if(hold != NULL) {
			current->next = tmp;
			free(hold);
			hold = NULL;
		}
	}
}

inline void list_add_node(list_node_t **list, list_node_t *new_node) {
	new_node->next = *list;
	*list = new_node;
}

inline void list_concat(list_node_t **left, list_node_t *right) {
	while (*left)
		left = &((*left)->next);
	*left = right;
}

bool list_is_ordered(list_node_t *list) {
    bool first = TRUE;
    int value;
    while (list) {
        if (first) {
            value = *((int *)(list->value));
            first = FALSE;
        } else {
            if (*((int *)(list->value)) < value)
                return FALSE;
            value = *((int *)(list->value));
        }
        list = list->next;
    }
    return TRUE;
}