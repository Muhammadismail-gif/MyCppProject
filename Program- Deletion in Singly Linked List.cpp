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

/* Delete at Beginning */
void deleteBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

/* Delete at End */
void deleteEnd() {
    if (!head || !head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

/* Delete at Specific Position */
void deleteAtPosition(int pos) {
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
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

    deleteBeginning();
    deleteEnd();
    deleteAtPosition(1);

    cout << "Linked List after deletions: ";
    display();

    return 0;
}
