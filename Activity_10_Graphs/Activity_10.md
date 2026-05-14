# Graphs: Breadth-First Search and Depth-First Search

## 1. Theoretical Graph

For this assignment, I created a simple undirected graph with 6 vertices.

Vertices:

A, B, C, D, E, F

Edges:

A - B  
A - C  
B - D  
B - E  
C - F  

Graph structure:

        A
       / \
      B   C
     / \   \
    D   E   F

## 2. C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << char(current + 'A') << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }

    void DFSHelper(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << char(current + 'A') << " ";

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                DFSHelper(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(vertices, false);

        cout << "DFS Traversal: ";
        DFSHelper(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);

    // A = 0, B = 1, C = 2, D = 3, E = 4, F = 5
    g.addEdge(0, 1); // A-B
    g.addEdge(0, 2); // A-C
    g.addEdge(1, 3); // B-D
    g.addEdge(1, 4); // B-E
    g.addEdge(2, 5); // C-F

    g.BFS(0);
    g.DFS(0);

    return 0;
}
```
3. Expected Output
BFS Traversal: A B C D E F
DFS Traversal: A B D E C F

4. Comparison of BFS and DFS Using Big O Notation

Both Breadth-First Search and Depth-First Search have the same time complexity when using an adjacency list.

The time complexity is:

O(V + E)

V represents the number of vertices, and E represents the number of edges.

BFS visits each vertex once and checks each edge connected to that vertex. DFS also visits each vertex once and checks each edge. Because of this, both algorithms are efficient for searching through graphs.


5. Conclusion

In this assignment, I created a simple undirected graph and implemented both BFS and DFS in C++. BFS used a queue to visit nodes level by level, while DFS used recursion to go deeper into the graph before backtracking. Even though both algorithms have the same Big O time complexity, they are useful in different situations depending on the problem.
