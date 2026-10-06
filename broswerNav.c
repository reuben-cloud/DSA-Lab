#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[50];
    struct Node *prev, *next;
};

struct Node *current = NULL;

void visit(char *url) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->next = NULL;
    newNode->prev = current;

    if (current != NULL) {
        current->next = newNode;
    }
    current = newNode;
    printf("Visited: %s\n", current->url);
}

void back() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Current Page: %s\n", current->url);
    } else {
        printf("No backward history.\n");
    }
}

void forward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Current Page: %s\n", current->url);
    } else {
        printf("No forward history.\n");
    }
}

int main() {
    int choice;
    char url[50];

    while (1) {
        printf("\n--- Browser Navigation ---\n");
        printf("1. Visit New Page\n2. Back\n3. Forward\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visit(url);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
