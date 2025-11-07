
#include <gtest/gtest.h>
#include "Graph.cpp"

using namespace std;

Graph<char> getTextbookGraphBFS()
{
    std::map<char, std::set<char>> adjList;
    adjList['w'] = {'r', 'v', 'x', 'z'};
    adjList['r'] = {'w', 't', 's'};
    adjList['t'] = {'r', 'u'};
    adjList['u'] = {'t', 's', 'y'};
    adjList['s'] = {'r', 'u', 'v'};
    adjList['v'] = {'w', 's', 'y'};
    adjList['x'] = {'w', 'y', 'z'};
    adjList['y'] = {'x', 'u', 'v'};
    adjList['z'] = {'w', 'x'};

    Graph<char> g(adjList);
    return g;
}

TEST(BFSTest, InstantiateGraphFromEdges)
{
    Graph<int> g({{1, 2}, {1, 3}, {2, 3}});
    ASSERT_EQ(g.size(), 3);

    std::vector<int> bfs = g.BFS(1);
    std::vector<int> expected{1, 2, 3};

    ASSERT_EQ(bfs.size(), g.size());
    ASSERT_EQ(bfs, expected);

    bfs = g.BFS(2);
    expected = {2, 3};

    ASSERT_EQ(bfs.size(), g.size() - 1);
    ASSERT_EQ(bfs, expected);

    ASSERT_EQ(g.shortestPath(1, 2), 1);
    ASSERT_EQ(g.shortestPath(1, 3), 1);
    ASSERT_EQ(g.shortestPath(1, 1), 0);

    ASSERT_EQ(g.shortestPath(2, 3), 1);
    ASSERT_EQ(g.shortestPath(2, 1), -1);
    ASSERT_EQ(g.shortestPath(2, 2), 0);

    Graph<int> g2;
    ASSERT_EQ(g2.size(), 0);

    std::vector<int> bfs2 = g2.BFS(7);
    std::vector<int> expected2; // expected{};

    ASSERT_EQ(bfs2.size(), g2.size());
    ASSERT_EQ(bfs2, expected2);

    ASSERT_EQ(g2.shortestPath(2, 3), -1);
    ASSERT_EQ(g2.shortestPath(2, 1), -1);
    ASSERT_EQ(g2.shortestPath(2, 2), -1);

    Graph<char> g3(getTextbookGraphBFS());
    ASSERT_EQ(g3.size(), 9);

    std::vector<char> bfs3 = g3.BFS('r');
    std::vector<char> expected3{'r', 's', 't', 'w', 'u', 'v', 'x', 'z', 'y'};

    ASSERT_EQ(bfs3.size(), g3.size());
    ASSERT_EQ(bfs3, expected3);

    ASSERT_EQ(g3.shortestPath('r', 'w'), 1);
    ASSERT_EQ(g3.shortestPath('r', 'u'), 2);
    ASSERT_EQ(g3.shortestPath('r', 'y'), 3);
    ASSERT_EQ(g3.shortestPath('q', 'o'), -1);
    ASSERT_EQ(g3.shortestPath('q', 'r'), -1);
    ASSERT_EQ(g3.shortestPath('r', 'q'), -1);
}
