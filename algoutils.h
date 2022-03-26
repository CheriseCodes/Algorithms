#ifndef ALGOUTILS_H_
#define ALGOUTILS_H_

#include <vector>
#include <map>

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

std::vector<int> generate_random_int_vector(int v_size);

void print_int_map(std::map<int, int> in_map);

#endif  // ALGOUTILS_H_
