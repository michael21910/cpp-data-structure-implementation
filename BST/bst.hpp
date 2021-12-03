#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() {
        data = 0;
        left = right = NULL;
    }
    TreeNode(int d) {
        data = d;
        left = right = NULL;
    }
};

class BST {
public:
    BST();
    void insert(TreeNode *n);
    bool search(int d);
    void inorder();
    void preorder();
    void postorder();
private:
    TreeNode *root;
    void insert(TreeNode **root, TreeNode *n);
    bool search(TreeNode *root, int d);
    void inorder(TreeNode *root);
    void preorder(TreeNode *root);
    void postorder(TreeNode *root);
};

BST::BST() {
    root = nullptr;
}

void BST::insert(TreeNode *n) {
    insert(&root, n);
}

void BST::insert(TreeNode **root, TreeNode *n) {
    if (*root == nullptr) {
        *root = n;
    }
    else if (n -> data < (*root) -> data) {
        insert(&((*root) -> left), n);
    }
    else {
        insert(&((*root) -> right), n);
    }
}

bool BST::search(int d) {
    return search(root, d);
}

bool BST::search(TreeNode *root, int d) {
    if (root == nullptr) {
        return false;
    }
    else if (d == root -> data) {
        return true;
    }
    else if (d < root -> data) {
        return search(root -> left, d);
    }
    else {
        return search(root -> right, d);
    }
}

void BST::inorder() {
    inorder(root);
}

void BST::inorder(TreeNode *root) {
    if (root != nullptr) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

void BST::preorder() {
    preorder(root);
}

void BST::preorder(TreeNode *root) {
    if (root != nullptr) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void BST::postorder() {
    postorder(root);
}

void BST::postorder(TreeNode *root) {
    if (root != nullptr) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

#endif