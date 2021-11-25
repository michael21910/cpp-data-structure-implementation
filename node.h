class Node {
public:
    Node();
    Node(int _data);
    ~Node();
    int getData();
    void setData(int _data);
    Node* getNext();
    void setNext(Node* _next);
    Node* getPrev();
    void setPrev(Node* _prev);
protected:
    int data;
    Node* next;
    Node *prev;
};

Node::Node() {
    data = 0;
    next = nullptr;
    prev = nullptr;
}

Node::Node(int _data) {
    this -> data = _data;
    next = nullptr;
    prev = nullptr;
}

Node::~Node() {
    next = nullptr;
    prev = nullptr;
}

int Node::getData() {
    return data;
}

void Node::setData(int _data) {
    this -> data = _data;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* _next) {
    this -> next = _next;
}

Node* Node::getPrev() {
    return prev;
}

void Node::setPrev(Node* _prev) {
    this -> prev = _prev;
}