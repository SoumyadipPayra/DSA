#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} *tptr;

void Print(tptr root)
{
    if (!root)
        return;
    Print(root->left);
    cout << root->val << " ";
    Print(root->right);
}

void PrintDLL(tptr root)
{
    tptr curr = root;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}

void FlattenToDLLInorder(tptr &root, tptr &prev, TreeNode *head)
{
    if (!root)
        return;
    FlattenToDLLInorder(root->left, prev, head);
    if (!head)
        head = root;
    root->left = prev;
    tptr temp = root->right;
    root->right = NULL;
    if (prev)
        prev->right = root;
    prev = root;
    FlattenToDLLInorder(temp, prev, head);
}

void FlattenToDLLPreOrder(tptr &root, tptr &prev, tptr &head)
{
    if (!root)
        return;
    if (!head)
        head = root;
    tptr tempLeft = root->left;
    tptr tempRight = root->right;

    root->left = prev;
    if (prev)
        prev->right = root;
    prev = root;

    FlattenToDLLPreOrder(tempLeft, prev, head);
    FlattenToDLLPreOrder(tempRight, prev, head);
}

void FlattenToDLLPostOrder(tptr &root, tptr &prev, tptr &head, tptr head1)
{
    if (!root)
        return;

    FlattenToDLLPostOrder(root->left, prev, head, head1);
    FlattenToDLLPostOrder(root->right, prev, head, head1);

    if (head != head1)
        cout << root->val << endl;
    if (!head)
        head = root;

    root->left = prev;
    root->right = NULL;
    if (prev)
        prev->right = root;

    prev = root;
}

int main()
{
    tptr root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    Print(root);
    cout << endl;

    tptr prev = NULL;
    tptr head = NULL;
    // FlattenToDLLInorder(root, prev, head);
    // PrintDLL(head);

    // FlattenToDLLPreOrder(root, prev, head);
    // PrintDLL(head);

    FlattenToDLLPostOrder(root, prev, head, head);
    PrintDLL(head);
}