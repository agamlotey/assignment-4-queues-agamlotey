#include <iostream>
using namespace std;

#define MAX 50

int q1[MAX], q2[MAX];
int f1=0, r1=-1, f2=0, r2=-1;

void pushTwoQ(int val) { q1[++r1] = val; }

void popTwoQ(){
    if (f1 > r1) { cout << "Stack empty\n"; return; }
    while (f1 < r1) q2[++r2] = q1[f1++];
    cout << "Popped (Two Queues): " << q1[f1++] << endl;
    for (int i = f2; i <= r2; i++) q1[i-f2] = q2[i];
    r1 = r2 - f2; f1 = f2 = 0; r2 = -1;
}

int q[MAX]; int f=0, r=-1;

void pushOneQ(int val) {
    q[++r] = val;
    int n = r - f + 1;
    for (int i = 0; i < n-1; i++) {
        q[++r] = q[f++];
    }
}

void popOneQ() {
    if (f > r){ cout << "Stack empty\n"; return; }
    cout << "Popped (One Queue): " << q[f++] << endl;
}

int main() {
    int choice, sub, val;
    while (1) {
        cout << "\n--- Stack using Queues ---\n";
        cout << "1. Two Queues\n2. One Queue\n3. Exit\n";
        cin >> choice;

        if (choice == 1) {
            while (1) {
                cout << "(Two Queues) 1.Push 2.Pop 3.Back\n";
                cin >> sub;
                if (sub == 1) { cout << "Enter value: "; cin >> val; pushTwoQ(val); }
                else if (sub == 2) popTwoQ();
                else if (sub == 3) break;
            }
        }
        else if (choice == 2) {
            while (1) {
                cout << "(One Queue) 1.Push 2.Pop 3.Back\n";
                cin >> sub;
                if (sub == 1) { cout << "Enter value: "; cin >> val; pushOneQ(val); }
                else if (sub == 2) popOneQ();
                else if (sub == 3) break;
            }
        }
        else break;
    }
    return 0;
}
