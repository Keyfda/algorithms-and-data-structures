#ifndef RedBackTreeHeader
#define RedBackTreeHeader

#include <iostream>
#include <queue>

using namespace std;

enum Color { RED, BLACK };

class RBTree {
public:
    int data;
    bool color;
    RBTree* left, * right, * parent;

    RBTree(int);
};

class RedBlackTree {
private:
    RBTree* root;
protected:
    void rotateLeft(RBTree*&);
    void rotateRight(RBTree*&);
    void fixViolation(RBTree*&);
public:
    RedBlackTree();
    void RBinsert(const int& n);
    void inorder();
    void inorderHelper(RBTree* root);
    void preorder();
    void preorderHelper(RBTree* root);
    void postorder();
    void postorderHelper(RBTree* root);
    void levelOrder();
};

RBTree::RBTree(int data) {
    this->data = data;
    left = right = parent = nullptr;
    color = RED;
}

RedBlackTree::RedBlackTree() {
    root = nullptr;
}

int height(RBTree* node) {
    if (node == nullptr)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

void RedBlackTree::rotateLeft(RBTree*& ptr) {
    RBTree* rightChild = ptr->right;
    ptr->right = rightChild->left;
    if (ptr->right != nullptr)
        ptr->right->parent = ptr;
    rightChild->parent = ptr->parent;
    if (ptr->parent == nullptr)
        root = rightChild;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = rightChild;
    else
        ptr->parent->right = rightChild;
    rightChild->left = ptr;
    ptr->parent = rightChild;
}

void RedBlackTree::rotateRight(RBTree*& ptr) {
    RBTree* leftChild = ptr->left;
    ptr->left = leftChild->right;
    if (ptr->left != nullptr)
        ptr->left->parent = ptr;
    leftChild->parent = ptr->parent;
    if (ptr->parent == nullptr)
        root = leftChild;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = leftChild;
    else
        ptr->parent->right = leftChild;
    leftChild->right = ptr;
    ptr->parent = leftChild;
}

void RedBlackTree::RBinsert(const int& n) {
    RBTree* newNode = new RBTree(n);
    RBTree* parent = nullptr;
    RBTree* current = root;

    while (current != nullptr) {
        parent = current;
        if (newNode->data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;

    if (parent == nullptr)
        root = newNode;
    else if (newNode->data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    fixViolation(newNode);
}

void RedBlackTree::fixViolation(RBTree*& ptr) {
    RBTree* parent = nullptr;
    RBTree* grandParent = nullptr;

    while ((ptr != root) && (ptr->color != BLACK) && (ptr->parent->color == RED)) {
        parent = ptr->parent;
        grandParent = ptr->parent->parent;

        if (parent == grandParent->left) {
            RBTree* uncle = grandParent->right;

            if (uncle != nullptr && uncle->color == RED) {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                ptr = grandParent;
            }
            else {
                if (ptr == parent->right) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandParent);
                swap(parent->color, grandParent->color);
                ptr = parent;
            }
        }
        else {
            RBTree* uncle = grandParent->left;

            if (uncle != nullptr && uncle->color == RED) {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                ptr = grandParent;
            }
            else {
                if (ptr == parent->left) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandParent);
                swap(parent->color, grandParent->color);
                ptr = parent;
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::inorder() {
    cout << "Inorder traversal: " << endl;
    inorderHelper(root);
    cout << endl;
}

void RedBlackTree::inorderHelper(RBTree* root) {
    if (root == nullptr)
        return;
    inorderHelper(root->left);
    cout << root->data << " ";
    inorderHelper(root->right);
}

void RedBlackTree::levelOrder() {
    cout << "Level order traversal: " << endl;
    if (root == nullptr)
        return;
    queue<RBTree*> q;
    q.push(root);
    while (!q.empty()) {
        RBTree* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

void RedBlackTree::preorder() {
    cout << "Preorder traversal: " << endl;
    preorderHelper(root);
    cout << endl;
}

void RedBlackTree::preorderHelper(RBTree* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderHelper(root->left);
    preorderHelper(root->right);
}

void RedBlackTree::postorder() {
    cout << "Postorder traversal: " << endl;
    postorderHelper(root);
    cout << endl;
}

void RedBlackTree::postorderHelper(RBTree* root) {
    if (root == nullptr)
        return;
    postorderHelper(root->left);
    postorderHelper(root->right);
    cout << root->data << " ";
}

#endif
