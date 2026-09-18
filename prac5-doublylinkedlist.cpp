#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

// Function to insert a node
void insert() {
    Node *newNode, *temp;
    int value, position, i;

    newNode = (Node *)malloc(sizeof(Node));

    cout << "Enter value: ";
    cin >> value;

    cout << "Enter position: ";
    cin >> position;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Insert at beginning
    if (position == 1) {
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;

        cout << "Node inserted successfully.\n";
        return;
    }

    // Find the node before the required position
    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!\n";
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

// Function to delete a node
void deleteNode() {
    Node *temp;
    int position, i;

    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    cout << "Enter position to delete: ";
    cin >> position;

    temp = head;

    // Delete first node
    if (position == 1) {
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        free(temp);

        cout << "Node deleted successfully.\n";
        return;
    }

    // Find the node to delete
    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    // Connect previous node to next node
    temp->prev->next = temp->next;

    // Connect next node to previous node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    cout << "Node deleted successfully.\n";
}

// Display in forward direction
void displayForward() {
    Node *temp;

    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    temp = head;

    cout << "Forward: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Display in reverse direction
void displayReverse() {
    Node *temp;

    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    temp = head;

    // Move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Reverse: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

// Main function
int main() {
    int choice, n, i, value;

    cout << "Enter the number of elements initially: ";
    cin >> n;

    // Create initial list
    for (i = 1; i <= n; i++) {
        Node *newNode, *temp;

        newNode = (Node *)malloc(sizeof(Node));

        cout << "Enter element " << i << ": ";
        cin >> value;

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Menu
    do {
        cout << "\n===== DOUBLY LINKED LIST =====\n";
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Reverse\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayReverse();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}