#include <iostream>
#include <vector>
#include "sorting.h"
#include "algoutils.h"

int main() {
    int list_size = 10;
    std::vector<int> in_list = generate_random_int_vector(list_size);
    std::vector<int> out_list(list_size,0);
    int k = 5;
    for (int i = 0; i < list_size; i++) {
        in_list[i] = in_list[i] % (k+1);
    }
    print_vector(in_list);
    counting_sort(in_list, out_list, k);
    print_vector(out_list);
    return 0;
}


