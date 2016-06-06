#include "stdafx.h"
#include "general.h"
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <deque>
#include <algorithm>
#include <utility>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <future>
#include <thread>

using namespace std;

class Graph
{
    int vertices;
    list<int>* adjacency;
    void startDFS(int v, vector<bool> visited);
public:
    Graph(int v);
    void addEdge(int a, int b);
    void dfs(int v);
};

Graph::Graph(int v)
{
    this->vertices = v;
    this->adjacency = new list<int>[v];
}

void Graph::addEdge(int a, int b)
{
    this->adjacency[a].push_back(b);
}

void Graph::startDFS(int vertex, vector<bool> visited)
{
    visited[vertex] = true;
    cout << vertex;

    list<int>::iterator i;
    for (i = this->adjacency[vertex].begin(); i != this->adjacency[vertex].end(); i++)
    {
        int adjacentVertex = *i;
        if (!visited[adjacentVertex])
        {
            startDFS(adjacentVertex, visited);
        }
    }
}

void Graph::dfs(int startVertex)
{
    vector<bool> visited(this->vertices);
    startDFS(startVertex, visited);
}

int Graph_DepthFirstSearch_main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.dfs(2);

    return 0;
}

