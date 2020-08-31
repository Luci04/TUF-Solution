#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return (newNode);
}

bool isSym(Node *a, Node *b)
{
    if (a == NULL && b == NULL)
        return true;

    if (a && b && a->data == b->data)
    {
        return isSym(a->left, b->right) && isSym(a->right, b->left);
    }

    return false;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    cout << isSym(root, root);
    return 0;
}