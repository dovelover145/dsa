#include "TreeSet.cpp"
#include <gtest/gtest.h>

TEST(TreeSetTest, InstantiateEmptyTree)
{
    TreeSet<int> s{};

    ASSERT_EQ(s.size(), 0);
}

TEST(TreeSetTest, InstantiateTreeWithComparator)
{
    // comparator that returns the opposite of the default comparator
    auto cmp = [](int a, int b)
    {
        if (a < b)
        {
            return 1;
        }
        else if (a > b)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    };
    TreeSet<int> s(cmp);

    ASSERT_EQ(s.size(), 0);

    s.add(1);
    s.add(2);
    s.add(3);
    s.add(4);
    ASSERT_EQ(s.to_vector(), std::vector<int>({4, 3, 2, 1}));
    ASSERT_EQ(s.min(), 4);
}

TEST(TreeSetTest, InstantiateTreeWithVectorAndComparator)
{
    // comparator that returns the opposite of the default comparator
    auto cmp = [](int a, int b)
    {
        if (a < b)
        {
            return 1;
        }
        else if (a > b)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    };
    TreeSet<int> s({4, 3, 2, 1}, cmp);

    ASSERT_EQ(s.size(), 4);

    ASSERT_EQ(s.to_vector(), std::vector<int>({4, 3, 2, 1}));
    ASSERT_EQ(s.min(), 4);
}

TEST(TreeSetTest, UnionTwo)
{
    TreeSet<int> s1({ 1, 2, 3, 4, 5 });
    TreeSet<int> s2({ 3, 4, 5, 6, 7 });
    TreeSet<int> s3 = s1 + s2;

    ASSERT_EQ(s3.size(), 7);
    ASSERT_EQ(s3.to_vector(), std::vector<int>({ 1, 2, 3, 4, 5, 6, 7 }));

    // union should not mutate original sets
    ASSERT_EQ(s1.size(), 5);
    ASSERT_EQ(s1.to_vector(), std::vector<int>({ 1, 2, 3, 4, 5 }));
    ASSERT_EQ(s2.size(), 5);
    ASSERT_EQ(s2.to_vector(), std::vector<int>({ 3, 4, 5, 6, 7 }));
}


TEST(TreeSetTest, Clear)
{
    TreeSet<int> s(std::vector<int>({1, 2, 3, 4, 5}));
    
    ASSERT_EQ(s.is_empty(), false);
    
    s.clear();

    ASSERT_EQ(s.is_empty(), true);

    ASSERT_EQ(s.size(), 0);
    ASSERT_EQ(s.to_vector(), std::vector<int>({}));
}

TEST(TreeSetTest, Add)
{
    TreeSet<int> s;

    s.add(20);

    ASSERT_EQ(s.size(), 1);
    ASSERT_EQ(s.to_vector(), std::vector<int>({20}));

    s.add(20);

    ASSERT_EQ(s.size(), 1);
    ASSERT_EQ(s.to_vector(), std::vector<int>({20}));

    s.add(2);

    ASSERT_EQ(s.size(), 2);
    ASSERT_EQ(s.to_vector(), std::vector<int>({2, 20}));

    s.add(1);

    ASSERT_EQ(s.size(), 3);
    ASSERT_EQ(s.to_vector(), std::vector<int>({1, 2, 20}));

    s.add(19);

    ASSERT_EQ(s.size(), 4);
    ASSERT_EQ(s.to_vector(), std::vector<int>({1, 2, 19, 20}));

    s.add(1);

    ASSERT_EQ(s.size(), 4);
    ASSERT_EQ(s.to_vector(), std::vector<int>({1, 2, 19, 20}));

    s.add(19);

    ASSERT_EQ(s.size(), 4);
    ASSERT_EQ(s.to_vector(), std::vector<int>({1, 2, 19, 20}));

    s.add(20);

    ASSERT_EQ(s.size(), 4);
    ASSERT_EQ(s.to_vector(), std::vector<int>({1, 2, 19, 20}));

    s.add(75);
    s.add(100);
    s.add(50);
    s.add(20);

    ASSERT_EQ(s.size(), 7);
    ASSERT_EQ(s.to_vector(), std::vector<int>({1, 2, 19, 20, 50, 75, 100}));
}

TEST(TreeSetTest, ContainsAndGet)
{
    TreeSet<int> s(std::vector<int>({1, 2, 3, 4, 5}));
    
    ASSERT_EQ(s.contains(1), true);
    ASSERT_EQ(s.contains(2), true);
    ASSERT_EQ(s.contains(5), true);
    ASSERT_EQ(s.contains(3), true);
    ASSERT_EQ(s.contains(4), true);
    ASSERT_EQ(s.contains(17), false);

    ASSERT_EQ(s.get(1), 1);
    ASSERT_EQ(s.get(2), 2);
    ASSERT_EQ(s.get(5), 5);
    ASSERT_EQ(s.get(3), 3);
    ASSERT_EQ(s.get(4), 4);
    ASSERT_EQ(s.get(17), std::nullopt);
    ASSERT_EQ(s.get(15), std::nullopt);

    TreeSet<int> s2;

    ASSERT_EQ(s2.is_empty(), true);

    ASSERT_EQ(s2.contains(5), false);
    
    ASSERT_EQ(s2.get(5), std::nullopt);

    s2.add(5);

    ASSERT_EQ(s2.is_empty(), false);
}

TEST(TreeSetTest, minAndMax) {
    TreeSet<int> s;

    ASSERT_EQ(s.min(), std::nullopt);
    ASSERT_EQ(s.max(), std::nullopt);

    s.add(1);

    ASSERT_EQ(s.min(), 1);
    ASSERT_EQ(s.max(), 1);

    s.add(2);

    ASSERT_EQ(s.min(), 1);
    ASSERT_EQ(s.max(), 2);
}

TEST(TreeSetTest, union) {
    TreeSet<int> s({1, 2, 3, 4, 5});
    TreeSet<int> s2({5, 4, 3, 1, 2});

    ASSERT_EQ((s + s2).to_vector(), std::vector<int>({1, 2, 3, 4, 5}));
    ASSERT_EQ((s + s2).size(), 5);
}

TEST(TreeSetTest, intersection) {
    TreeSet<int> s({1, 2, 3, 4, 5, 8, 7, 9});
    TreeSet<int> s2({5, 4, 3, 1, 2, 13, 98});

    ASSERT_EQ((s & s2).to_vector(), std::vector<int>({1, 2, 3, 4, 5}));
    ASSERT_EQ((s & s2).size(), 5);
}

TEST(TreeSetTest, equalAndNotEqual) {
    TreeSet<int> s({1, 2, 3, 4, 5, 8, 7, 9, 17, 27});
    TreeSet<int> s2({9, 8, 7, 1, 2, 3, 4, 5});

    ASSERT_EQ(s == s2, false);
    ASSERT_EQ(s != s2, true);
}

TEST(TreeSetTest, inPlaceUnion) {
    TreeSet<int> s({9, 8, 7, 1, 2, 3, 4, 5});
    TreeSet<int> s2({7, 17, 25});
    
    ASSERT_EQ(s += s2, s);
    ASSERT_EQ(s.to_vector(), std::vector<int>({1, 2, 3, 4, 5, 7, 8, 9, 17, 25}));
}