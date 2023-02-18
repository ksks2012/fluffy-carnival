#include "sort.h"
#include <stdio.h>

int ranom_in_range(int min, int max) {
	return rand() % (max - min + 1) + min;
}

list_node_t* list_insertion_sort(list_node_t *start) {
	if (!start || !start->next)
		return start;
	list_node_t *left = start;
	list_node_t *right = left->next;
	left->next = NULL; // sub linking list_node_t

	printf("left: ");
	print_list(left);
	printf("right: ");
	print_list(right);

	left = list_insertion_sort(left);
	right = list_insertion_sort(right);

	for (list_node_t *merge = NULL; left || right; ) {
		if (!right || (left && left->value < right->value)) {
			if (!merge) {
				start = merge = left; // init merge, start = left
			} else {
				// insert
				merge->next = left;
				merge = merge->next;
			}
			left = left->next; // left = NULL, finish loop
		} else {
			if (!merge) {
				start = merge = right; // init merge, start = right
			} else {
				merge->next = right;
				merge = merge->next;
			}
			right = right->next;
		}
	}
	return start;
}

/*
 * https://hackmd.io/@sysprog/linux2021-quiz1
 */
void list_quick_sort(list_node_t **start) {
	if (!*start)
		return;

	list_node_t *pivot = *start;
	int value = *((int *)pivot->value);
	list_node_t *p = pivot->next;
	pivot->next = NULL;

	list_node_t *left = NULL, *right = NULL;
	while (p) {
		list_node_t *n = p;
		p = p->next;
		list_add_node(*((int *)n->value) > value ? &(right) : &(left), n);
	}
	list_quick_sort(&left);
	list_quick_sort(&right);

	list_node_t *result = NULL;
	list_concat(&result, left);
	list_concat(&result, pivot);
	list_concat(&result, right); 

	*start = result;
}