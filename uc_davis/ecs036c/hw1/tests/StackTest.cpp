#include <gtest/gtest.h>
#include "Stack.cpp"

// TODO: Uncomment the following test

TEST(StackTest, InstantiateEmptyStack)
{
    Stack<int> stack;
    ASSERT_EQ(stack.size(), 0);
    ASSERT_EQ(stack.top(), std::nullopt);
}

// TODO: Add more tests for Stack here

TEST(StackTest, InstantiateFromVector)
{
    Stack<int> stack(std::vector<int>{17, 19, 23});
    ASSERT_EQ(stack.size(), 3);
    ASSERT_EQ(stack.top(), 23);
}

TEST(StackTest, push)
{
    Stack<int> stack(std::vector<int>{17, 19, 23});
    
    stack.push(15);

    ASSERT_EQ(stack.size(), 4);
    ASSERT_EQ(stack.top(), 15);
}

TEST(StackTest, pop)
{
    Stack<int> stack;
    
    std::optional<int> value = stack.pop();

    ASSERT_EQ(stack.size(), 0);
    ASSERT_EQ(value, std::nullopt);

    stack.push(5);
    value = stack.pop();

    ASSERT_EQ(stack.size(), 0);
    ASSERT_EQ(value, 5);
}
