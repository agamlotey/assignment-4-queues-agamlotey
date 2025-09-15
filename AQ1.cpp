#include <iostream>
using namespace std;

#define SIZE 5

class SimpleQueue {
    int arr[SIZE];
    int front, rear;

public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << x << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    SimpleQueue q;
    int choice, val;

    do {
        cout << "\nSimple Queue Menu\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is not Empty\n");
                break;
            case 6:
                cout << (q.isFull() ? "Queue is Full\n" : "Queue is not Full\n");
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
