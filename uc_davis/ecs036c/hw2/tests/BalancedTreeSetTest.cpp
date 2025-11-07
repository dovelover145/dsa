#include "TreeSet.cpp"
#include <gtest/gtest.h>


TEST(BalancedTreeSetTest, InstantiateEmptyTree)
{
    TreeSet<int> s{};

    ASSERT_TRUE(s.is_balanced());
}


TEST(BalancedTreeSetTest, RedBlackTreeTests) {
    TreeSet<int> s;

    ASSERT_TRUE(s.is_balanced());

    s.add(1);

    ASSERT_TRUE(s.is_balanced());

    s.add(7);

    ASSERT_TRUE(s.is_balanced());

    s.add(15);
    s.add(65);
    s.add(17);
    s.add(15);
    s.add(77);

    ASSERT_TRUE(s.is_balanced());

    s.add(901);
    s.add(0);
    s.add(77);
    s.add(601);

    ASSERT_TRUE(s.is_balanced());

    TreeSet<int> s2({17, 85, 69, 701, 1023, 3, 1, 2, 901, 1001, 1002, 1003, 1004, 76, 85});

    ASSERT_TRUE(s2.is_balanced());
}

