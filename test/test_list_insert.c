#include "../lib/cheader.h"

int main() {
	int input[4] = {1, 2, 3, 4};
	list_t *list = array_to_list(input, 4);
	print_list(list->head);

	int back_input = 6;
	push_back(&(list->head), &back_input);
	print_list(list->head);

	int front_input = 0;
	push_front(&(list->head), &front_input);
	print_list(list->head);

	int mid_input = 11;
	insert_mid(&(list->head), &mid_input);
	print_list(list->head);
	int mid_input2 = 22;
	insert_mid(&(list->head), &mid_input2);
	print_list(list->head);
}