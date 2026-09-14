#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild, *rchild;
};

struct node *root = NULL;

void insert(int item) {
    struct node *ptr, *parent = NULL, *new;
    int flag = 0;

    if (root == NULL) {
        new = (struct node*)malloc(sizeof(struct node));
        new->data = item;
        new->lchild = NULL;
        new->rchild = NULL;
        root = new;
        return;
    }

    ptr = root;
    while (ptr != NULL && flag == 0) {
        if (ptr->data == item) {
            flag = 1;
            printf("item already exists\n");
            return;
        } else if (ptr->data < item) {
            parent = ptr;
            ptr = ptr->rchild;
        } else {
            parent = ptr;
            ptr = ptr->lchild;
        }
    }

    if (ptr == NULL) {
        new = (struct node*)malloc(sizeof(struct node));
        new->data = item;
        new->lchild = NULL;
        new->rchild = NULL;

        if (parent->data < item)
            parent->rchild = new;
        else
            parent->lchild = new;
    }
}

void search(int item) {
    struct node *ptr = root;
    int flag = 0;

    while (ptr != NULL && flag == 0) {
        if (ptr->data == item)
            flag = 1;
        else if (ptr->data < item)
            ptr = ptr->rchild;
        else
            ptr = ptr->lchild;
    }

    if (flag == 1)
        printf("Search data found\n");
    else
        printf("Search data not found\n");
}

void delnode(int item) {
    struct node *ptr, *parent = NULL, *succ, *succParent;
    int flag = 0;

    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    ptr = root;
    while (ptr != NULL && flag == 0) {
        if (ptr->data == item) {
            flag = 1;
        } else if (ptr->data > item) {
            parent = ptr;
            ptr = ptr->lchild;
        } else {
            parent = ptr;
            ptr = ptr->rchild;
        }
    }

    if (flag == 0) {
        printf("item not found\n");
        return;
    }

    if (ptr->lchild == NULL && ptr->rchild == NULL) {
        if (parent == NULL)
            root = NULL;
        else if (parent->lchild == ptr)
            parent->lchild = NULL;
        else
            parent->rchild = NULL;
        free(ptr);
    }
    else if (ptr->lchild != NULL && ptr->rchild != NULL) {
        succParent = ptr;
        succ = ptr->rchild;
        while (succ->lchild != NULL) {
            succParent = succ;
            succ = succ->lchild;
        }
        ptr->data = succ->data;
        if (succParent->lchild == succ)
            succParent->lchild = succ->rchild;
        else
            succParent->rchild = succ->rchild;
        free(succ);
    }
    else {
        struct node *child;
        if (ptr->lchild != NULL)
            child = ptr->lchild;
        else
            child = ptr->rchild;

        if (parent == NULL)
            root = child;
        else if (parent->lchild == ptr)
            parent->lchild = child;
        else
            parent->rchild = child;
        free(ptr);
    }
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                search(val);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                delnode(val);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

