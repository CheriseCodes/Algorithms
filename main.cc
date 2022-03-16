#include <iostream>
#include <vector>
#include "order_statistics.h"
#include "algoutils.h"

int main() {
    int list_size = 10;
    std::vector<int> in_list = generate_random_int_vector(list_size);
    //std::vector<double> in_list = {.78,.17,.39,.26,.72,.94,.21,.12,.23,.68}; // example from CLRS 3e
    print_vector(in_list);
    int end_idx = in_list.size()-1;
    int res = randomized_select_iterative(in_list, 0, end_idx,end_idx-3);
    std::cout << "result: " << res << std::endl;
    print_vector(in_list);
    return 0;
}
