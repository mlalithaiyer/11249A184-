#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) front = 0; 
    queue[++rear] = value;
    printf("%d inserted into the queue.\n", value);
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }
    printf("%d deleted from the queue.\n", queue[front]);
    front++;
    if (front > rear) { 
        front = rear = -1;
    }
}
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("=== Queue Implementation in C ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
