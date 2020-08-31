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

int height(struct Node *node)
{
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

int diameter(Node *root)
{
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(l + r + 1, max(ld, rd));
}

int diameter2(Node *root, int *height)
{
    int lh = 0, rh = 0;

    int ld = 0, rd = 0;

    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    ld = diameter2(root->left, &lh);
    rd = diameter2(root->right, &rh);

    *height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ld, rd));
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int height = 0;
    cout << diameter(root) << "\n";
    cout << diameter2(root, &height) << "\n";
    return 0;
}