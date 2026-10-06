#include <stdio.h>

void read_matrix(int a[10][10], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

int convert(int a[10][10], int s[20][3], int r, int c) {
    int k = 1;
    s[0][0] = r; s[0][1] = c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                s[k][0] = i; s[k][1] = j; s[k][2] = a[i][j];
                k++;
            }
        }
    }
    s[0][2] = k - 1;
    return k;
}

void display(int s[][3]) {
    printf("\nRow Col Value\n");
    for (int i = 0; i <= s[0][2]; i++)
        printf("%d   %d   %d\n", s[i][0], s[i][1], s[i][2]);
}

int add(int s1[][3], int s2[][3], int s3[][3]) {
    if (s1[0][0] != s2[0][0] || s1[0][1] != s2[0][1]) {
        printf("\nMatrices cannot be added (Dimension mismatch)!\n");
        return 0;
    }

    int i = 1, j = 1, k = 1;
    s3[0][0] = s1[0][0]; s3[0][1] = s1[0][1];

    while (i <= s1[0][2] || j <= s2[0][2]) {
        int r1 = (i <= s1[0][2]) ? s1[i][0] : 999;
        int c1 = (i <= s1[0][2]) ? s1[i][1] : 999;
        int r2 = (j <= s2[0][2]) ? s2[j][0] : 999;
        int c2 = (j <= s2[j][1]) ? s2[j][1] : 999; // fixed row check logic

        if (r1 == r2 && c1 == c2) {
            int sum = s1[i][2] + s2[j][2];
            if (sum != 0) {
                s3[k][0] = r1; s3[k][1] = c1; s3[k][2] = sum; k++;
            }
            i++; j++;
        } else if (r1 < r2 || (r1 == r2 && c1 < c2)) {
            s3[k][0] = r1; s3[k][1] = c1; s3[k][2] = s1[i][2]; k++; i++;
        } else {
            s3[k][0] = s2[j][0]; s3[k][1] = s2[j][1]; s3[k][2] = s2[j][2]; k++; j++;
        }
    }
    s3[0][2] = k - 1;
    return k;
}

int transpose(int s[][3], int t[][3]) {
    t[0][0] = s[0][1]; t[0][1] = s[0][0]; t[0][2] = s[0][2];
    int k = 1;
    for (int col = 0; col < s[0][1]; col++) {
        for (int i = 1; i <= s[0][2]; i++) {
            if (s[i][1] == col) {
                t[k][0] = s[i][1]; t[k][1] = s[i][0]; t[k][2] = s[i][2]; k++;
            }
        }
    }
    return k;
}

int main() {
    int a[10][10], b[10][10], s1[20][3], s2[20][3], s3[40][3], t_sum[40][3];
    int r = 0, c = 0, ch, added = 0;
    char ans;

    do {
        printf("\n1. Read Matrices\n2. Convert & Display\n3. Add Sparse Matrices\n4. Transpose Added Matrix\n5. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter rows and columns: ");
                scanf("%d%d", &r, &c);
                printf("Enter Matrix 1:\n"); read_matrix(a, r, c);
                printf("Enter Matrix 2:\n"); read_matrix(b, r, c);
                added = 0;
                break;
            case 2:
                convert(a, s1, r, c); convert(b, s2, r, c);
                printf("\nEfficient Representation of Matrix 1:"); display(s1);
                printf("\nEfficient Representation of Matrix 2:"); display(s2);
                break;
            case 3:
                if (add(s1, s2, s3) > 0) {
                    printf("\nAddition Result:"); display(s3);
                    added = 1;
                }
                break;
            case 4:
                if (!added) printf("Add Sparse Matrices first!\n");
                else {
                    transpose(s3, t_sum);
                    printf("\nTranspose of Added Matrix:"); display(t_sum);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Choice!");
        }
        printf("\nDo you want to continue (Y/N): ");
        scanf(" %c", &ans);
    } while (ans == 'Y' || ans == 'y');

    return 0;
}
