#include <iostream>
#include <queue>
using namespace std;

#define MAX 10   // maximum number of vertices

// BFS function for one connected component
void bfs(int adj[MAX][MAX], int V) {

    bool visited[MAX] = {false};   // visited array
    queue<int> q;

    int src = 0;                   // starting point src = source
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << " ";       // print node
        // check all neighbours
        for (int i = 0; i < V; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }        }      }    }
int main() {
    int V = 5;
    int adj[MAX][MAX] = {0};       // adjacency matrix
    // adding edges (undirected)
    adj[1][2] = adj[2][1] = 1;
    adj[1][0] = adj[0][1] = 1;
    adj[2][0] = adj[0][2] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[2][4] = adj[4][2] = 1;
    // call BFS
    bfs(adj, V);
    return 0;
}
