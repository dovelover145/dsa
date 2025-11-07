#include <gtest/gtest.h>
#include "Queue.cpp"

// TODO: Uncomment the following test

TEST(QueueTest, InstantiateEmptyQueue)
{
    Queue<int> queue;
    ASSERT_EQ(queue.size(), 0);
}

// TODO: add more tests for Queue below

TEST(QueueTest, InstantiateFromVector)
{
    Queue<int> queue(std::vector<int>{17, 19, 23});

    ASSERT_EQ(queue.size(), 3);
}

TEST(QueueTest, enqueue)
{
    Queue<int> queue(std::vector<int>{17, 19, 23});

    ASSERT_EQ(queue.size(), 3);

    queue.enqueue(15);

    ASSERT_EQ(queue.size(), 4);
}

TEST(QueueTest, dequeue)
{
    Queue<int> queue(std::vector<int>{17, 19, 23});

    ASSERT_EQ(queue.size(), 3);

    std::optional<int> value = queue.dequeue();

    ASSERT_EQ(queue.size(), 2);
    ASSERT_EQ(value, 17);

    value = queue.dequeue();

    ASSERT_EQ(queue.size(), 1);
    ASSERT_EQ(value, 19);

    value = queue.dequeue();

    ASSERT_EQ(queue.size(), 0);
    ASSERT_EQ(value, 23);

    value = queue.dequeue();

    ASSERT_EQ(queue.size(), 0);
    ASSERT_EQ(value, std::nullopt);
}
