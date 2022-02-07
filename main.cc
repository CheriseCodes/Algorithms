#include <iostream>
#include <vector>
#include "sorting.h"
#include "algoutils.h"

int main() {
    int list_size = 10;
    std::vector<int> in_list = generate_random_int_vector(list_size);
    print_vector(in_list);
    quick_sort(in_list, 0, --list_size);
    //heap_sort(in_list);
    print_vector(in_list);
    return 0;
}


