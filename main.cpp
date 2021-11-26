#include <iostream>
#include "stack.hpp"
using namespace std;

int main()
{
    cout << endl << "/**  Testing the class LinkedList and the class Node **/" << endl << endl;
    LinkedList *list = new LinkedList();
    for (int i = 4; i >= 0; i--) {
        list -> insertFromHead(i);
    }
    for (int i = 5; i <= 9; i++) {
        list -> insertFromTail(i);
    }
    list -> insert(10, 10);
    cout << "list after inserting elements from 0 to 10 by different functions:" << endl;
    list -> print();
    cout << "start to remove data:" << endl;
    for(int i = 0; i < 3; i++) {
        int removeValue = list -> removeFromHead();
        cout << "data removed: " << removeValue << endl;
    }
    for(int i = 0; i < 3; i++) {
        int removeValue = list -> removeFromTail();
        cout << "data removed: " << removeValue << endl;
    }
    int removeValue = list -> remove(3);
    cout << "data removed: " << removeValue << endl << endl;
    cout << "list after removing elements from 0 to 2, 8 to 10 and 6 by different functions:" << endl;
    list -> print();
    cout << "list after reversing:" << endl;
    list -> reverse();
    list -> print();
    cout << "list after reversing again:" << endl;
    list -> reverse();
    list -> print();
    cout << "list after calling the print reverse function without actually reverse it:" << endl;
    list -> printReverse();
    cout << "the origrinal linked list:" << endl;
    list -> print();
    cout << "the size of the linked list:" << endl;
    cout << list -> getSize() << endl;
    cout << endl << "/**  Finished testing the class LinkedList and the class Node **/" << endl << endl;

    cout << endl << "/** Testing the class Stack **/" << endl << endl;
    Stack *stack = new Stack();
    for (int i = 0; i < 10; i++) {
        stack -> push(i);
    }
    cout << "stack after pushing elements from 0 to 9:" << endl;
    stack -> print();
    cout << "top of the stack: " << stack -> top() << endl << endl;
    cout << "stack after popping elements from 0 to 9:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "data popped: " << stack -> pop() << endl;
    }
    cout << endl << "stack after popping elements from 0 to 9:" << endl;
    stack -> print();
    cout << "top of the stack: " << stack -> top() << endl << endl;;
    cout << "is the stack empty? " << stack -> isEmpty() << endl;
    cout << endl << "/** Finished testing the class Stack **/" << endl << endl;

    return 0;
}