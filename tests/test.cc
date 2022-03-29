#include <gtest/gtest.h>
#include "../linked_list.h"

TEST(LinkedList, IntializeEmptyNode) {
    LLNode<int> lln = LLNode<int>();
    EXPECT_EQ(lln.value(), 0);
}

TEST(LinkedList, SearchWithOneItem) {
    LLNode<int> n = LLNode<int>(1);
    LinkedList<int> ll = LinkedList<int>(&n);
    LLNode<int> * found = ll.search(1);
    EXPECT_EQ(found->value(), 1);
}

TEST(LinkedList, InsertIntoEmptyList) {
    LinkedList<int> ll = LinkedList<int>();
    ll.insert(1);
    EXPECT_EQ(ll.root()->value(), 1); 
}

TEST(LinkedList, DeleteNodeFromListWithOneItem) {
    LLNode<int> n = LLNode<int>(1);
    LinkedList<int> ll = LinkedList<int>(&n);
    ll.remove(&n);
    EXPECT_TRUE(ll.is_empty());
}

TEST(LinkedList, DeleteKeyFromListWithOneItem) {
    LLNode<int> n = LLNode<int>(1);
    LinkedList<int> ll = LinkedList<int>(&n);
    ll.remove(1);
    EXPECT_TRUE(ll.is_empty());
}




