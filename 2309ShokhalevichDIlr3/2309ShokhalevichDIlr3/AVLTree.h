#ifndef AVLTreeHeader
#define AVLTreeHeader

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (node == nullptr)
        return 0;
  
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* node) {
    Node* leftChild = node->left;
    Node* subtree = leftChild->right;

    leftChild->right = node;
    node->left = subtree;

    node->height = max(height(node->left), height(node->right)) + 1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;

    return leftChild;
}

Node* leftRotate(Node* node) {
    Node* rightChild = node->right;
    Node* subtree = rightChild->left;

    rightChild->left = node;
    node->right = subtree;

    node->height = max(height(node->left), height(node->right)) + 1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;

    return rightChild;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* avlinsert(Node* root, int key) {
    if (root == nullptr)
        return newNode(key);

    if (key < root->key)
        root->left = avlinsert(root->left, key);
    else if (key > root->key)
        root->right = avlinsert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void avlinorderTraversal(Node* node) {
    if (node != nullptr) {
        avlinorderTraversal(node->left);
        cout << node->key << " ";
        avlinorderTraversal(node->right);
    }
}

void bfsAVLTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
        Node* node = queue.front();
        queue.pop();
        cout << node->key << " ";

        if (node->left) {
            queue.push(node->left);
        }
        if (node->right) {
            queue.push(node->right);
        }
    }
}

#endif
