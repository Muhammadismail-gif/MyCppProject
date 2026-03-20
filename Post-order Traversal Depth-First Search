#include <iostream>
using namespace std;
// A binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
// Function to print nodes in postorder traversal (left-right-root)
void printPostorder(Node* node) {
    if (node == nullptr)
        return;
    // Recur on left subtree
    printPostorder(node->left);
 // Recur on right subtree
    printPostorder(node->right);
    // Print current node's data
    cout << node->data << " ";
}
int main() {
    // Construct the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    // Print postorder traversal
    cout << "Postorder Traversal: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
