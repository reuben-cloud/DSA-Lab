#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int coeff;
    int expo;
    struct node *next;
};

struct node* readPoly()
 {
    struct node *head = NULL, *temp = NULL, *p = NULL;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter coeff and expo: ");
        scanf("%d %d", &p->coeff, &p->expo);
        p->next = NULL;

        if (head == NULL) {
            head = p;
            temp = p;
        } else {
            temp->next = p;
            temp = p;
        }
    }
    return head;
}

struct node* addPoly(struct node *P, struct node *Q) 
{
    struct node *R = NULL, *temp = NULL, *p = NULL;

    while (P != NULL && Q != NULL) {
        p = (struct node*)malloc(sizeof(struct node));
        p->next = NULL;

        if (P->expo == Q->expo) {
            p->coeff = P->coeff + Q->coeff;
            p->expo = P->expo;
            P = P->next;
            Q = Q->next;
        } 
        else if (P->expo > Q->expo) {
            p->coeff = P->coeff;
            p->expo = P->expo;
            P = P->next;
        } 
        else {
            p->coeff = Q->coeff;
            p->expo = Q->expo;
            Q = Q->next;
        }

        if (p->coeff != 0) {
            if (R == NULL) {
                R = p;
                temp = p;
            } else {
                temp->next = p;
                temp = p;
            }
        } else {
            free(p);
        }
    }

    while (P != NULL) 
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->coeff = P->coeff;
        p->expo = P->expo;
        p->next = NULL;

        if (R == NULL) {
            R = p;
            temp = p;
        } else {
            temp->next = p;
            temp = p;
        }
        P = P->next;
    }

    while (Q != NULL) 
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->coeff = Q->coeff;
        p->expo = Q->expo;
        p->next = NULL;

        if (R == NULL) {
            R = p;
            temp = p;
        } else {
            temp->next = p;
            temp = p;
        }
        Q = Q->next;
    }

    return R;
}

void display(struct node *head) 
{
    struct node *temp = head;
    if (temp == NULL) {
        printf("0\n");
        return;
    }
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main()
 {
    struct node *P = NULL, *Q = NULL, *R = NULL;

    printf("Polynomial 1:\n");
    P = readPoly();

    printf("\nPolynomial 2:\n");
    Q = readPoly();

    printf("\nP = ");
    display(P);
    printf("Q = ");
    display(Q);

    R = addPoly(P, Q);

    printf("\nResult R = ");
    display(R);

    return 0;
}
