#include <iostream>
#include <vector>
#include "stack.h"

int main() {
    const int stack_size = 10;
    Stack my_stack = Stack<int, stack_size>();
    std::cout << "empty: " << my_stack.empty() << " top: "<< my_stack.top() << std::endl;
    my_stack.push(1);
    std::cout << "empty: " << my_stack.empty() << " top: "<< my_stack.top() << std::endl;
    my_stack.push(2);
    std::cout << "empty: " << my_stack.empty() << " top: "<< my_stack.top() << std::endl;
    int popped = my_stack.pop();
    std::cout << "empty: " << my_stack.empty() << " top: "<< my_stack.top() << " popped: " << popped << std::endl;
    return 0;
}
