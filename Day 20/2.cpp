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

bool isPresent(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return isPresent(root->left, key);
    }
    else
    {
        return isPresent(root->right, key);
    }
}

int main()
{

    Node *root = newNode(10);
    root->left = newNode(9);
    root->left->left = newNode(6);
    root->right = newNode(11);

    cout << isPresent(root, 6) << "\n";

    return 0;
}