#include <stdio.h>

int main() {
    int n, k, i, j, temp, sum, choice;
    int a[100];

    while (1) {
        printf("\n1. Enter Events & Calculate Max Points\n2. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sum = 0;
                printf("Enter n and k: ");
                scanf("%d %d", &n, &k);

                printf("Enter points:\n");
                for (i = 0; i < n; i++)
                    scanf("%d", &a[i]);

                for (i = 0; i < n - 1; i++) {
                    for (j = i + 1; j < n; j++) {
                        if (a[j] > a[i]) {
                            temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        }
                    }
                }

                for (i = 0; i < n && i < k; i++) {
                    if (a[i] > 0)
                        sum += a[i];
                }

                printf("Max points: %d\n", sum);
                break;

            case 2:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
