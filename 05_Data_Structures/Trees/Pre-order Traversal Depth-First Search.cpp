#include <iostream>
using namespace std;
// A node with data, pointer to left child, and a pointer to right child
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    } };
// print its nodes in preorder
void printPreorder(Node* node) {
    if (node == nullptr)
        return;
// First print data of node
    cout << node->data << " ";
// Then recur on left subtree
    printPreorder(node->left);
    // Now recur on right subtree
    printPreorder(node->right);
}
int main() 
{
    // Creating the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    // Print preorder traversal
    cout << "Preorder traversal: ";
    printPreorder(root);
    cout << endl;
    return 0;
}
