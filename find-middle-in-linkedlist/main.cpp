
#include "linkedlist.h"
#include <stdio.h>

Node* findMiddle(Node* head);

int main(int argc, char* argv[]) {
    Node* head = makeLinkedList("0123456789");
    Node* middle = findMiddle(head);
    printf("middle of 0123456789 is %c\n", middle->data);

    head = makeLinkedList("0123456789a");
    middle = findMiddle(head);
    printf("middle of 0123456789a is %c\n", middle->data);

    return 0;
}

Node* findMiddle(Node* head) {
    Node* normalIt = head;
    Node* fast2xIt = head;

    for (;;) {
        fast2xIt = step(fast2xIt, 2);
        if (fast2xIt->next == NULL)
            break;
        normalIt = step(normalIt, 1);
    }

    return normalIt;
}
