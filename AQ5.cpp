#include <stdio.h>
#define MAX 50
int q1[MAX], q2[MAX];
int f1=0, r1=-1, f2=0, r2=-1;

void enqueue1(int val) { q1[++r1] = val; }
int dequeue1() { return q1[f1++]; }
void enqueue2(int val) { q2[++r2] = val; }
int dequeue2() { return q2[f2++]; }
int isEmpty1() { return f1 > r1; }

void pushTwoQ(int val) { enqueue1(val); }

void popTwoQ() {
    if (isEmpty1()) { printf("Stack empty\n"); return; }
    while (f1 < r1) enqueue2(dequeue1());
    int top = dequeue1();
    printf("Popped (Two Queues): %d\n", top);

    f1 = 0; r1 = r2;
    for (int i = 0; i <= r2; i++) q1[i] = q2[i];
    f2 = 0; r2 = -1;
}

int q[MAX];
int f=0, r=-1;

void enqueue(int val) { q[++r] = val; }
int dequeue() { return q[f++]; }
int size() { return r - f + 1; }
int isEmptyQ() { return f > r; }

void pushOneQ(int val) {
    enqueue(val);
    int n = size();
    for (int i = 0; i < n-1; i++) enqueue(dequeue());
}

void popOneQ() {
    if (isEmptyQ()) { printf("Stack empty\n"); return; }
    printf("Popped (One Queue): %d\n", dequeue());
}
int main() {
    int choice, sub, val;
    while (1) {
        printf("\n--- Stack using Queues ---\n");
        printf("1. Two Queues\n2. One Queue\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while (1) {
                    printf("\n(Two Queues) 1.Push 2.Pop 3.Back\n");
                    scanf("%d", &sub);
                    if (sub == 1) { printf("Enter value: "); scanf("%d", &val); pushTwoQ(val); }
                    else if (sub == 2) popTwoQ();
                    else if (sub == 3) break;
                    else printf("Invalid\n");
                }
                break;

            case 2: 
                while (1) {
                    printf("\n(One Queue) 1.Push 2.Pop 3.Back\n");
                    scanf("%d", &sub);
                    if (sub == 1) { printf("Enter value: "); scanf("%d", &val); pushOneQ(val); }
                    else if (sub == 2) popOneQ();
                    else if (sub == 3) break;
                    else printf("Invalid\n");
                }
                break;

            case 3: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
