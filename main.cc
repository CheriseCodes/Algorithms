#include <iostream>
#include <vector>
#include "sorting.h"
#include "algoutils.h"

int main() {
    //int list_size = 10;
    //std::vector<int> in_list = generate_random_int_vector(list_size);
    std::vector<int> in_list = {329, 457, 657, 839, 436, 720, 355}; // example from CLRS 3e
    print_vector(in_list);
    radix_sort(in_list);
    print_vector(in_list);
    return 0;
}


