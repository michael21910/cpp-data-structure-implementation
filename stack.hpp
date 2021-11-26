#include "linkedlist.hpp"
#include <iostream>
using namespace std;

class Stack : LinkedList {
public:
    Stack();
    ~Stack();
    void push(int _data);
    int pop();
    int top();
    bool isEmpty();
    void print();
    int getSize();
    void setSize(int _size);
private:
    LinkedList *list;
    int size;
};

Stack::Stack() {
    list = new LinkedList();
    size = 0;
}

Stack::~Stack() {
    delete list;
}

void Stack::push(int _data) {
    list -> insertFromHead(_data);
    setSize(getSize() + 1);
}

int Stack::pop() {
    if (isEmpty()) {
        return -1;
    }
    int returnValue = list -> removeFromHead();
    setSize(getSize() - 1);
    return returnValue;
}

int Stack::top() {
    if (isEmpty()) {
        return -1;
    }
    return list -> getHead() -> getData();
}

bool Stack::isEmpty() {
    return getSize() == 0;
}

void Stack::print() {
    list -> print();
}

int Stack::getSize() {
    return size;
}

void Stack::setSize(int _size) {
    this -> size = _size;
}