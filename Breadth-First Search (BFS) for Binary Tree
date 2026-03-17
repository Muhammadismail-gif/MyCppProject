#include <iostream>
#include <queue>
using namespace std;
// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to perform level-order traversal
void levelOrder(Node* root) {
    if (root == nullptr) return;
queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();  // Number of nodes 		         at current level
  // Print all nodes of current level
        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->data << " ";

            if (node->left) 
		q.push(node->left);
            if (node->right) 
		q.push(node->right);
        }
        cout << endl; // Move to next level
    }
}

int main() {
    // Construct the tree
    Node* root = new Node(5);
    root->left = new Node(12);
    root->right = new Node(13);
    root->left->left = new Node(7);
    root->left->right = new Node(14);
    root->right->right = new Node(2);
    root->left->left->left = new Node(17);
    root->left->left->right = new Node(23);
    root->left->right->left = new Node(27);
    root->left->right->right = new Node(3);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(11);
    // Print level-order traversal
    cout << "Level-order Traversal:" << endl;
    levelOrder(root);

    return 0;
}
