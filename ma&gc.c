#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id, mark;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void alloc(int id) {
    struct Node *n = malloc(sizeof(struct Node));
    n->id = id; n->mark = 0; n->prev = NULL; n->next = head;
    if (head) head->prev = n;
    head = n;
}

void gc() {
    struct Node *cur = head, *nxt;
    while (cur) {
        nxt = cur->next;
        if (!cur->mark) {
            if (cur->prev) cur->prev->next = cur->next;
            else head = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            printf("Freed %d\n", cur->id);
            free(cur);
        } else cur->mark = 0;
        cur = nxt;
    }
}

void show() {
    for (struct Node *cur = head; cur; cur = cur->next)
        printf("[%d m=%d] ", cur->id, cur->mark);
    printf("\n");
}

int main() {
    int ch, id;
    struct Node *cur;
    while (1) {
        printf("1.Alloc 2.Mark 3.GC 4.Show 5.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: scanf("%d", &id); alloc(id); break;
            case 2: scanf("%d", &id);
                    for (cur = head; cur; cur = cur->next)
                        if (cur->id == id) cur->mark = 1;
                    break;
            case 3: gc(); break;
            case 4: show(); break;
            case 5: return 0;
        }
    }
}
