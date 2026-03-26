#include <iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
};

Node* root = NULL;

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Basic BST insert (RB balancing omitted for brevity in exams unless required)
Node* bstInsert(Node* root, Node* pt) {
    if (!root) return pt;

    if (pt->data < root->data) {
        root->left = bstInsert(root->left, pt);
        root->left->parent = root;
    } else {
        root->right = bstInsert(root->right, pt);
        root->right->parent = root;
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    root = bstInsert(root, createNode(10));
    bstInsert(root, createNode(20));
    bstInsert(root, createNode(30));

    inorder(root);
}