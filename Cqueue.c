#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;


void enqueue(int item) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }
    
    if (front == -1) { 
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX; 
    }
    
    queue[rear] = item;
    printf("%d enqueued to queue\n", item);
}


void dequeue() {
    if (front == -1) {
        printf("Queue Underflow (Empty)\n");
        return;
    }
    
    printf("%d dequeued from queue\n", queue[front]);
    
    if (front == rear) { 
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX; 
    }
}


void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, item;
    
    while (1) {
        printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
