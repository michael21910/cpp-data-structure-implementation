#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
    Node(int data);
    ~Node();
    int getData();
    Node* getLeft();
    Node* getRight();
    void setData(int data);
    void setLeft(Node* left);
    void setRight(Node* right);
private:
    int data;
    Node* left;
    Node* right;
};

Node::Node(int data) {
    this -> data = data;
    this -> left = nullptr;
    this -> right = nullptr;
}

Node::~Node() {
    delete this -> left;
    delete this -> right;
}

int Node::getData() {
    return this -> data;
}

Node* Node::getLeft() {
    return this -> left;
}

Node* Node::getRight() {
    return this -> right;
}

void Node::setData(int data) {
    this -> data = data;
}

void Node::setLeft(Node* left) {
    this -> left = left;
}

void Node::setRight(Node* right) {
    this -> right = right;
}

#endif