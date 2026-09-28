#include <stdio.h>
#include <stdlib.h>

int count = 0;

int bin_search(int a[], int low, int high, int item) {
    count++;
    if (low > high) {
        return -1;
    }
    
    int mid = (low + high) / 2;
    if (a[mid] == item) {
        return mid;
    }
    if (a[mid] > item) {
        return bin_search(a, low, mid - 1, item);
    }
    if (a[mid] < item) {
        return bin_search(a, mid + 1, high, item);
    }
    return -1;
}

int main() {
    int a[100], n, item, res, ch;

    while (1) {
        printf("\n1. Enter Array\n2. Binary Search\n3. Time Complexity\n4. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter %d sorted elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                break;

            case 2:
                printf("Enter item to search: ");
                scanf("%d", &item);
                
                count = 0;
                res = bin_search(a, 0, n - 1, item);

                if (res != -1)
                    printf("Item found at index: %d\n", res);
                else
                    printf("Item not found.\n");

                printf("Frequency Count: %d\n", count);
                break;

            case 3:
                printf("Frequency Count: T(n) = T(n/2) + O(1)\n");
                printf("Best Case: O(1)\n");
                printf("Worst Case: O(log n)\n");
                printf("Space Complexity: O(log n)\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
