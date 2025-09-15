#include <iostream>
using namespace std;

#define MAX 50
int q[MAX], front = -1, rear = -1;

void insertQ(int val){
    if (rear == MAX - 1) { cout << "Queue Overflow\n"; return; }
    if (front == -1) front = 0;
    q[++rear] = val;
}

void deleteQ() {
    if (front == -1 || front > rear) { cout << "Queue Underflow\n"; return; }
    cout << "Deleted: " << q[front++] << endl;
}

void displayQ() {
    if (front == -1 || front > rear) { cout << "Queue Empty\n"; return; }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) cout << q[i] << " ";
    cout << endl;
}

int main() {
    int ch, val;
    while (1) {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit\n";
        cin >> ch;
        if (ch == 1) { cout << "Enter value: "; cin >> val; insertQ(val); }
        else if (ch == 2) deleteQ();
        else if (ch == 3) displayQ();
        else break;
    }
    return 0;
}
