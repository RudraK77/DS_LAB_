#include <iostream>//SINGLY LINKED LIST
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Insert at beginning
void insertAtHead(Node* &head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtTail(Node* &head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete first node
void deleteHead(Node* &head) {
    if (head == NULL)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Display linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    insertAtTail(head, 40);
    insertAtTail(head, 50);

    display(head);

    deleteHead(head);

    display(head);

    return 0;
}