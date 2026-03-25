#include <iostream>
#include <stack>
using namespace std;

const int MAX = 100;  // Maximum number of vertices

int adj[MAX][MAX];    // Adjacency matrix
bool visited[MAX];    // Visited array
int V;               // Number of vertices

// Add edge to undirected graph
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Iterative DFS using stack
void dfs(int start) {
    stack<int> s;
    s.push(start);
   while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Push all unvisited adjacent vertices to stack
            for (int i = V - 1; i >= 0; i--) { // Reverse for correct order
                if (adj[node][i] && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
}

int main() {
    V = 5;
    // Initialize adjacency matrix and visited array
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }
    addEdge(1, 2);
    addEdge(1, 0);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(2, 4);

    // Perform DFS starting from vertex 0
    dfs(0);
    cout << endl;

    return 0;
}

