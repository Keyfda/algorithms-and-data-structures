#ifndef BSTreeHeader
#define BSTreeHeader

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
      //  cout << root->data << " ";
        inorder(root->right);
    }
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void printLevel(TreeNode* root, int level) {
    if (root == nullptr) return;
    if (level == 1) cout << root->data << " ";
    else if (level > 1) {
       // printLevel(root->left, level - 1);
       // printLevel(root->right, level - 1);
    }
}

void levelOrder(TreeNode* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, int val) {
    if (root == nullptr) return root;

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    }
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

#endif
