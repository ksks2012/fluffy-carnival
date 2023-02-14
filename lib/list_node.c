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