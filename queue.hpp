#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "linkedlist.hpp"

class Queue : public LinkedList {
public:
    Queue();
    ~Queue();
    void enqueue(int _data);
    int dequeue();
    int front();
    bool isEmpty();
    void print();
    int getSize();
    void setSize(int _size);
private:
    LinkedList *list;
    int size;
};

Queue::Queue() {
    list = new LinkedList();
    size = 0;
}

Queue::~Queue() {
    delete list;
}

void Queue::enqueue(int _data) {
    list -> insertFromTail(_data);
    setSize(getSize() + 1);
    return;
}

int Queue::dequeue() {
    if (isEmpty()) {
        return -1;
    }
    int returnValue = list -> removeFromHead();
    setSize(getSize() - 1);
    return returnValue;
}

int Queue::front() {
    if (isEmpty()) {
        return -1;
    }
    return list -> getHead() -> getData();
}

bool Queue::isEmpty() {
    return getSize() == 0;
}

void Queue::print() {
    list -> print();
    return;
}

int Queue::getSize() {
    return list -> getSize();
}

void Queue::setSize(int _size) {
    list -> setSize(_size);
    return;
}

#endif