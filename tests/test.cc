#include <gtest/gtest.h>
#include "../linked_list.h"

TEST(DataStructures, IntializeEmptyLinkedList) {
    LLNode<int> ll = LLNode<int>();
    EXPECT_EQ(ll.value(), 0);
}
