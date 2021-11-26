#include "node.hpp"
#include <iostream>
using namespace std;

class LinkedList : public Node {
public:
    LinkedList();
    ~LinkedList();
    void insert(int data, int n);
    void insertFromHead(int data);
    void insertFromTail(int data);
    void remove(int n);
    void removeFromHead();
    void removeFromTail();
    void reverse();
    void print();
    void printReverse();
    int getSize();
    void setSize(int _size);  
protected:
    Node* head;
    Node* tail;
    int size;
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp -> getNext();
        delete temp;
        temp = next;
    }
}

void LinkedList::insert(int data, int n) {
    if (n < 0 || n > size) {
        return;
    }
    if (n == 0) {
        insertFromHead(data);
        return;
    }
    if (n == size) {
        insertFromTail(data);
        return;
    }
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        temp = temp -> getNext();
    }
    Node* newNode = new Node(data);
    newNode -> setNext(temp -> getNext());
    newNode -> setPrev(temp);
    temp -> setNext(newNode);
    temp -> getNext() -> setPrev(newNode);
    setSize(size + 1);
    return;
}

void LinkedList::insertFromHead(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode -> setNext(head);
        head -> setPrev(newNode);
        head = newNode;
    }
    setSize(size + 1);
}

void LinkedList::insertFromTail(int data) {
    Node* newNode = new Node(data);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode -> setPrev(tail);
        tail -> setNext(newNode);
        tail = newNode;
    }
    setSize(size + 1);
}

void LinkedList::remove(int n) {
    if (n < 0 || n >= size) {
        return;
    }
    if (n == 0) {
        removeFromHead();
        return;
    }
    if (n == size - 1) {
        removeFromTail();
        return;
    }
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        temp = temp -> getNext();
    }
    temp -> getPrev() -> setNext(temp -> getNext());
    temp -> getNext() -> setPrev(temp -> getPrev());
    delete temp;
    setSize(size - 1);
    return;
}

void LinkedList::removeFromHead() {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head -> getNext();
    head -> setPrev(nullptr);
    delete temp;
    setSize(size - 1);
    return;
}

void LinkedList::removeFromTail() {
    if (tail == nullptr) {
        return;
    }
    Node* temp = tail;
    tail = tail -> getPrev();
    tail -> setNext(nullptr);
    delete temp;
    setSize(size - 1);
    return;
}

void LinkedList::reverse() {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        Node* next = temp -> getNext();
        temp -> setNext(prev);
        temp -> setPrev(next);
        prev = temp;
        temp = next;
    }
    Node* swapHeadTail = head;
    head = tail;
    tail = swapHeadTail;
    return;
}

void LinkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp -> getData() << " ";
        temp = temp -> getNext();
    }
    cout << endl << endl;
    return;
}

void LinkedList::printReverse() {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp -> getData() << " ";
        temp = temp -> getPrev();
    }
    cout << endl << endl;
    return;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::setSize(int _size) {
    this -> size = _size;
}