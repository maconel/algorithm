
#include "linkedlist.h"
#include <stdio.h>

void deleteFromLast(Node* head, int n);

int main(int argc, char* argv[]) {
    Node* head = makeLinkedList("0123456789");
    printLinkedList(head);

    deleteFromLast(head, 7);
    printLinkedList(head);

    return 0;
}

void deleteFromLast(Node* head, int n) {
    Node* it = head;
    for (int i = 0; i < n+2 && it->next != NULL; ++i) {
        it = it->next;
    }

    Node* forDelete = head;
    for (; it->next != NULL; it = it->next) {
        forDelete = forDelete->next;
    }

    Node* tmp = forDelete->next;
    forDelete->next = tmp->next;
    delete tmp;
}
