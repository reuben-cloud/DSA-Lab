#include <stdio.h>
#include <stdlib.h>

int c = 0;

int bin_search(int a[], int low, int high, int item) {
    c++;
    if (low > high) {
        c++;
        return -1;
    }
    
    c++;
    int mid = (low + high) / 2;

    c++;
    if (a[mid] == item) {
        c++;
        return mid;
    }

    c++;
    if (a[mid] > item) {
        c++;
        return bin_search(a, low, mid - 1, item);
    }

    c++;
    if (a[mid] < item) {
        c++;
        return bin_search(a, mid + 1, high, item);
    }

    c++;
    return -1;
}

int main() {
    int a[100], n = 0, item, res, ch;

    while (1) {
        printf("\n1. Enter Array\n2. Binary Search\n3. Display Complexities\n4. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of elements (n): ");
                scanf("%d", &n);
                printf("Enter %d sorted elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                break;

            case 2:
                if (n == 0) {
                    printf("Please enter array first!\n");
                    break;
                }
                printf("Enter item to search: ");
                scanf("%d", &item);
                
                c = 0;
                res = bin_search(a, 0, n - 1, item);

                if (res != -1)
                    printf("Item found at index: %d\n", res);
                else
                    printf("Item not found.\n");
                break;

            case 3:
                if (n == 0) {
                    printf("Please enter array first!\n");
                    break;
                }
                printf("Time complexity count c = %d\n", c);
                printf("Space complexity = %d bytes (%d * %d bytes for array + fixed variables)\n", 
                        (n * 4) + 20, n, 4);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
