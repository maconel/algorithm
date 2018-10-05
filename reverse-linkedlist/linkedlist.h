
struct Node {
    char data;
    Node* next;
};

Node* makeLinkedList(char* datas);
void printLinkedList(Node* head);
Node* makeNode(char data, Node* next);
