
#include "linkedlist.h"
#include <stdio.h>

void makeCircle(Node* head);
Node* findTail(Node* head);
Node* step(Node* it, int stepCount);
bool hasCircle(Node* head);

int main(int argc, char* argv[]) {
    Node* head = makeLinkedList("0123456789");
    printLinkedList(head);
    printf("%shas circle\n", hasCircle(head) ? "" : "not ");
    makeCircle(head->next->next);
    printf("%shas circle\n", hasCircle(head) ? "" : "not ");
    return 0;
}

void makeCircle(Node* tailPointTo) {
    Node* tail = findTail(tailPointTo);
    tail->next = tailPointTo;
}

Node* findTail(Node* head) {
    Node* tail = head;
    for (; tail->next != NULL; tail = tail->next) {
    }
    return tail;
}

Node* step(Node* it, int stepCount) {
    for (int i=0; i<stepCount; ++i) {
        it = it->next;
        if (it->next == NULL)
            break;
    }
    return it;
}

bool hasCircle(Node* head) {
    Node* normalIt = head;
    Node* fast2xIt = head;

    for (; fast2xIt->next != NULL; ) {
        normalIt = step(normalIt, 1);
        fast2xIt = step(fast2xIt, 2);
        if (normalIt == fast2xIt)
            return true;
    }
    return false;
}
