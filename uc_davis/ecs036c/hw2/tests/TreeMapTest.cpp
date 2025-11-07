#include <gtest/gtest.h>
#include "TreeMap.cpp"

TEST(TreeMapTest, TreeMapStuff)
{
    TreeMap<int, string> treeMap;

    ASSERT_EQ(treeMap.size(), 0);
    ASSERT_EQ(treeMap.is_empty(), true);

    treeMap.insert(5, "Bob");
    treeMap.insert(7, "Fred");
    treeMap.insert(13, "Bobby");

    ASSERT_EQ(treeMap.size(), 3);
    ASSERT_EQ(treeMap.is_empty(), false);

    ASSERT_EQ(treeMap.get(17), std::nullopt);

    ASSERT_EQ(treeMap.contains(15), false);
}