#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

/* Insert for setup */
void insertEnd(int value) {
    Node* n = new Node{value, NULL};
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
}

/* Reverse Linked List */
void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

/* Display */
void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    cout << "Before Reverse: ";
    display();

    reverseList();

    cout << "After Reverse: ";
    display();

    return 0;
}
