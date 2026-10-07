#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int p, int r) {
    int x = A[r]; // last element as pivot[span_0](start_span)[span_0](end_span)
    int i = p - 1;[span_1](start_span)[span_1](end_span)

    for (int j = p; j <= r - 1; j++) {[span_2](start_span)[span_2](end_span)
        if (A[j] <= x) {[span_3](start_span)[span_3](end_span)
            i = i + 1;[span_4](start_span)[span_4](end_span)
            swap(&A[i], &A[j]); // exchange A[i] & A[j][span_5](start_span)[span_5](end_span)
        }
    }
    swap(&A[i + 1], &A[r]); // exchange A[i + 1] & A[r][span_6](start_span)[span_6](end_span)
    return i + 1;[span_7](start_span)[span_7](end_span)
}

void quicksort(int A[], int p, int r) {
    if (p < r) {[span_8](start_span)[span_8](end_span)
        int q = partition(A, p, r);[span_9](start_span)[span_9](end_span)
        quicksort(A, p, q - 1);[span_10](start_span)[span_10](end_span)
        quicksort(A, q + 1, r);[span_11](start_span)[span_11](end_span)
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    quicksort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
