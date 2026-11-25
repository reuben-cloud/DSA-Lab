#include <stdio.h>
#include <string.h>

int main() {
    char text[200], find[50], rep[50], res[300];
    int choice;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    while (1) {
        printf("\n1. Find\n2. Replace\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Find: ");
                scanf(" %49[^\n]", find);
                if (strstr(text, find))
                    printf("Found!\n");
                else
                    printf("Not found.\n");
                break;

            case 2:
                printf("Find: ");
                scanf(" %49[^\n]", find);
                printf("Replace with: ");
                scanf(" %49[^\n]", rep);

                char *pos = strstr(text, find);
                if (pos) {
                    int len = pos - text;
                    strncpy(res, text, len);
                    res[len] = '\0';
                    strcat(res, rep);
                    strcat(res, pos + strlen(find));
                    strcpy(text, res);
                    printf("Updated Text: %s\n", text);
                } else {
                    printf("Not found.\n");
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
