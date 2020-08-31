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
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void Post(Node *root)
{
    if (root)
    {
        Post(root->left);
        Post(root->right);
        cout << root->data << " ";
    }
}

void Post1(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    Node *curr;

    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);

        if (curr->right)
            s1.push(curr->right);
    }

    while (!s2.empty())
    {
        curr = s2.top();
        s2.pop();
        cout << curr->data << " ";
    }
}

int main()
{

    struct Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    Post(root);
    cout << "\n";
    Post1(root);

    return 0;
}