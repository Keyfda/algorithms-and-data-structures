#include "BSTree.h"
#include "RBTree.h"
#include "AVLTree.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

void preorderTraversal(TreeNode* root) 
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void AVLpreorderTraversal(Node* root) 
{
    if (root == nullptr)
        return;
    cout << root->key << " ";
    AVLpreorderTraversal(root->left);
    AVLpreorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) 
{
    if (root == nullptr)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void AVLpostorderTraversal(Node* root) 
{
    if (root == nullptr)
        return;
    AVLpostorderTraversal(root->left);
    AVLpostorderTraversal(root->right);
    cout << root->key << " ";
}

int main() 
{
    TreeNode* root = nullptr;
    RedBlackTree tree;
    Node* root3 = nullptr;


    cout << "Check trees\n\n";
    const int N = 9999;
    int k[N + 1];

    for (int i = 0; i < 50; i++)
    {
        k[i] = rand();
        root = insert(root, k[i]);
    }
   
   int heightbs = height(root);
 
   cout << "Inorder: \n\n";
 
   cout << "BINARY TREE : \n";
    inorderTraversal(root);
    cout << endl;
    for (int i = 0; i < 50; i++)
    {
        root3 = avlinsert(root3, k[i]);
    }
    int heightavl = root3->height;
    
    cout << "AVL TREE:  \n";
   
    avlinorderTraversal(root3);
    cout << endl;

    for (int i = 0; i < 50; i++)
    {
        tree.RBinsert(k[i]);
    }
   
   
    cout << "RED BLACK TREE:  \n";

   auto start = chrono::high_resolution_clock::now();
    tree.inorder();
    cout << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << ", " << fixed << duration.count();

    cout << "RED BLACK TREE:  \n";

    start = chrono::high_resolution_clock::now();
    tree.preorder();
     end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << ", " << fixed << duration.count();


    start = chrono::high_resolution_clock::now();
    preorderTraversal(root);
    cout << endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << ", " << fixed << duration.count();

    start = chrono::high_resolution_clock::now();
    AVLpreorderTraversal(root3);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << ", " << fixed << duration.count();

    
    start = chrono::high_resolution_clock::now();
    tree.postorder();
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << ", " << fixed << duration.count();

    start = chrono::high_resolution_clock::now();
    postorderTraversal(root);
    cout << endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << ", " << fixed << duration.count();

    start = chrono::high_resolution_clock::now();
    AVLpostorderTraversal(root3);
    cout << endl;
    end = chrono::high_resolution_clock::now();
   duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << ", " << fixed << duration.count();

    start = chrono::high_resolution_clock::now();
    levelOrder(root);
    cout << endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << ", " << fixed << duration.count();


    start = chrono::high_resolution_clock::now();
    tree.levelOrder();
    cout << endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout.precision(10);
    cout << ", " << fixed << duration.count();

    bfsAVLTree(root3);
}

