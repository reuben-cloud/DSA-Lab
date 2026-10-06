#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;
    int start = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Hash table is full!\n");
            return;
        }
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Slot %d -> %d\n", i, hashTable[i]);
        else
            printf("Slot %d -> Empty\n", i);
    }
}

int main() {
    int choice, val;
    init();
    while (1) {
        printf("\n--- MENU ---\n1. Insert\n2. Display\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                display();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
