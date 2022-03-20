#include <iostream>
#include <vector>
#include "queue.h"

int main() {
    const int queue_size = 2;
    Queue my_queue = Queue<int, queue_size>();
    puts("Init empty queue...");
    std::cout << "head_: " << my_queue.head() << " tail_: " << my_queue.tail() << std::endl;
    std::cout << "empty: " << my_queue.empty() << " full: " << my_queue.full() << " peek: "<< my_queue.peek() << std::endl;
    my_queue.enqueue(1);
    puts("Enqueue 1...");
    std::cout << "head_: " << my_queue.head() << " tail_: " << my_queue.tail() << std::endl;
    std::cout << "empty: " << my_queue.empty() << " full: " << my_queue.full() << " peek: "<< my_queue.peek() << std::endl;
    my_queue.enqueue(2);
    puts("Enqueue 2...");
    std::cout << "head_: " << my_queue.head() << " tail_: " << my_queue.tail() << std::endl;
    std::cout << "empty: " << my_queue.empty() << " full: " << my_queue.full() << " peek: "<< my_queue.peek() << std::endl;
    int dequeued = my_queue.dequeue();
    puts("Dequeue...");
    std::cout << "head_: " << my_queue.head() << " tail_: " << my_queue.tail() << std::endl;
    std::cout << "empty: " << my_queue.empty() << " full: " << my_queue.full() << " peek: "<< my_queue.peek() << " dequeued: " << dequeued << std::endl;
    dequeued = my_queue.dequeue();
    puts("Dequeue...");
    std::cout << "head_: " << my_queue.head() << " tail_: " << my_queue.tail() << std::endl;
    std::cout << "empty: " << my_queue.empty() << " full: " << my_queue.full() << " peek: "<< my_queue.peek() << " dequeued: " << dequeued << std::endl;
    my_queue.enqueue(3);
    puts("Enqueue 3...");
    std::cout << "head_: " << my_queue.head() << " tail_: " << my_queue.tail() << std::endl;
    std::cout << "empty: " << my_queue.empty() << " full: " << my_queue.full() << " peek: "<< my_queue.peek() << std::endl;
    my_queue.enqueue(4);
    puts("Enqueue 4...");
    std::cout << "head_: " << my_queue.head() << " tail_: " << my_queue.tail() << std::endl;
    std::cout << "empty: " << my_queue.empty() << " full: " << my_queue.full() << " peek: "<< my_queue.peek() << std::endl;
    dequeued = my_queue.dequeue();
    puts("Dequeue...");
    std::cout << "head_: " << my_queue.head() << " tail_: " << my_queue.tail() << std::endl;
    std::cout << "empty: " << my_queue.empty() << " full: " << my_queue.full() << " peek: "<< my_queue.peek() << " dequeued: " << dequeued << std::endl;
    dequeued = my_queue.dequeue();
    puts("Dequeue...");
    std::cout << "head_: " << my_queue.head() << " tail_: " << my_queue.tail() << std::endl;
    std::cout << "empty: " << my_queue.empty() << " full: " << my_queue.full() << " peek: "<< my_queue.peek() << " dequeued: " << dequeued << std::endl;
    
    return 0;
}
