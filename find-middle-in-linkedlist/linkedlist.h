
struct Node {
    char data;
    Node* next;
};

Node* makeLinkedList(char* datas);
void printLinkedList(Node* head);
Node* makeNode(char data, Node* next);
Node* findTail(Node* head);
Node* step(Node* it, int stepCount);
