#include "../lib/cheader.h"

void test_remove_nth_node_from_tail() {
	printf("\ntest_remove_nth_node\n");
	int input[4] = {1, 2, 3, 4};
	list_t *list = array_to_list(input, 4);
	print_list(list->head);

	remove_nth_node_from_tail(&(list->head), 5);
    remove_nth_node_from_tail(&(list->head), 2);
	print_list(list->head);
}

void test_remove_mid_node() {
	printf("\ntest_remove_mid_node\n");
	int input[4] = {1, 2, 3, 4};
	list_t *list = array_to_list(input, 4);
	print_list(list->head);

	remove_mid_node(&(list->head));
	print_list(list->head);
    remove_mid_node(&(list->head));
	print_list(list->head);
}

void test_remove_duplicates_node() {
	int input[4] = {1, 1, 1, 1};
	list_t *list = array_to_list(input, 4);
	print_list(list->head);
	remove_duplicates_node(&(list->head));
	print_list(list->head);
}

void test_remove_duplicates_node_in_none_sort_list() {
	int input[7] = {1, 2, 1, 3, 1, 1, 2};
	list_t *list = array_to_list(input, 7);
	print_list(list->head);
	remove_duplicates_node_in_none_sort_list(&(list->head));
	print_list(list->head);
}

int main() {
	test_remove_nth_node_from_tail();
	test_remove_mid_node();
	test_remove_duplicates_node();
	test_remove_duplicates_node_in_none_sort_list();
}