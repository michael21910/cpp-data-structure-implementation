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
    int remove(int n);
    int removeFromHead();
    int removeFromTail();
    void reverse();
    void print();
    void printReverse();
    Node* getHead();
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
    setSize(getSize() + 1);
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
    setSize(getSize() + 1);
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
    setSize(getSize() + 1);
}

int LinkedList::remove(int n) {
    if (n < 0 || n >= size) {
        return -1;
    }
    if (n == 0) {
        int returnValue = removeFromHead();
        return returnValue;
    }
    if (n == size - 1) {
        int returnValue = removeFromTail();
        return returnValue;
    }
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        temp = temp -> getNext();
    }
    int returnValue = temp -> getData();
    temp -> getPrev() -> setNext(temp -> getNext());
    temp -> getNext() -> setPrev(temp -> getPrev());
    delete temp;
    setSize(size - 1);
    return returnValue;
}

int LinkedList::removeFromHead() {
    if (head == nullptr) {
        return -1;
    }
    Node* temp = head;
    int returnValue = temp -> getData();
    head = head -> getNext();
    if (head != nullptr) {
        head -> setPrev(nullptr);
    }
    delete temp;
    setSize(size - 1);
    return returnValue;
}

int LinkedList::removeFromTail() {
    if (tail == nullptr) {
        return -1;
    }
    Node* temp = tail;
    int returnValue = temp -> getData();
    tail = tail -> getPrev();
    if (tail != nullptr) {
        tail -> setNext(nullptr);
    }
    delete temp;
    setSize(size - 1);
    return returnValue;
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
    if (getSize() == 0) {
        cout << "Empty!" << endl << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp -> getData() << " ";
        temp = temp -> getNext();
    }
    cout << endl << endl;
    return;
}

void LinkedList::printReverse() {
    if (getSize() == 0) {
        cout << "Empty!" << endl << endl;
        return;
    }
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp -> getData() << " ";
        temp = temp -> getPrev();
    }
    cout << endl << endl;
    return;
}

Node* LinkedList::getHead() {
    return head;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::setSize(int _size) {
    this -> size = _size;
}