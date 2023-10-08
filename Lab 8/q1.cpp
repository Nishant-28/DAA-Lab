// Graph Algorithms - Graph traversal

// Aim of the program: Consider an undirected graph where each edge weights 2 units. Each of the nodes is labeled consecutively from 1 to n. The user will input a list of edges for describing an undirected graph. After representation of the graph, from a given starting position
// ● Display the breadth-first search traversal.
// ● Determine and display the shortest distance to each of the other nodes using the breadth- first search algorithm. Return an array of distances from the start node in node number order. If a node is unreachable, return -1 for that node.

// Input Format:

// The first line contains two space-separated integers ‘n’ and ‘m’, the number of nodes and edges in the graph.
// Each line ‘i’ of the ‘m’ subsequent lines contains two space-separated integers ‘u’ and ‘v’, that describe an edge between nodes ‘u’ and ‘v’.
// The last line contains a single integer ‘s’, the node number to start from.

// Output Format:

// The first line shows the result of the BFS traversal.
// The last line shows an array of distances from node ‘s’ to all other nodes.

// Input:
// 5 4
// 1 2
// 1 4
// 4 5
// 2 5
// 1

// Output:
// BFS Traversal: 1 2 4 5
// Distance [2 -1 2 4]
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list representation of the graph

vector<int> bfs(int start, int n) {
    vector<int> distance(n + 1, -1); // Initialize distances to -1 (unreachable)
    queue<int> q;

    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 2; // Edge weight is 2
                q.push(v);
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    adj.resize(n + 1);

    cout << "Enter the edges: (a,b) " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected graph
    }

    int start;
    cin >> start;

    vector<int> distance = bfs(start, n);

    // BFS Traversal
    cout << "BFS Traversal:";
    for (int i = 1; i <= n; i++) {
        if (distance[i] != -1) {
            cout << " " << i;
        }
    }
    cout << endl;

    // Distance from the start node to all other nodes
    cout << "Distance [";
    for (int i = 1; i <= n; i++) {
        cout << distance[i];
        if (i < n) {
            cout << " ";
        }
    }
    cout << "]" << endl;

    return 0;
}
