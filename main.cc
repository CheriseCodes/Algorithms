#include <iostream>
#include <vector>
#include "queue.h"
#include "linked_list.h"

void test_queue() {
    const int queue_size = 2;
    Queue<int,queue_size> my_queue = Queue<int, queue_size>();
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
    
}

void test_linked_list() {
    LLNode<int> root = LLNode<int>(5);
    LinkedList<int> my_ll = LinkedList<int>(&root);
    LLNode<int> * found_node = my_ll.search(5);
    std::cout << found_node->value() << std::endl;
}

int main() {
    test_linked_list();
    return 0;
}
