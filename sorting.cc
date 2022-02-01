#include <vector>
#include <iostream>
#include <random>
#include "algoutils.h"

void insertion_sort(std::vector<int> & in_list) {
    int list_len = in_list.size();
    for (int j = 1; j < list_len; j++) {
        int key = in_list[j];
        int i = j - 1;
        // make sure every item before in_list[j] is in sorted order
        while ((i > -1) && (in_list[i] > key)) {
            in_list[i+1] = in_list[i];
            --i;
        }
        in_list[i+1] = key;
        //print_vector(in_list);
    }
}

std::vector<int> generate_random_input(int v_size) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, v_size*3);
    std::vector<int> arr;
    distrib(gen);
    for (int i = 0; i < v_size; i++) {
        arr.push_back(distrib(gen)); 
    }
    //std::cout << arr.max_size() << std::endl;
    return arr;
}