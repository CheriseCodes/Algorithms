#ifndef LINKED_LIST_
#define LINKED_LIST_

template <typename T>
class LLNode {
    LLNode<T> * prev_;
    LLNode<T> * next_;
    T value_;
    public:
        LLNode(): prev_{nullptr}, next_{nullptr}, value_{} {};
        LLNode(T value): prev_{nullptr},  next_{nullptr}, value_{value} {};
        LLNode(T value, LLNode<T> * next): prev_{nullptr}, next_{next}, value_{value} {};
        LLNode(T value, LLNode<T> * next, LLNode<T> * prev): prev_{prev}, next_{next}, value_{value} {};
        T value() { return value_; }
        LLNode<T> * next() { return next_; }
        LLNode<T> * prev() { return prev_; }
        bool has_next() { return next_ != nullptr;}
        bool has_prev() { return prev_ != nullptr;}
        void set_next(LLNode<T> * next) {next_ = next;}
        void set_prev(LLNode<T> * prev) {prev_ = prev;}
};

template <typename T>
class LinkedList {
    LLNode<T> * root_;
    public:
        LinkedList(): root_{nullptr} {};
        LinkedList(LLNode<T> * root): root_{root} {};
        LLNode<T> * search(T key);
        void insert(T key);
        void remove(T key);
        void remove(LLNode<T> * node);
        LLNode<T> * root() { return root_; }
        bool is_empty() {return root_ == nullptr; }
};

template <typename T>
LLNode<T> * LinkedList<T>::search(T key) {
    LLNode<T> * pointer = root_;
    while ((pointer->has_next()) && (pointer->value() != key))
        pointer = pointer->next();

    if (pointer->has_next()) {
        return pointer->next();
    } else {
        return pointer;
    }
}

template <typename T>
void LinkedList<T>::insert(T key) {
    LLNode<T> new_node = LLNode<T>(key);
    new_node.set_next(root_);
    if (new_node.has_next()) {
        (new_node.next())->set_prev(&new_node);
    }
    root_ = &new_node;
    root_->set_prev(nullptr);
}

template <typename T>
void LinkedList<T>::remove(LLNode<T> * node) {
    if (node->has_prev()) {
        node->prev()->set_next(node->next());
    } else {
        root_ = node->next();
    }
    if (node->has_next()) 
        node->next()->set_prev(node->prev());
}

template <typename T>
void LinkedList<T>::remove(T key) {
    LLNode<T> * found = search(key);
    if (found != nullptr) {
        remove(found);
    }
}


#endif // LINKED_LIST_
