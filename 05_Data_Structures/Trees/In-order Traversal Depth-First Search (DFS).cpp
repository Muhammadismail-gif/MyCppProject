#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    } };
// Function to print nodes in inorder traversal
void printInorder(Node* node) {
    if (node == nullptr)
        return;
    // Recur on left child
    printInorder(node->left);
    // Print current node's data
    cout << node->data << " ";
 // Recur on right child
    printInorder(node->right);
}

int main() {
    // Construct the tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Print inorder traversal
    cout << "Inorder Traversal: ";
    printInorder(root);
    cout << endl;

    return 0;
