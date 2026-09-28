#include <stdio.h>

int main() {
    int n, target, choice;
    int arr[100];
    int size = 0;

    while (1) {
        printf("\n1. Enter Array\n2. Search & Count Operations\n3. Show Complexity Analysis\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                size = n;

                printf("Enter %d sorted elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2: {
                if (size == 0) {
                    printf("Please enter the array first!\n");
                    break;
                }

                printf("Enter element to search: ");
                scanf("%d", &target);

                int low = 0, high = size - 1;
                int found = -1;
                int count = 0;  // Frequency counter for iterations

                while (low <= high) {
                    count++;  // Counting loop execution frequency
                    int mid = low + (high - low) / 2;

                    if (arr[mid] == target) {
                        found = mid;
                        break;
                    }
                    if (arr[mid] < target)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }

                if (found != -1)
                    printf("Element found at index: %d\n", found);
                else
                    printf("Element not found.\n");

                printf("Frequency Count (Loop iterations): %d\n", count);
                break;
            }

            case 3:
                printf("\n--- TIME COMPLEXITY VIA FREQUENCY COUNT ---\n");
                printf("Frequency Equation: f(n) = log2(n)\n");
                printf("Worst Case Frequency: ceil(log2(%d)) + 1\n", size > 0 ? size : 1);
                printf("Time Complexity Class: O(log n)\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
