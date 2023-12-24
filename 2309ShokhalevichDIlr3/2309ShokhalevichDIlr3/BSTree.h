#ifndef BSTreeHeader
#define BSTreeHeader

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    else {
        if (val < root->data) {
            root->left = insert(root->left, val);
        }
        else {
            root->right = insert(root->right, val);
        }
        return root;
    }
}

bool BinSearch(TreeNode* root, int val) {
    if (root == nullptr) {
        return false;
    }
    else if (root->data == val) {
        return true;
    }
    else if (val < root->data) {
        return BinSearch(root->left, val);
    }
    else {
        return BinSearch(root->right, val);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int height(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
   
    return max(leftHeight, rightHeight) + 1;
}

void printGivenLevel(TreeNode* root, int level) {
    if (root == nullptr)
        return;
    if (level == 1) {
        std::cout << root->data << " ";
    }
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void levelOrder(TreeNode* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}

#endif
