
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->right), height(root->left));
}

bool isBalanced(Node *root)
{
    int lh, rh;
    if (root == NULL)
        return true;
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->right) && isBalanced(root->left))
        return 1;
    return 0;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if (isBalanced(root))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");

    return 0;
}