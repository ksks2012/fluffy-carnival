#include "../lib/cheader.h"

void test_insert_basic() {
	printf("\ntest_insert_basic\n");
	int input[4] = {1, 2, 3, 4};
	list_t *list = array_to_list(input, 4);
	print_list(list->head);

	int back_input = 6;
	push_back(&(list->head), &back_input);
	print_list(list->head);

	int front_input = 0;
	push_front(&(list->head), &front_input);
	print_list(list->head);
}

void test_insert_nth_last() {
	printf("\ntest_insert_nth_last\n");
	int input[4] = {1, 2, 3, 4};
	list_t *list = array_to_list(input, 4);
	print_list(list->head);
	int input1 = 5;
	insert_nth_last(&(list->head), &input1, 2);
	print_list(list->head);
	int input2 = 0;
	insert_nth_last(&(list->head), &input2, 5);
	print_list(list->head);
}

void test_insert_mid() {
	printf("\ntest_insert_mid\n");
	int input[4] = {1, 2, 3, 4};
	list_t *list = array_to_list(input, 4);
	print_list(list->head);
	int mid_input = 11;
	insert_mid(&(list->head), &mid_input);
	print_list(list->head);
	int mid_input2 = 22;
	insert_mid(&(list->head), &mid_input2);
	print_list(list->head);
}

int main() {
	test_insert_basic();
	test_insert_nth_last();
	test_insert_mid();
}