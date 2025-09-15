#include <stdio.h>
#define MAX 50

int cq[MAX];
int front = -1, rear = -1;

int isEmpty() { return front == -1; }
int isFull() { return (front == (rear + 1) % MAX); }

void enqueue(int val) {
    if (isFull()) {
        printf("Circular Queue is full!\n");
        return;
    }
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % MAX;
    cq[rear] = val;
}

void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", cq[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int choice, val;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
