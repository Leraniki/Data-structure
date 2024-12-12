#include "queue.h"

#include <gtest.h>

TEST(QueueTest, is_empty) {
    Queue<int> q(5);

    EXPECT_EQ(q.empty(), true);
}

TEST(QueueTest, push) {
    Queue<int> q(5);

    q.push(10);

    ASSERT_EQ(q.get_size(), 1);
    ASSERT_EQ(q.front(), 10);
}

TEST(QueueTest, pop) {
    Queue<int> q(5);

    q.push(20);
    q.pop();

    EXPECT_EQ(q.empty(), true);    
}


TEST(QueueTest, push_pop) {
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

TEST(QueueTest, is_full) {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.push(3);

    ASSERT_TRUE(q.full());

}


TEST(QueueTest, pop_from_empty) {
    Queue<int> q(3);

    ASSERT_ANY_THROW(q.pop());
}


TEST(QueueTest, front_from_empty) {
    Queue<int> q(3);

    ASSERT_ANY_THROW(q.front());
}
