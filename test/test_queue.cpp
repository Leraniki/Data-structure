#include "queue.h"

#include <gtest.h>

TEST(Queue, is_empty) {
    Queue<int> q(5);

    EXPECT_EQ(q.empty(), true);
}

TEST(Queue, push) {
    Queue<int> q(5);

    q.push(10);

    ASSERT_EQ(q.get_size(), 1);
    ASSERT_EQ(q.front(), 10);
}

TEST(Queue, pop) {
    Queue<int> q(5);

    q.push(20);
    q.pop();

    EXPECT_EQ(q.empty(), true);    
}


TEST(Queue, push_pop) {
    Queue<int> q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();

    ASSERT_EQ(q.get_size(), 2);
    ASSERT_EQ(q.front(), 2);
    q.pop();
    ASSERT_EQ(q.front(), 3);
}

TEST(Queue, is_full) {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.push(3);

    ASSERT_TRUE(q.full());

}


TEST(Queue, pop_from_empty) {
    Queue<int> q(3);

    ASSERT_ANY_THROW(q.pop());
}


TEST(Queue, front_from_empty) {
    Queue<int> q(3);

    ASSERT_ANY_THROW(q.front());
}

TEST(Queue, repacking) {
    Queue<int> q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop(); 

    q.repack();

    ASSERT_EQ(q.get_head(), 0);
    ASSERT_EQ(q.get_tail(), 1);
    ASSERT_EQ(q.size(), 1);
    ASSERT_EQ(q.front(), 3);
}
