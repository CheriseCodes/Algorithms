#include <iostream>
#include <vector>
#include "sorting.h"
#include "algoutils.h"

int main() {
    std::vector<int> in_list = generate_random_input(10);
    print_vector(in_list);
    insertion_sort(in_list);
    print_vector(in_list);
    return 0;
}


