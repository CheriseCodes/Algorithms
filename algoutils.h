#ifndef ALGOUTILS_H_
#define ALGOUTILS_H_

template <typename T>
void print_vector(std::vector<T> & v) {
    int len = v.size();
    if (len == 0) std::cout << "v = { }\n";
    std::cout << "v = { " << v[0];
    for (int i = 1; i < len ; i++) {
        std::cout << ", " << v[i] ;
    }
    std::cout << "}; \n";
}

#endif  // ALGOUTILS_H_