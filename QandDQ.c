#include <stdio.h>
#define MAX 5


int q[MAX], front = -1, rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    if (front == -1) front = 0;
    q[++rear] = val;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Removed: %d\n", q[front++]);
    if (front > rear) front = rear = -1; // Reset
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) printf("%d ", q[i]);
    printf("\n");
}

void handleQueue() {
    int choice;
    do {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back to Main\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: displayQueue(); break;
        }
    } while (choice != 4);
}


int dq[MAX], dFront = -1, dRear = -1;

void pushFront() {
    if (dFront == 0) {
        printf("Cannot insert at front (No space ahead)!\n");
        return;
    }
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    if (dFront == -1) { dFront = dRear = 0; }
    else { dFront--; }
    dq[dFront] = val;
}

void pushBack() {
    if (dRear == MAX - 1) {
        printf("Deque Overflow at back!\n");
        return;
    }
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    if (dFront == -1) dFront = 0;
    dq[++dRear] = val;
}

void popFront() {
    if (dFront == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Removed from Front: %d\n", dq[dFront]);
    if (dFront == dRear) dFront = dRear = -1;
    else dFront++;
}

void popBack() {
    if (dRear == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Removed from Back: %d\n", dq[dRear]);
    if (dFront == dRear) dFront = dRear = -1;
    else dRear--;
}

void displayDeque() {
    if (dFront == -1) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = dFront; i <= dRear; i++) printf("%d ", dq[i]);
    printf("\n");
}

void handleDeque() {
    int choice;
    do {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n5. Display\n6. Back to Main\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: pushFront(); break;
            case 2: pushBack(); break;
            case 3: popFront(); break;
            case 4: popBack(); break;
            case 5: displayDeque(); break;
        }
    } while (choice != 6);
}


int main() {
    int choice;
    do {
        printf("\n=== MAIN MENU ===\n");
        printf("1. Standard Queue\n2. Double Ended Queue (Deque)\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: handleQueue(); break;
            case 2: handleDeque(); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
