#include <iostream>
using namespace std;
// Simple Graph using Adj. Matrix
class GraphMatrix {
public:
    int nodes;
    int adj[10][10]; // Fixed-size matrix for simplicity

    GraphMatrix(int n) {
        nodes = n; 
        // Initialize matrix with 0
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                adj[i][j] = 0;
            } }
 }
  // Add an edge (u -> v)
    void addEdge(int u, int v) {
        adj[u][v] = 1;      // Set edge
        adj[v][u] = 1;      // For undirected graph
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

int main() {
    GraphMatrix g(4);

    g.addEdge(0, 1);  // work with both (0,1) and (1,0)
    g.addEdge(0, 2);  // as above (0,2) and (2,0)
    g.addEdge(1, 3); // as above (1,3) and (3,1)

    g.display();	 //call the function. 
// We can also write the whole function here instead of inside the class 

    return 0;
}

};
