#include <iostream>
using namespace std;

#define MAX 5
int cq[MAX], front = -1, rear = -1;

void insertCQ(int val) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        cout << "Circular Queue Overflow\n"; return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    cq[rear] = val;
}

void deleteCQ() {
    if (front == -1) { cout << "Circular Queue Underflow\n"; return; }
    cout << "Deleted: " << cq[front] << endl;
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void displayCQ() {
    if (front == -1) { cout << "Circular Queue Empty\n"; return; }
    cout << "Circular Queue: ";
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    int ch, val;
    while (1) {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit\n";
        cin >> ch;
        if (ch == 1) { cout << "Enter value: "; cin >> val; insertCQ(val); }
        else if (ch == 2) deleteCQ();
        else if (ch == 3) displayCQ();
        else break;
    }
    return 0;
}
