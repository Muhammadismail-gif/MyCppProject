#include <iostream>
using namespace std;
// Tree Node structure
class Node {
public:
    char data;
    Node* left;
    Node* right;
// Constructor
    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }   };
int main() {
    // Creating nodes
    Node* root = new Node('R');
    Node* nodeA = new Node('A');
    Node* nodeB = new Node('B');
    Node*  nodeC = new Node('C');
    Node* nodeD = new Node('D');
    Node* nodeE = new Node('E');
    Node* nodeF = new Node('F');
    Node* nodeG = new Node('G');

    // Linking the nodes to form the tree
    root->left = nodeA;
    root->right = nodeB;
    nodeA->left = nodeC;
    nodeA->right = nodeD;
    nodeB->left = nodeE;
    nodeB->right = nodeF;
    nodeF->left = nodeG;
    // Test
    cout << "root->right->left->data: " 
         << root->right->left->data << endl;
    return 0;
}
