#include <iostream>
using namespace std;

class CircularQueue//CIRCULAR QUEUE
{
    int *arr;
    int size;
    int front, rear;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        // Queue is full
        if ((rear + 1) % size == front) {
            cout << "Queue is Full\n";
            return;
        }

        // First element
        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void dequeue() {
        // Queue is empty
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        // Last element
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}