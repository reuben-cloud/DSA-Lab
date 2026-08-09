#include <stdio.h>

struct poly {
    int coeff;
    int expo;
};

void read(struct poly p[], int n) {
    int i;
    printf("Enter coeff and expo:\n");
    for(i = 0; i < n; i++)
        scanf("%d%d", &p[i].coeff, &p[i].expo);
}

int add(struct poly x1[], struct poly x2[], struct poly x3[], int t1, int t2) {
    int i = 0, j = 0, k = 0;
    while(i < t1 && j < t2) {
        if(x1[i].expo == x2[j].expo) {
            x3[k].coeff = x1[i].coeff + x2[j].coeff;
            x3[k].expo = x1[i].expo;
            i++; j++; k++;
        }
        else if(x1[i].expo > x2[j].expo) {
            x3[k].coeff = x1[i].coeff;
            x3[k].expo = x1[i].expo;
            i++; k++;
        }
        else {
            x3[k].coeff = x2[j].coeff;
            x3[k].expo = x2[j].expo;
            j++; k++;
        }
    }
    while(i < t1) { x3[k].coeff = x1[i].coeff; x3[k].expo = x1[i].expo; i++; k++; }
    while(j < t2) { x3[k].coeff = x2[j].coeff; x3[k].expo = x2[j].expo; j++; k++; }
    return k;
}

void display(struct poly p[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%dx^%d", p[i].coeff, p[i].expo);
        if(i < n - 1) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct poly x1[10], x2[10], x3[20];
    int t1, t2, t3, ch;
    char ans;

    do {
        printf("\n1.Read & Add\n2.Exit\nChoice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter terms for Poly 1: "); scanf("%d", &t1); read(x1, t1);
                printf("Enter terms for Poly 2: "); scanf("%d", &t2); read(x2, t2);
                
                t3 = add(x1, x2, x3, t1, t2);
                
                printf("Result: ");
                display(x3, t3);
                break;
            case 2:
                return 0;
            default:
                printf("Invalid Choice!");
        }

        printf("\nContinue (Y/N): ");
        scanf(" %c", &ans);
    } while(ans == 'Y' || ans == 'y');

    return 0;
}
