#include "BSTree.h"
#include "RBTree.h"
#include "AVLTree.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <functional>

using namespace std;
using namespace chrono;

void measureExecTime(const function<void()>& func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start);
    cout.precision(10);
    cout << fixed << duration.count() << " " ;
}

void preorder(TreeNode* root) {
    if (root == nullptr) return;
   // cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void AVLpreorder(Node* root) {
    if (root == nullptr) return;
  //  cout << root->key << " ";
    AVLpreorder(root->left);
    AVLpreorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
  //  cout << root->data << " ";
}

void AVLpostorder(Node* root) {
    if (root == nullptr) return;
    AVLpostorder(root->left);
    AVLpostorder(root->right);
   // cout << root->key << " ";
}

int main() {
    TreeNode* bsRoot = nullptr;
    RBTree rbTree;
    Node* avlRoot = nullptr;

    cout << "Check trees\n\n";
    const int N = 9999;
    int k[N + 1];

    /*for (int i = 0; i < 100; i++) {
        
    }*/

    int heightBs = height(bsRoot);

  //  cout << "Inorder: \n\n";

   // cout << "BS TREE : \n";
    
  //  cout << endl;

    for (int i = 0; i < 100; i++) {
        k[i] = rand();
        bsRoot = insert(bsRoot, k[i]);
        avlRoot = avlInsert(avlRoot, k[i]);
        rbTree.rbInsert(k[i]);
    }

   // measureExecTime([&]() {  bsRoot = insert(bsRoot, 2); });
    measureExecTime([&]() {  avlRoot = avlInsert(avlRoot, 2); });
    measureExecTime([&]() {  rbTree.rbInsert(2); });
    int heightAvl = avlRoot->height;

    inorder(bsRoot);
   // cout << "AVL TREE:  \n";
    avlInorder(avlRoot);
    cout << endl;

    /*for (int i = 0; i < 100; i++) {
        
    }*/

    cout << "RB TREE Inorder Traversal: ";
   // measureExecTime([&]() { rbTree.inorder(); });

    cout << "RB TREE Preorder Traversal: ";
   // measureExecTime([&]() { rbTree.preorder(); });

    cout << "BS TREE Preorder Traversal: ";
   // measureExecTime([&]() { preorder(bsRoot); });

    cout << "AVL TREE Preorder Traversal: ";
   // measureExecTime([&]() { AVLpreorder(avlRoot); });

    cout << "RB TREE Postorder Traversal: ";
  //  measureExecTime([&]() { rbTree.postorder(); });

    cout << "BS TREE Postorder Traversal: ";
   // measureExecTime([&]() { postorder(bsRoot); });

    cout << "AVL TREE Postorder Traversal: ";
   // measureExecTime([&]() { AVLpostorder(avlRoot); });

    cout << "BS TREE Level Order Traversal: ";
  //  measureExecTime([&]() { levelOrder(bsRoot); });

    cout << "RB TREE Level Order Traversal: ";
   // measureExecTime([&]() { rbTree.levelOrder(); });

    cout << "AVL TREE Level Order Traversal: ";
  //  measureExecTime([&]() { bfsAVL(avlRoot); });

    /* for (int i = 0; i < 5; i++) {
            bsRoot = deleteNode(bsRoot, k[i]);
        }*/
    bsRoot = deleteNode(bsRoot, k[2]);
   // cout << "After Deletion in BS TREE (Inorder): ";
   // measureExecTime([&]() { inorder(bsRoot); });

    /* for (int i = 0; i < 5; i++) {
         avlRoot = avlDelete(avlRoot, k[i]);
     }*/
     avlRoot = avlDelete(avlRoot, k[4]);
  //  cout << "After Deletion in AVL TREE (Inorder): ";
    measureExecTime([&]() { avlInorder(avlRoot); });

   /* for (int i = 0; i < 100; i++) {
        rbTree.rbDelete(k[i]);
    }*/
    rbTree.rbDelete(k[4]);
   // cout << "After Deletion in RB TREE (Inorder): ";
    measureExecTime([&]() { rbTree.inorder(); });

    int heightBsAfterDelete = height(bsRoot);
    cout << "Height of BS TREE after deletion: " << heightBsAfterDelete << endl;

    int heightAvlAfterDelete = height(avlRoot);
    cout << "Height of AVL TREE after deletion: " << heightAvlAfterDelete << endl;

    int heightRbAfterDelete = rbTree.getHeight();
    cout << "Height of RB TREE after deletion: " << heightRbAfterDelete << endl;

    return 0;
}
