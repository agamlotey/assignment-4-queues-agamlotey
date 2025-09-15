#include <stdio.h>
#define MAX 50

int queue[MAX];
int front = -1, rear = -1;
int isEmpty(){
    return (front == -1);
}
int isFull(){
    return (rear==MAX-1);
}
void enqueue(int val) {
    if(isFull()){
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = val;
}

void dequeue() {
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) front = rear = -1;
    else front++;
}

void display(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void peek() {
    if (isEmpty()) printf("Queue empty!\n");
    else printf("Front element: %d\n", queue[front]);
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
