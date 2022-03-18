#ifndef STACK_H_
#define STACK_H_

#include <array>
#include <stdexcept>

template <typename T, int max_size>
class Stack {
  int top_;
  std::array<T, max_size> arr_;
public:
    Stack(): top_{-1}, arr_{} {};
    bool empty() { return top_ == -1; }
    int top() { return top_; }
    T peek() { return arr_[top_];}
    void push(T item);
    T pop();
};

template <typename T, int max_size>
void Stack<T,max_size>::push(T item) {
    arr_[++top_] = item;
}

template <typename T, int max_size>
T Stack<T, max_size>::pop() {
    if (empty())
        throw std::underflow_error("stack underflow");
    
    return arr_[top_--];
}

#endif  // STACK_H_