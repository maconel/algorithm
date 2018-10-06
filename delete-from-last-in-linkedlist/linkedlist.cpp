
#include "linkedlist.h"
#include <stdio.h>

Node* makeNode(char data, Node* next) {
    Node* node = new Node();
    node->data = data;
    node->next = next;
    return node;
}

Node* makeLinkedList(char* datas) {
    Node* tail = makeNode('\0', NULL);
    Node* head = makeNode('\0', tail);

    Node* it = head;
    for (char* p=datas; *p; ++p) {
        Node* node = makeNode('\0', tail);

        it->data = *p;
        it->next = node;

        it = node;
    }

    return head;
}

void printLinkedList(Node* head) {
    for (Node* it = head; it->next != NULL; it = it->next) {
        printf("%c", it->data);
    }
    printf("\n");
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
