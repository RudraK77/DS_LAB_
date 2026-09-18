#include <iostream>//circular linked list
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

// Insert
void insert() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    Node *newNode = new Node;
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        Node *temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Node inserted successfully.\n";
}

// Delete
void deleteNode() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    int data;
    cout << "Enter data to delete: ";
    cin >> data;

    Node *temp = head;
    Node *prev = NULL;

    // If only one node
    if (head->data == data && head->next == head) {
        delete head;
        head = NULL;
        cout << "Node deleted.\n";
        return;
    }

    // Delete head node
    if (head->data == data) {
        while (temp->next != head) {
            temp = temp->next;
        }

        Node *ptr = head;
        head = head->next;
        temp->next = head;
        delete ptr;

        cout << "Node deleted.\n";
        return;
    }

    // Delete other nodes
    temp = head;

    do {
        prev = temp;
        temp = temp->next;

        if (temp->data == data) {
            prev->next = temp->next;
            delete temp;

            cout << "Node deleted.\n";
            return;
        }

    } while (temp != head);

    cout << "Data not found.\n";
}

// Update
void update() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    int oldData, newData;

    cout << "Enter data to update: ";
    cin >> oldData;

    cout << "Enter new data: ";
    cin >> newData;

    Node *temp = head;

    do {
        if (temp->data == oldData) {
            temp->data = newData;
            cout << "Node updated successfully.\n";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Data not found.\n";
}

// Display
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to Head)\n";
}

int main() {

    int choice;

    do {
        cout << "\n===== CIRCULAR LINKED LIST =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Update\n";
        cout << "4. Display\n";
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
                update();
                break;

            case 4:
                display();
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