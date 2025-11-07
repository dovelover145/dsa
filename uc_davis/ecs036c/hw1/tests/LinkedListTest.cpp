#include <gtest/gtest.h>
#include "LinkedList.cpp"

TEST(LinkedListTest, InstantiateEmptyList)
{
    LinkedList<int> llist;

    ASSERT_EQ(llist.head(), nullptr);
    ASSERT_EQ(llist.tail(), nullptr);
    ASSERT_EQ(llist.size(), 0);
}

TEST(LinkedListTest, InstantiateFromVector)
{
    LinkedList<int> llist(std::vector<int>{17, 19, 23});

    ASSERT_EQ(llist.size(), 3);

    LinkedListNode<int> *node = llist.head();
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next()->value, 19);
    ASSERT_EQ(node->next()->next()->value, 23);
    ASSERT_EQ(node->next()->next()->next(), nullptr);
}

TEST(LinkedListTest, AppendToEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.append(17);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next(), nullptr);
    ASSERT_EQ(llist.size(), 1);
}

TEST(LinkedListTest, AppendToNonEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.append(19);

    ASSERT_EQ(first, llist.head());
    ASSERT_EQ(first->value, 17);
    ASSERT_EQ(first->next(), second);

    ASSERT_EQ(second, llist.tail());
    ASSERT_EQ(second->value, 19);
    ASSERT_EQ(second->next(), nullptr);

    ASSERT_EQ(llist.size(), 2);

    /*
    LinkedList<int> llist2;
    LinkedListNode<int> *first2 = llist2.append(17);
    LinkedListNode<int> *second2 = llist2.append(19);
    LinkedListNode<int> *third = llist2.append(15);

    ASSERT_EQ(first2, llist2.head());
    ASSERT_EQ(first2->value, 17);
    ASSERT_EQ(first2->next(), second2);

    ASSERT_EQ(second2->value, 19);
    ASSERT_EQ(second2->next(), third);

    ASSERT_EQ(third, llist2.tail());
    ASSERT_EQ(third->value, 15);
    ASSERT_EQ(third->next(), nullptr);

    ASSERT_EQ(llist2.size(), 3);
    */
}

// TODO: Add more tests for LinkedList here

TEST(LinkedListTest, PrependToEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.prepend(17);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next(), nullptr);
    ASSERT_EQ(llist.size(), 1);
}

TEST(LinkedListTest, PrependToNonEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.prepend(17);
    LinkedListNode<int> *second = llist.prepend(19);

    ASSERT_EQ(second, llist.head());
    ASSERT_EQ(second->value, 19);
    ASSERT_EQ(second->next(), first);

    ASSERT_EQ(first, llist.tail());
    ASSERT_EQ(first->value, 17);
    ASSERT_EQ(first->next(), nullptr);

    ASSERT_EQ(llist.size(), 2);

    LinkedList<int> llist2;
    LinkedListNode<int> *first2 = llist2.prepend(17);
    LinkedListNode<int> *second2 = llist2.prepend(19);
    LinkedListNode<int> *third = llist2.prepend(15);

    ASSERT_EQ(third, llist2.head());
    ASSERT_EQ(third->value, 15);
    ASSERT_EQ(third->next(), second2);

    ASSERT_EQ(second2->value, 19);
    ASSERT_EQ(second2->next(), first2);

    ASSERT_EQ(first2, llist2.tail());
    ASSERT_EQ(first2->value, 17);
    ASSERT_EQ(first2->next(), nullptr);

    ASSERT_EQ(llist2.size(), 3);
}

TEST(LinkedListTest, find)
{
    LinkedList<int> llist;

    LinkedListNode<int> *findNode = llist.find(5);

    ASSERT_EQ(findNode, nullptr);

    LinkedListNode<int> *first = llist.prepend(17);
    LinkedListNode<int> *second = llist.prepend(19);

    findNode = llist.find(17);

    ASSERT_EQ(findNode, first);

    findNode = llist.find(25);

    ASSERT_EQ(findNode, nullptr);

    findNode = llist.find(19);

    ASSERT_EQ(findNode, second);
}

TEST(LinkedListTest, insertAfter)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.insertAfter(nullptr, 17);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next(), nullptr);
    ASSERT_EQ(llist.size(), 1);

    LinkedListNode<int> *node2 = llist.insertAfter(node, 19);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node2, llist.tail());
    ASSERT_EQ(node2->value, 19);
    ASSERT_EQ(node2->next(), nullptr);
    ASSERT_EQ(llist.size(), 2);

    LinkedListNode<int> *node3 = llist.insertAfter(node2, 15);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node3, llist.tail());
    ASSERT_EQ(node3->value, 15);
    ASSERT_EQ(node3->next(), nullptr);
    ASSERT_EQ(llist.size(), 3);

    LinkedListNode<int> *node1_2 = llist.insertAfter(node, 11);

    ASSERT_EQ(node1_2, node->next());
    ASSERT_EQ(node1_2->value, 11);
    ASSERT_EQ(node1_2->next(), node2);
    ASSERT_EQ(llist.size(), 4);

    LinkedListNode<int> *node_1 = llist.insertAfter(nullptr, 10);

    ASSERT_EQ(node_1, llist.head());
    ASSERT_EQ(node_1->value, 10);
    ASSERT_EQ(node_1->next(), node);
    ASSERT_EQ(llist.size(), 5);
}

TEST(LinkedListTest, removeHead)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.append(17);
    LinkedListNode<int> *node2 = llist.append(19);
    LinkedListNode<int> *node3 = llist.append(15);

    llist.removeHead();

    ASSERT_EQ(node2, llist.head());
    ASSERT_EQ(node3, llist.tail());
    ASSERT_EQ(llist.size(), 2);

    llist.removeHead();
    ASSERT_EQ(node3, llist.head());
    ASSERT_EQ(node3, llist.tail());
    ASSERT_EQ(llist.size(), 1);

    llist.removeHead();
    ASSERT_EQ(llist.head(), nullptr);
    ASSERT_EQ(llist.tail(), nullptr);
    ASSERT_EQ(llist.size(), 0);
}

TEST(LinkedListTest, remove)
{
    /*
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.append(17);

    // 17
    llist.remove(15);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());
    ASSERT_EQ(llist.size(), 1);

    // 17
    llist.remove(17);

    ASSERT_EQ(llist.head(), nullptr);
    ASSERT_EQ(llist.tail(), nullptr);
    ASSERT_EQ(llist.size(), 0);

    node = llist.append(17);
    LinkedListNode<int> *node2 = llist.append(19);
    LinkedListNode<int> *node3 = llist.append(15);

    // 17 19 15
    llist.remove(15);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node2, llist.tail());
    ASSERT_EQ(llist.size(), 2);

    node3 = llist.append(22);

    // 17 19 22
    llist.remove(17);

    ASSERT_EQ(node2, llist.head());
    ASSERT_EQ(node3, llist.tail());
    ASSERT_EQ(llist.size(), 2);

    node = llist.prepend(17);
    */

    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.append(17);
    LinkedListNode<int> *node2 = llist.append(19);
    LinkedListNode<int> *node3 = llist.append(15);
    LinkedListNode<int> *node4 = llist.append(11);
    LinkedListNode<int> *node5 = llist.append(20);

    llist.remove(11);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node3->next(), node5);
    ASSERT_EQ(node5, llist.tail());
    ASSERT_EQ(llist.size(), 4);

    llist.remove(20);

    ASSERT_EQ(node3, llist.tail());
    ASSERT_EQ(llist.size(), 3);

    bool b = llist.remove(99);
    ASSERT_EQ(llist.size(), 3);
    ASSERT_EQ(b, false);
}

TEST(LinkedListTest, clear)
{
    LinkedList<int> llist;
    llist.append(1);
    llist.append(2);
    llist.append(3);
    llist.append(4);

    llist.clear();

    ASSERT_EQ(llist.head(), nullptr);
    ASSERT_EQ(llist.tail(), nullptr);
    ASSERT_EQ(llist.size(), 0);
}