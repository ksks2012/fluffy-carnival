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
