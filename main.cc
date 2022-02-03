#include <iostream>
#include <vector>
#include "sorting.h"
#include "algoutils.h"

int main() {
    std::vector<int> in_list = generate_random_int_vector(10);
    print_vector(in_list);
    heap_sort(in_list);
    print_vector(in_list);
    return 0;
}


