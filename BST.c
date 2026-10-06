#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild, *rchild;
};

struct node *root = NULL;

struct node* insert(struct node* node, int item) {
    if (node == NULL) {
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = item;
        new_node->lchild = new_node->rchild = NULL;
        return new_node;
    }
    if (item == node->data)
        printf("item already exists\n");
    else if (item < node->data)
        node->lchild = insert(node->lchild, item);
    else
        node->rchild = insert(node->rchild, item);
    return node;
}

void search(int item) {
    struct node *ptr = root, *parent = NULL;
    while (ptr != NULL && ptr->data != item) {
        parent = ptr;
        ptr = (item < ptr->data) ? ptr->lchild : ptr->rchild;
    }
    if (ptr == NULL) {
        printf("Search data not found\n");
    } else if (parent == NULL) {
        printf("%d is the root node.\n", item);
    } else if (parent->lchild == ptr) {
        printf("%d is found as lchild of %d\n", item, parent->data);
    } else {
        printf("%d is found as rchild of %d\n", item, parent->data);
    }
}

struct node* delnode(struct node* node, int item) {
    if (node == NULL) return NULL;

    if (item < node->data) {
        node->lchild = delnode(node->lchild, item);
    } else if (item > node->data) {
        node->rchild = delnode(node->rchild, item);
    } else {
        if (node->lchild == NULL) {
            struct node *temp = node->rchild;
            free(node);
            return temp;
        } else if (node->rchild == NULL) {
            struct node *temp = node->lchild;
            free(node);
            return temp;
        }
        struct node *succ = node->rchild;
        while (succ->lchild != NULL) succ = succ->lchild;
        node->data = succ->data;
        node->rchild = delnode(node->rchild, succ->data);
    }
    return node;
}

void display(struct node *ptr) {
    if (ptr != NULL) {
        display(ptr->lchild);
        printf("%d ", ptr->data);
        display(ptr->rchild);
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            root = insert(root, val);
        } else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &val);
            search(val);
        } else if (choice == 3) {
            printf("Enter value: ");
            scanf("%d", &val);
            if (root == NULL) {
                printf("Tree is empty\n");
            } else {
                struct node *ptr = root;
                while (ptr != NULL && ptr->data != val)
                    ptr = (val < ptr->data) ? ptr->lchild : ptr->rchild;
                if (ptr == NULL) printf("item not found\n");
                else root = delnode(root, val);
            }
        } else if (choice == 4) {
            if (root == NULL) printf("Tree is empty\n");
            else { printf("Tree elements: "); display(root); printf("\n"); }
        } else if (choice == 5) {
            exit(0);
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
