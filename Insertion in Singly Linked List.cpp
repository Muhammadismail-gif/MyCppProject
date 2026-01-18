#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

/* Insert at Beginning */
void insertBeginning(int value) {
    Node* n = new Node{value, head};
    head = n;
}

/* Insert at End */
void insertEnd(int value) {
    Node* n = new Node{value, NULL};
    if (head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

/* Insert at Specific Position */
void insertAtPosition(int value, int pos) {
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    Node* n = new Node{value, temp->next};
    temp->next = n;
}

/* Display List */
void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertBeginning(20);
    insertBeginning(10);
    insertEnd(40);
    insertAtPosition(30, 2);

    cout << "Linked List: ";
    display();

    return 0;
}
