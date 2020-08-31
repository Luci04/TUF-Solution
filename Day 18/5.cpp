
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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left && right)
        return root;
    return left != NULL ? left : right;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << LCA(root, 4, 5)->data << "\n";
    cout << "LCA(4, 6) = " << LCA(root, 4, 6)->data << "\n";
    cout << "LCA(3, 4) = " << LCA(root, 3, 4)->data << "\n";
    cout << "LCA(2, 4) = " << LCA(root, 2, 4)->data << "\n";

    return 0;
}