#include <gtest/gtest.h>
#include "Graph.cpp"

TEST(GraphTest, InstantiateEmptyGraph)
{
    Graph<int> g;
    
    ASSERT_EQ(g.size(), 0);

    ASSERT_FALSE(g.hasEdge(1, 2));
    ASSERT_FALSE(g.hasEdge(1, 3));
    ASSERT_FALSE(g.hasEdge(2, 3));

    ASSERT_EQ(g.getNeighbors(1), std::nullopt);
    ASSERT_EQ(g.getNeighbors(2), std::nullopt);
    ASSERT_EQ(g.getNeighbors(3), std::nullopt);
}

TEST(GraphTest, InstantiateFromVector)
{
    std::vector<std::pair<int, int>> edges({{1, 2}, {1, 3}, {2, 3}});
    
    Graph<int> g(edges);
    
    ASSERT_EQ(g.size(), 3);
    
    ASSERT_TRUE(g.hasEdge(1, 2));
    ASSERT_TRUE(g.hasEdge(1, 3));
    ASSERT_TRUE(g.hasEdge(2, 3));
    
    ASSERT_FALSE(g.hasEdge(2, 1));
    ASSERT_FALSE(g.hasEdge(3, 1));
    ASSERT_FALSE(g.hasEdge(3, 2));

    ASSERT_EQ(g.getNeighbors(1), std::set<int>({2, 3}));
    ASSERT_EQ(g.getNeighbors(2), std::set<int>({3}));
    ASSERT_EQ(g.getNeighbors(3), std::set<int>({}));
    ASSERT_EQ(g.getNeighbors(4), std::nullopt);

    std::vector<std::pair<int, int>> edges2({});

    Graph<int> g2(edges2);

    ASSERT_EQ(g2.size(), 0);

    ASSERT_FALSE(g2.hasEdge(1, 2));
    ASSERT_FALSE(g2.hasEdge(1, 3));
    ASSERT_FALSE(g2.hasEdge(2, 3));
    ASSERT_FALSE(g2.hasEdge(2, 1));
    ASSERT_FALSE(g2.hasEdge(3, 1));
    ASSERT_FALSE(g2.hasEdge(3, 2));

    ASSERT_EQ(g2.getNeighbors(1), std::nullopt);
    ASSERT_EQ(g2.getNeighbors(2), std::nullopt);
    ASSERT_EQ(g2.getNeighbors(3), std::nullopt);


    std::vector<std::pair<int, int>> edges3({{1, 1}, {1, 1}, {2, 3}, {1, 2}, {4, 5}});

    Graph<int> g3(edges3);

    ASSERT_EQ(g3.size(), 5);

    ASSERT_TRUE(g3.hasEdge(1, 1));
    ASSERT_TRUE(g3.hasEdge(2, 3));
    ASSERT_TRUE(g3.hasEdge(1, 2));
    ASSERT_TRUE(g3.hasEdge(4, 5));

    ASSERT_FALSE(g3.hasEdge(3, 2));
    ASSERT_FALSE(g3.hasEdge(2, 1));
    ASSERT_FALSE(g3.hasEdge(5, 4));

    ASSERT_EQ(g3.getNeighbors(1), std::set<int>({1, 2}));
    ASSERT_EQ(g3.getNeighbors(2), std::set<int>({3}));
    ASSERT_EQ(g3.getNeighbors(3), std::set<int>({}));
    ASSERT_EQ(g3.getNeighbors(4), std::set<int>({5}));
    ASSERT_EQ(g3.getNeighbors(5), std::set<int>({}));
    ASSERT_EQ(g3.getNeighbors(6), std::nullopt);
}

TEST(GraphTest, InstantiateFromAdjacencyList) {
    std::map<char, std::set<char>> adjList;
    adjList['w'] = { 'r', 'v', 'x', 'z' };
    adjList['r'] = { 'w', 't', 's' };
    adjList['t'] = { 'r', 'u' };
    adjList['u'] = { 't', 's', 'y' };
    adjList['s'] = { 'r', 'u', 'v' };
    adjList['v'] = { 'w', 's', 'y' };
    adjList['x'] = { 'w', 'y', 'z' };
    adjList['y'] = { 'x', 'u', 'v' };
    adjList['z'] = { 'w', 'x' };

    Graph<char> g(adjList);
    ASSERT_EQ(g.size(), 9);
    ASSERT_EQ(g.getNeighbors('w'), std::set<char>({'r', 'v', 'x', 'z'}));

    std::map<char, std::set<char>> adjList2;
    Graph<char> g2(adjList2);
    ASSERT_EQ(g2.size(), 0);
}

TEST(GraphTest, AddVertex)
{
    Graph<char> g;
    g.addVertex('a');

    ASSERT_EQ(g.size(), 1);
    ASSERT_FALSE(g.hasEdge('a', 'b'));
    ASSERT_EQ(g.getNeighbors('a').value().size(), 0);

    g.addVertex('a');
    ASSERT_EQ(g.size(), 1);
    ASSERT_FALSE(g.hasEdge('a', 'b'));
    ASSERT_EQ(g.getNeighbors('a').value().size(), 0);

    g.addVertex('b');
    ASSERT_EQ(g.size(), 2);
    ASSERT_FALSE(g.hasEdge('a', 'b'));
    ASSERT_EQ(g.getNeighbors('a').value().size(), 0);
    ASSERT_EQ(g.getNeighbors('b').value().size(), 0);

    g.addVertex('b');
    ASSERT_EQ(g.size(), 2);
    ASSERT_FALSE(g.hasEdge('a', 'b'));
    ASSERT_EQ(g.getNeighbors('a').value().size(), 0);
    ASSERT_EQ(g.getNeighbors('b').value().size(), 0);

    g.addVertex('c');
    g.addVertex('d');
    g.addVertex('e');
    ASSERT_EQ(g.size(), 5);
    ASSERT_FALSE(g.hasEdge('a', 'b'));
    ASSERT_EQ(g.getNeighbors('a').value().size(), 0);
    ASSERT_EQ(g.getNeighbors('b').value().size(), 0);
    ASSERT_EQ(g.getNeighbors('c').value().size(), 0);
    ASSERT_EQ(g.getNeighbors('d').value().size(), 0);
    ASSERT_EQ(g.getNeighbors('e').value().size(), 0);
}

TEST(GraphTest, AddEdge) {
    Graph<char> g;
    g.addEdge('a', 'b');

    ASSERT_EQ(g.size(), 2);
    ASSERT_TRUE(g.hasEdge('a', 'b'));
    ASSERT_EQ(g.getNeighbors('a'), std::set<char>({'b'}));
    ASSERT_EQ(g.getNeighbors('b'), std::set<char>({}));

    g.addEdge('a', 'b');
    ASSERT_EQ(g.size(), 2);
    ASSERT_TRUE(g.hasEdge('a', 'b'));
    ASSERT_EQ(g.getNeighbors('a'), std::set<char>({'b'}));
    ASSERT_EQ(g.getNeighbors('b'), std::set<char>({}));

    g.addEdge('a', 'c');
    ASSERT_EQ(g.size(), 3);
    ASSERT_TRUE(g.hasEdge('a', 'b'));
    ASSERT_TRUE(g.hasEdge('a', 'c'));
    ASSERT_EQ(g.getNeighbors('a'), std::set<char>({'b', 'c'}));
    ASSERT_EQ(g.getNeighbors('b'), std::set<char>({}));
    ASSERT_EQ(g.getNeighbors('c'), std::set<char>({}));

    g.addEdge('a', 'c');
    ASSERT_EQ(g.size(), 3);
    ASSERT_EQ(g.getNeighbors('a'), std::set<char>({'b', 'c'}));
    ASSERT_EQ(g.getNeighbors('b'), std::set<char>({}));
    ASSERT_EQ(g.getNeighbors('c'), std::set<char>({}));

    g.addEdge('a', 'a');
    ASSERT_EQ(g.size(), 3);
    ASSERT_EQ(g.getNeighbors('a'), std::set<char>({'a', 'b', 'c'}));
    ASSERT_EQ(g.getNeighbors('b'), std::set<char>({}));
    ASSERT_EQ(g.getNeighbors('c'), std::set<char>({}));

    g.addEdge('b', 'a');
    g.addEdge('b', 'c');
    ASSERT_EQ(g.size(), 3);
    ASSERT_EQ(g.getNeighbors('a'), std::set<char>({'a', 'b', 'c'}));
    ASSERT_EQ(g.getNeighbors('b'), std::set<char>({'a', 'c'}));
    ASSERT_EQ(g.getNeighbors('c'), std::set<char>({}));
    ASSERT_EQ(g.getNeighbors('d'), std::nullopt);

    g.addEdge('b', 'd');
    ASSERT_EQ(g.size(), 4);
    ASSERT_EQ(g.getNeighbors('a'), std::set<char>({'a', 'b', 'c'}));
    ASSERT_EQ(g.getNeighbors('b'), std::set<char>({'a', 'c', 'd'}));
    ASSERT_EQ(g.getNeighbors('c'), std::set<char>({}));
    ASSERT_EQ(g.getNeighbors('d'), std::set<char>({}));
}
