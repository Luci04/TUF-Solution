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
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

bool solve(Node *root, int mini, int maxi)
{
    if (root == NULL)
        return true;

    if (root->data < mini || root->data > maxi)
        return false;

    return solve(root->left, mini, root->data) && solve(root->right, root->data, maxi);
}

bool isBst(Node *root)
{
    return solve(root, INT_MIN, INT_MAX);
}

int main()
{

    Node *root = newNode(10);
    root->left = newNode(9);
    root->left->left = newNode(6);
    root->right = newNode(11);

    cout << isBst(root) << "\n";

    return 0;
}