#include <iostream>
#include <vector>
#include "sorting.h"
#include "algoutils.h"

int main() {
    //int list_size = 10;
    //std::vector<int> in_list = generate_random_int_vector(list_size);
    std::vector<double> in_list = {.78,.17,.39,.26,.72,.94,.21,.12,.23,.68}; // example from CLRS 3e
    print_vector(in_list);
    bucket_sort(in_list);
    print_vector(in_list);
    return 0;
}


