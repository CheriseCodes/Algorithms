#ifndef LINKED_LIST_
#define LINKED_LIST_

template <typename T>
class LLNode {
    LLNode & prev_;
    LLNode & next_;
    T value_;
    public:
        LLNode(): prev_{0}, next_{0}, value_{} {};
        LLNode(T value): value_{value} {};
        LLNode(LLNode & next): next_{next} {};
        LLNode(T value, LLNode & next): value_{value}, next_{next} {};
        LLNode(T value, LLNode & next, LLNode & prev): value_{value}, next_{next}, prev_{prev} {};
        T value() { return value_; }
};



#endif // LINKED_LIST_