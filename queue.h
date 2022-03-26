#ifndef QUEUE_H_
#define QUEUE_H_

#include <array>
#include <stdexcept>

template <typename T, int max_size>
class Queue {
    int max_size_;
    int head_;
    int tail_;
    std::array<T, max_size> arr_;

    public:
        Queue(): max_size_{max_size}, head_{0}, tail_{0}, arr_{} {};
        T peek() { if (head_ == max_size_) {return arr_[0];} else { return arr_[head_]; }}
        int tail() { return tail_;}
        int head() { return head_; }
        bool empty() {return (head_ == tail_);}
        bool full() {return ((head_ == (tail_+1)) || ((head_==0)&&(tail_==max_size_)));}
        T dequeue();
        void enqueue(T item);
};

template <typename T, int max_size>
T Queue<T, max_size>::dequeue() {
    if (empty())
        throw std::underflow_error("can't dequeue from empty queue");
    T res; 
    if (head_ == max_size_) {
        res = arr_[head_-1];
        head_ = 0;
    } else {
        res = arr_[head_];
        head_++;
    }
    return res;
}

template <typename T, int max_size>
void Queue<T, max_size>::enqueue(T item) {
    if (full())
        throw std::overflow_error("can't enqueue to full queue");
    if (tail_ == max_size_) {
        arr_[tail_-1] = item;
        tail_ = 0;
    } else {
        arr_[tail_] = item;
        tail_++;
    }
}

#endif  // QUEUE_H_
