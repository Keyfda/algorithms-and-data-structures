#ifndef RBTreeHeader
#define RBTreeHeader

#include <iostream>
#include <queue>

using namespace std;

enum Color { RED, BLACK };

class RBNode {
public:
    int data;
    bool color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
private:
    RBNode* root;

    void rotateLeft(RBNode*& node);
    void rotateRight(RBNode*& node);
    void fixViolation(RBNode*& node);
    void fixDeletion(RBNode*& node, RBNode* root, RBNode* parent);
    void deleteNode(RBNode*& root, RBNode* node);
    RBNode* minimum(RBNode* node);

public:
    RBTree() : root(nullptr) {}

    void rbInsert(int data);
    void rbDelete(int data);
    void inorder();
    void preorder();
    void postorder();
    void levelOrder();
    int getHeight();

private:
    void inorderHelper(RBNode* root);
    void preorderHelper(RBNode* root);
    void postorderHelper(RBNode* root);
    int getHeightHelper(RBNode* node);
};

void RBTree::rotateLeft(RBNode*& node) {
    RBNode* rightChild = node->right;
    node->right = rightChild->left;
    if (node->right != nullptr) node->right->parent = node;
    rightChild->parent = node->parent;
    if (node->parent == nullptr) root = rightChild;
    else if (node == node->parent->left) node->parent->left = rightChild;
    else node->parent->right = rightChild;
    rightChild->left = node;
    node->parent = rightChild;
}

void RBTree::rotateRight(RBNode*& node) {
    RBNode* leftChild = node->left;
    node->left = leftChild->right;
    if (node->left != nullptr) node->left->parent = node;
    leftChild->parent = node->parent;
    if (node->parent == nullptr) root = leftChild;
    else if (node == node->parent->left) node->parent->left = leftChild;
    else node->parent->right = leftChild;
    leftChild->right = node;
    node->parent = leftChild;
}

void RBTree::rbInsert(int data) {
    RBNode* newNode = new RBNode(data);
    RBNode* parent = nullptr;
    RBNode* current = root;

    while (current != nullptr) {
        parent = current;
        if (newNode->data < current->data) current = current->left;
        else current = current->right;
    }

    newNode->parent = parent;
    if (parent == nullptr) root = newNode;
    else if (newNode->data < parent->data) parent->left = newNode;
    else parent->right = newNode;

    fixViolation(newNode);
}

void RBTree::fixViolation(RBNode*& node) {
    while (node != root && node->color == RED && node->parent->color == RED) {
        RBNode* parent = node->parent;
        RBNode* grandParent = parent->parent;
        if (parent == grandParent->left) {
            RBNode* uncle = grandParent->right;
            if (uncle && uncle->color == RED) {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandParent;
            }
            else {
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateRight(grandParent);
                swap(parent->color, grandParent->color);
                node = parent;
            }
        }
        else {
            RBNode* uncle = grandParent->left;
            if (uncle && uncle->color == RED) {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandParent;
            }
            else {
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateLeft(grandParent);
                swap(parent->color, grandParent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

void RBTree::inorder() {
   // cout << "Inorder: ";
    inorderHelper(root);
    cout << endl;
}

void RBTree::preorder() {
    preorderHelper(root);
    cout << endl;
}

void RBTree::postorder() {
    postorderHelper(root);
    cout << endl;
}

void RBTree::levelOrder() {
    if (root == nullptr) return;
    queue<RBNode*> q;
    q.push(root);

    while (!q.empty()) {
        RBNode* current = q.front();
        q.pop();
       // cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

void RBTree::inorderHelper(RBNode* root) {
    if (root != nullptr) {
        inorderHelper(root->left);
       // cout << root->data << " ";
        inorderHelper(root->right);
    }
}

void RBTree::preorderHelper(RBNode* root) {
    if (root != nullptr) {
      //  cout << root->data << " ";
        preorderHelper(root->left);
        preorderHelper(root->right);
    }
}

void RBTree::postorderHelper(RBNode* root) {
    if (root != nullptr) {
        postorderHelper(root->left);
        postorderHelper(root->right);
     //   cout << root->data << " ";
    }
}

int RBTree::getHeight() {
    return getHeightHelper(root);
}

int RBTree::getHeightHelper(RBNode* node) {
    if (node == nullptr) return 0;
    int leftHeight = getHeightHelper(node->left);
    int rightHeight = getHeightHelper(node->right);
    return max(leftHeight, rightHeight) + 1;
}


RBNode* RBTree::minimum(RBNode* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}


void RBTree::deleteNode(RBNode*& root, RBNode* node) {
    RBNode* child;
    RBNode* parent;
    bool color;

    if (node->left != nullptr && node->right != nullptr) {
        RBNode* replace = node->right;
        while (replace->left != nullptr) {
            replace = replace->left;
        }

        if (node->parent != nullptr) {
            if (node->parent->left == node)
                node->parent->left = replace;
            else
                node->parent->right = replace;
        }
        else {
            root = replace;
        }

        child = replace->right;
        parent = replace->parent;
        color = replace->color;

        if (parent == node) {
            parent = replace;
        }
        else {
            if (child != nullptr) {
                child->parent = parent;
            }
            parent->left = child;

            replace->right = node->right;
            node->right->parent = replace;
        }

        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;

        if (color == BLACK) {
            fixDeletion(root, child, parent);
        }

        delete node;
        return;
    }

    if (node->left != nullptr) {
        child = node->left;
    }
    else {
        child = node->right;
    }

    parent = node->parent;
    color = node->color;

    if (child != nullptr) {
        child->parent = parent;
    }

    if (parent != nullptr) {
        if (node == parent->left) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }
    }
    else {
        root = child;
    }

    if (color == BLACK) {
        fixDeletion(root, child, parent);
    }

    delete node;
}

void RBTree::fixDeletion(RBNode*& root, RBNode* node, RBNode* parent) {
    RBNode* sibling;

    while ((node == nullptr || node->color == BLACK) && node != root) {
        if (node == parent->left) {
            sibling = parent->right;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                rotateLeft(parent);
                sibling = parent->right;
            }

            if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                (sibling->right == nullptr || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = parent;
                parent = node->parent;
            }
            else {
                if (sibling->right == nullptr || sibling->right->color == BLACK) {
                    if (sibling->left != nullptr) {
                        sibling->left->color = BLACK;
                    }
                    sibling->color = RED;
                    rotateRight(sibling);
                    sibling = parent->right;
                }

                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->right != nullptr) {
                    sibling->right->color = BLACK;
                }
                rotateLeft(parent);
                node = root;
            }
        }
        else {
            sibling = parent->left;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                rotateRight(parent);
                sibling = parent->left;
            }

            if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                (sibling->right == nullptr || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = parent;
                parent = node->parent;
            }
            else {
                if (sibling->left == nullptr || sibling->left->color == BLACK) {
                    if (sibling->right != nullptr) {
                        sibling->right->color = BLACK;
                    }
                    sibling->color = RED;
                    rotateLeft(sibling);
                    sibling = parent->left;
                }

                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->left != nullptr) {
                    sibling->left->color = BLACK;
                }
                rotateRight(parent);
                node = root;
            }
        }
    }

    if (node != nullptr) {
        node->color = BLACK;
    }
}

void RBTree::rbDelete(int data) {
    RBNode* node = root;
    while (node != nullptr) {
        if (node->data == data) {
            deleteNode(root, node);
            return;
        }
        else if (data < node->data) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
}

#endif
