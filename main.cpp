#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    cout << "/**  Testing the class LinkedList and the class Node **/" << endl;
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
    for(int i = 0; i < 3; i++) {
        list -> removeFromHead();
    }
    for(int i = 0; i < 3; i++) {
        list -> removeFromTail();
    }
    list -> remove(3);
    cout << "list after removing elements from 0 to 2, 8 to 10 and 6 by different functions:" << endl;
    list -> print();
    list -> reverse();
    cout << "list after reversing:" << endl;
    list -> print();
    list -> reverse();
    cout << "list after reversing again:" << endl;
    list -> print();
    cout << "list after calling the print reverse function without actually reverse it:" << endl;
    list -> printReverse();
    cout << "The origrinal linked list:" << endl;
    list -> print();
    cout << "The size of the linked list:" << endl;
    cout << list -> getSize() << endl;
    cout << "/**  Finished testing the class LinkedList and the class Node **/" << endl;
    return 0;
}