#include <iostream>
#include <ctime>
#include "bst.hpp"
using namespace std;

int main()
{
    cout << "Testing the Binary Search Tree" << endl;
    BST *bst = new BST();
    srand(time(NULL));
    
    int arr[10] = {0};
    int counter = 0;

    cout << "insert order: ";
    while (counter < 10) {
        TreeNode *n = new TreeNode(rand() % 10 + 1);
        if (arr[ n -> data - 1 ] == 0) {
            arr[ n -> data - 1 ] = 1;
            bst -> insert(n);
        }
        else {
            continue;
        }
        counter++;
        cout << n -> data << " ";
    }
    cout << endl;

    cout << "preorder: ";
    bst -> preorder();
    cout << endl;
    cout << "inorder: ";
    bst -> inorder();
    cout << endl;
    cout << "postorder: ";
    bst -> postorder();
    cout << endl;
    for(int i = 0; i <= 10; i++) {
        cout << bst -> search(i) << " ";
    }
    cout << endl;
    return 0;
}