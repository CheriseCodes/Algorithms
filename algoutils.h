#ifndef ALGOUTILS_H_
#define ALGOUTILS_H_

#include <vector>
#include <random>

template <typename T>
void print_vector(std::vector<T> & v) {
    int len = v.size();
    if (len == 0) std::cout << "v = { }\n";
    std::cout << "v = { " << v[0];
    for (int i = 1; i < len ; i++) {
        std::cout << ", " << v[i] ;
    }
    std::cout << " }; \n";
}

template <typename T>
void print_vector_with_indices(std::vector<T> & v) {
    int len = v.size();
    if (len == 0) std::cout << "v = { }\n";
    std::cout << "v = { " << 0 << ": " << v[0];
    for (int i = 1; i < len ; i++) {
        std::cout << ", " << i << ": " << v[i] ;
    }
    std::cout << "}; \n";
}

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

#endif  // ALGOUTILS_H_