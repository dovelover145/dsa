#include <gtest/gtest.h>
#include "qsort.cpp"

TEST(QuickSortTest, SortEmpty)
{
    std::vector<int> v;
    quick_sort(v.begin(), v.end(), std::less<int>());
    std::vector<int> expected;
    ASSERT_EQ(v, expected);
}

TEST(QuickSortTest, SortVectorWithOneElement)
{
    std::vector<int> v{1};
    quick_sort(v.begin(), v.end(), std::less<int>());
    std::vector<int> expected{1};
    ASSERT_EQ(v, expected);
}

TEST(QuickSortTest, SortVectorWithMultipleElement)
{
    std::vector<int> v{1, 7, 19, 35, 78, 92, 106, 75, 1034, 97, 1, 200, 96};
    quick_sort(v.begin(), v.end(), std::less<int>());
    std::vector<int> expected{1, 1, 7, 19, 35, 75, 78, 92, 96, 97, 106, 200, 1034};
    ASSERT_EQ(v, expected);

    std::vector<int> v2{1, 2, 5, 7, 8};
    quick_sort(v2.begin(), v2.end(), std::greater<int>());
    std::vector<int> expected2{8, 7, 5, 2, 1};
    ASSERT_EQ(v2, expected2);

    std::vector<int> v3{800, 7, 95, 38, 64, 72, 1};
    quick_sort(v3.begin(), v3.end(), std::less<int>());
    std::vector<int> expected3{1, 7, 38, 64, 72, 95, 800};
    ASSERT_EQ(v3, expected3);
}

// TODO: Add more tests here
