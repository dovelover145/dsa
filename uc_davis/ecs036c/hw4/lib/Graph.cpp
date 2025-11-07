#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Graph.hpp"
#include "GraphNode.hpp"
#include <queue>
#include <stack>

// TODO: Implement all other methods defined in Graph.hpp here

template <typename T>
Graph<T>::Graph(const std::vector<std::pair<T, T>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {

        // (vertex1, vertex2) = vertex1 -> vertex2

        T vertex1 = edges[i].first;  // get the first vertex
        T vertex2 = edges[i].second; // get the second vertex

        std::set<T> adjList1; // construct the adjacency list of the first vertex
        std::set<T> adjList2; // construct the adjacency list of the second vertex

        GraphNode<T> node1(vertex1);
        GraphNode<T> node2(vertex2);

        for (int j = i; j < edges.size(); j++)
        {
            if (edges[j].first == vertex1)
            {
                adjList1.insert(edges[j].second);
            }
            else if (edges[j].first == vertex2)
            {
                adjList2.insert(edges[j].second);
            }
        }

        _adjList.insert({vertex1, adjList1});
        _adjList.insert({vertex2, adjList2});

        _vertices.insert({vertex1, node1});
        _vertices.insert({vertex2, node2});
    }
}

template <typename T>
Graph<T>::Graph(const std::map<T, std::set<T>> &adjList)
{
    _adjList = adjList;
    for (typename std::map<T, std::set<T>>::const_iterator i = adjList.begin(); i != adjList.end(); i++)
    {
        GraphNode<T> node(i->first);
        _vertices.insert({i->first, node});
    }
}

template <typename T>
int Graph<T>::size() const
{
    return _vertices.size();
}

template <typename T>
void Graph<T>::addVertex(T vertex)
{
    GraphNode<T> node(vertex);
    std::set<T> adjList;
    _adjList.insert({vertex, adjList});
    _vertices.insert({vertex, node});
}

template <typename T>
void Graph<T>::addEdge(T from, T to)
{
    typename std::map<T, std::set<T>>::iterator i = _adjList.find(from);
    if (i != _adjList.end())
    {
        i->second.insert(to);
    }
    else
    {
        std::set<T> adjList;
        adjList.insert(to);
        _adjList.insert({from, adjList});
    }

    std::set<T> adjList;
    _adjList.insert({to, adjList});

    GraphNode<T> node1(from);
    GraphNode<T> node2(to);

    _vertices.insert({from, node1});
    _vertices.insert({to, node2});
}

template <typename T>
bool Graph<T>::hasEdge(T from, T to) const
{
    typename std::map<T, std::set<T>>::const_iterator i = _adjList.find(from);
    if (i != _adjList.end())
    {
        std::set<T> adjList = i->second;
        for (typename std::set<T>::const_iterator j = adjList.begin(); j != adjList.end(); j++)
        {
            if (*j == to)
            {
                return true;
            }
        }
    }
    return false;
}

template <typename T>
std::optional<std::set<T>> Graph<T>::getNeighbors(T vertex) const
{
    typename std::map<T, std::set<T>>::const_iterator i = _adjList.find(vertex);
    if (i != _adjList.end())
    {
        return i->second;
    }
    else
    {
        return std::nullopt;
    }
}

template <typename T>
std::vector<T> Graph<T>::BFS(T start)
{
    std::vector<T> vector;
    std::queue<GraphNode<T>> queue;

    for (typename std::map<T, GraphNode<T>>::iterator i = _vertices.begin(); i != _vertices.end(); i++)
    {
        if (i->first == start)
        {
            i->second.distance = 0;
            i->second.predecessor = std::nullopt;
            queue.push(i->second);
        }
        else
        {
            i->second.distance = -1;
            i->second.predecessor = std::nullopt;
        }
    }

    while (!queue.empty())
    {
        GraphNode<T> u = queue.front();
        queue.pop();
        std::optional<std::set<T>> adjList = getNeighbors(u.value);
        if (adjList != std::nullopt)
        {
            for (typename std::set<T>::iterator i = adjList.value().begin(); i != adjList.value().end(); i++)
            {
                if ((*this)[*i].distance == -1)
                {
                    (*this)[*i].distance = u.distance + 1;
                    (*this)[*i].predecessor = u.value;
                    queue.push((*this)[*i]);
                }
            }
        }
        vector.push_back(u.value);
    }
    return vector;
}

template <typename T>
int Graph<T>::shortestPath(T start, T end)
{
    std::vector<T> vector = BFS(start);
    if (vector.empty())
    { // both values are not present in the graph
        return -1;
    }
    else if (vector.size() != 0 && start != end && (*this)[end].distance == 0)
    { // the first value is not present in the graph and the second value is
        return -1;
    }
    else
    { // the second value is not present in the graph, or both values are in the graph
        return (*this)[end].distance;
    }
}

template <typename T>
void Graph<T>::DFS_visit(const T &u, int &time, std::list<T> &record)
{
    time++;
    typename std::map<T, GraphNode<T>>::iterator uNode = _vertices.find(u);
    uNode->second.discovery_time = time;
    uNode->second.color = Gray;
    std::optional<std::set<T>> adjList = getNeighbors(u);
    if (adjList != std::nullopt) {
        for (typename std::set<T>::iterator i = adjList.value().begin(); i != adjList.value().end(); i++) {
            typename std::map<T, GraphNode<T>>::iterator vNode = _vertices.find(*i);
            if (vNode->second.color == White) {
               vNode->second.predecessor = u;
               DFS_visit(vNode->second.value, time, record); 
            }
        }
    }
    time++;
    uNode->second.finish_time = time;
    uNode->second.color = Black;
    record.push_front(uNode->second.value);
}

template <typename T>
std::list<T> Graph<T>::DFS()
{
    std::list<T> record;

    for (typename std::map<T, GraphNode<T>>::iterator i = _vertices.begin(); i != _vertices.end(); i++)
    {
        i->second.color = White;
        i->second.predecessor = std::nullopt;
    }

    int time = 0;

    for (typename std::map<T, GraphNode<T>>::iterator i = _vertices.begin(); i != _vertices.end(); i++)
    {
        if (i->second.color == White)
        {
            DFS_visit(i->second.value, time, record);
        }
    }

    return record;
}

#endif // GRAPH_CPP