#include "../lib/cheader.h"


int main(int argc, char **argv) {
    const int array_size = 100;
    int array[100] = {0};
    int count = array_size;

    init_rand(time(NULL));
    while (count--) {
        array[count] = rand_range(0, 1024);
    }

    list_t *list = array_to_list(array, array_size);

    printf("Not sort:\n");
    print_list(list->head);
    list_quick_sort(&(list->head));
    printf("\nSorted:\n");
    print_list(list->head);

    if (!list_is_ordered(list->head))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}    