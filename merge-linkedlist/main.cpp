
#include "linkedlist.h"
#include <stdio.h>

Node* merge(Node* a, Node* b);
Node* min(Node** a, Node** b);

int main(int argc, char* argv[]) {
    Node* a = makeLinkedList("024568");
    Node* b = makeLinkedList("13579");
    printLinkedList(a);
    printLinkedList(b);

    Node* x = merge(a, b);
    printLinkedList(x);

    return 0;
}

Node* merge(Node* a, Node* b) {
    Node* x = makeNode('\0', a);
    Node* m = x;
    for (;m->next != NULL;) {
        m->next = min(&a, &b);
        m = m->next;
    }
    m = x;
    x = x->next;
    delete m;
    return x;
}

Node* min(Node** a, Node** b) {
    Node* m = NULL;
    if ((*a)->data < (*b)->data) {
        m = *a;
        *a = (*a)->next;
    } else if ((*a)->data > (*b)->data) {
        m = *b;
        *b = (*b)->next;
    } else {
        m = *a;
        *a = (*a)->next;
        *b = (*b)->next;
    }
    return m;
}
