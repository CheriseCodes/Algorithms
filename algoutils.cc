#include <vector>
#include <random>
#include <map>
#include <iostream>

std::vector<int> generate_random_int_vector(int v_size) {
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

void print_int_map(std::map<int, int> in_map) {
    for(std::map<int, int>::iterator it = in_map.begin(); it != in_map.end(); ++it) {
            std::cout << it->first << " " << it->second << "\n";
        }
}
