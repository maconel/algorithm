
#include "linkedlist.h"
#include <stdio.h>

void makeCircle(Node* head);
Node* findTail(Node* head);
Node* step(Node* it, int stepCount);
bool hasCircle(Node* head);
Node* findCircle(Node* head);

int main(int argc, char* argv[]) {
    Node* head = makeLinkedList("0123456789");
    printLinkedList(head);

    Node* circleEntry = findCircle(head);
    if (circleEntry == NULL) {
        printf("has not circle\n");
    } else {
        printf("has circle, entry is %c\n", circleEntry->data);
    }

    makeCircle(head->next->next);

    circleEntry = findCircle(head);
    if (circleEntry == NULL) {
        printf("has not circle\n");
    } else {
        printf("has circle, entry is %c\n", circleEntry->data);
    }

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

/*
0-1-2-3-4-5-6-7-8-9-t-2
s: 相交时，slow走的步数
L: 链表长度
a: head到入口点长度
x: 入口点到相交处长度

当fast和slow相遇时，slow还没有走完链表，假设fast已经在环内循环了n(1<= n)圈。假设slow走了s步，则fast走了2s步，又由于
fast走过的步数 = s + n*r（s + 在环上多走的n圈），则有下面的等式：

2*s = s + n  * r ; (1)
 => s = n*r (2)
如果假设整个链表的长度是L，入口和相遇点的距离是x（如上图所示），起点到入口点的距离是a(如上图所示)，则有：
a + x = s = n * r; (3)  由（2）推出
a + x = (n - 1) * r + r  = (n - 1) * r + (L - a) (4) 由环的长度 = 链表总长度 - 起点到入口点的距离求出
a = (n - 1) * r + (L -a -x) (5)

集合式子（5）以及上图我们可以看出，从链表起点head开始到入口点的距离a,与从slow和fast的相遇点（如图）到入口点的距离相等。
因此我们就可以分别用一个指针（ptr1, prt2），同时从head与slow和fast的相遇点出发，每一次操作走一步，直到ptr1 == ptr2，此时的位置也就是入口点！
*/
Node* findCircle(Node* head) {
    Node* normalIt = head;
    Node* fast2xIt = head;

    for (; fast2xIt->next != NULL; ) {
        normalIt = step(normalIt, 1);
        fast2xIt = step(fast2xIt, 2);
        if (normalIt == fast2xIt)
            break;
    }

    if (fast2xIt->next == NULL) {
        return NULL;
    }

    Node* circleEntry = head;
    for (; circleEntry != normalIt; ) {
        normalIt = step(normalIt, 1);
        circleEntry = step(circleEntry, 1);
    }
    return circleEntry;
}
