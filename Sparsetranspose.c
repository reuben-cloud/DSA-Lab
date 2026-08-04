#include <stdio.h>

void read(int a[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

int convert(int a[10][10], int s[20][3], int r, int c)
{
    int i, j, k = 1, count = 0;

    s[0][0] = r;
    s[0][1] = c;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] != 0)
            {
                count++;
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }

    s[0][2] = count;
    return k;
}

void display(int s[20][3], int k)
{
    int i;
    printf("\nRow Col Value\n");
    for(i = 0; i < k; i++)
        printf("%d   %d   %d\n", s[i][0], s[i][1], s[i][2]);
}

int add(int s1[20][3], int s2[20][3], int s3[40][3])
{
    if (s1[0][0] != s2[0][0] || s1[0][1] != s2[0][1]) {
        printf("\nMatrices cannot be added (Dimension mismatch)!\n");
        return 0;
    }

    int i = 1, j = 1, k = 1;

    s3[0][0] = s1[0][0];
    s3[0][1] = s1[0][1];

    while (i < s1[0][2] + 1 && j < s2[0][2] + 1)
    {
        if (s1[i][0] == s2[j][0])
        {
            if (s1[i][1] == s2[j][1])
            {
                int sum = s1[i][2] + s2[j][2];
                if (sum != 0)
                {
                    s3[k][0] = s1[i][0];
                    s3[k][1] = s1[i][1];
                    s3[k][2] = sum;
                    k++;
                }
                i++;
                j++;
            }
            else if (s1[i][1] < s2[j][1])
            {
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2];
                k++;
                i++;
            }
            else
            {
                s3[k][0] = s2[j][0];
                s3[k][1] = s2[j][1];
                s3[k][2] = s2[j][2];
                k++;
                j++;
            }
        }
        else if (s1[i][0] < s2[j][0])
        {
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2];
            k++;
            i++;
        }
        else
        {
            s3[k][0] = s2[j][0];
            s3[k][1] = s2[j][1];
            s3[k][2] = s2[j][2];
            k++;
            j++;
        }
    }

    while (i < s1[0][2] + 1)
    {
        s3[k][0] = s1[i][0];
        s3[k][1] = s1[i][1];
        s3[k][2] = s1[i][2];
        k++;
        i++;
    }

    while (j < s2[0][2] + 1)
    {
        s3[k][0] = s2[j][0];
        s3[k][1] = s2[j][1];
        s3[k][2] = s2[j][2];
        k++;
        j++;
    }

    s3[0][2] = k - 1; 
    return k;
}

int transpose(int s[40][3], int t[40][3])
{
    int total_terms = s[0][2];

    t[0][0] = s[0][1];
    t[0][1] = s[0][0];
    t[0][2] = total_terms;

    if (total_terms == 0) return 1;

    int k = 1;
    for (int col = 0; col < s[0][1]; col++)
    {
        for (int i = 1; i <= total_terms; i++)
        {
            if (s[i][1] == col)
            {
                t[k][0] = s[i][1];
                t[k][1] = s[i][0];
                t[k][2] = s[i][2];
                k++;
            }
        }
    }
    return k;
}

int main()
{
    int a[10][10], b[10][10];
    int s1[20][3], s2[20][3], s3[40][3], t_sum[40][3];
    int r = 0, c = 0, k1 = 0, k2 = 0, k3 = 0, kt = 0, ch;
    char ans;

    do
    {
        printf("\n1. Read Matrices");
        printf("\n2. Convert & Display");
        printf("\n3. Add Sparse Matrices");
        printf("\n4. Transpose Added Matrix");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter rows and columns: ");
                scanf("%d%d", &r, &c);

                printf("Enter Matrix 1:\n");
                read(a, r, c);

                printf("Enter Matrix 2:\n");
                read(b, r, c);
                break;

            case 2:
                k1 = convert(a, s1, r, c);
                k2 = convert(b, s2, r, c);

                printf("\nEfficient Representation of Matrix 1:");
                display(s1, k1);

                printf("\nEfficient Representation of Matrix 2:");
                display(s2, k2);
                break;

            case 3:
                k3 = add(s1, s2, s3);
                if (k3 > 0) {
                    printf("\nAddition Result:");
                    display(s3, k3);
                }
                break;

            case 4:
                if (k3 <= 0) {
                    printf("\nPlease run Option 3 (Add Sparse Matrices) first!\n");
                } else {
                    kt = transpose(s3, t_sum);
                    printf("\nTranspose of Added Matrix:");
                    display(t_sum, kt);
                }
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice!");
        }

        printf("\nDo you want to continue (Y/N): ");
        scanf(" %c", &ans);

    } while(ans == 'Y' || ans == 'y');

    return 0;
}
