
#include "linkedlist.h"
#include <stdio.h>

Node* reverse(Node* head);

int main(int argc, char* argv[]) {
    Node* head = makeLinkedList("hello world.");
    printLinkedList(head);
    head = reverse(head);
    printLinkedList(head);
    return 0;
}

Node* reverse(Node* head) {
    Node* tail = head;

    Node* prev = NULL;
    Node* it = head;
    while (it->next != NULL) {
        Node* cur = it;
        it = it->next;
        cur->next = prev;
        prev = cur;
    }

    head = prev;
    tail->next = it;

    return head;
}
