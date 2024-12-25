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

    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

int getBalance(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* avlInsert(Node* node, int key) {
    if (node == nullptr) return new Node(key);

    if (key < node->key) node->left = avlInsert(node->left, key);
    else if (key > node->key) node->right = avlInsert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* avlDelete(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key) {
        root->left = avlDelete(root->left, key);
    }
    else if (key > root->key) {
        root->right = avlDelete(root->right, key);
    }
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = avlDelete(root->right, temp->key);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);

    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void avlInorder(Node* root) {
    if (root != nullptr) {
        avlInorder(root->left);
        //cout << root->key << " ";
        avlInorder(root->right);
    }
}

void bfsAVL(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
       // cout << current->key << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

#endif
