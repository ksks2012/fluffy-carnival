#include "../lib/cheader.h"

int main() {
	int input[4] = {1, 2, 3, 4};
	list_t *list = array_to_list(input, 4);
	print_list(list->head);
}
