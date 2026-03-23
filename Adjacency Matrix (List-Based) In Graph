#include <iostream>
using namespace std;

// Node for linked list
struct Node {
    int data;
    Node* next;
};

// Graph using Adjacency List
class GraphList {
public:
    int nodes;
    Node* head[10];   // Array of linked list heads
    GraphList(int n) {
        nodes = n;
   // Initialize all heads to NULL
        for (int i = 0; i < nodes; i++) {
            head[i] = NULL;
        }    }
    // Add edge u -> v
    void addEdge(int u, int v) {
        // Insert v at start of list for u
        Node* newNode = new Node();
        newNode->data = v;
        newNode->next = head[u];
        head[u] = newNode;
// Insert u at start of list for v (undirected graph)
        Node* newNode2 = new Node();
        newNode2->data = u;
        newNode2->next = head[v];
        head[v] = newNode2;
    }
 void display() {
        cout << "Adjacency List:\n";

        for (int i = 0; i < nodes; i++) {
            cout << i << " -> ";
            Node* temp = head[i];

            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        } } };
int main() {
    GraphList g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    g.display();

    return 0;
}

